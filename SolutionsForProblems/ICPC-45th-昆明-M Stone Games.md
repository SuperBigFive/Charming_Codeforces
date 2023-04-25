## [ICPC-45th-昆明-M Stone Games](https://ac.nowcoder.com/acm/contest/12548/M)

### 题目描述

给定 $n$ 个数， $m$ 次询问，每次询问下标区间 $[l_{i}, r_{i}]$ 内最小的不能被表示的数。

一个数能被表示的意思是，在询问区间内能够选择一些数（一个下标只能选一次），使得这些数的和等于该数字。

强制在线。

### 数据范围

$ 1 \leq n \leq 10^{6} ，1 \leq m \leq 10 ^ {5}$，每个数字的大小范围是 $[1, 10^{9}]$。

-----

### 题解报告

对于每次询问，假设区间内的数都是递增的，并且我们选中了区间内的前 $k$ 个数，

并求出了利用这 $k$ 个数我们能表示的数的范围 $[1, p]$。

考虑从未被选择的数中选择一部分，假设选择了一个数 $q$，如果 $q$ 的大小在 $[1, p + 1]$，

那么我们可被表示的数的范围就扩展成了 $[1, p + q]$。

而大于 $p + 1$ 的数，这些数被选取后，并不能扩展能表示的数的右端点。

我们计算区间内所有数字大小在 $[1, p + 1]$ 的数字的和 $sum$，

那么 $[1, sum]$ 就是新的能表示的数的范围。

扩展之后，未被选择的数中可能会出现新的能够使能表示的数的范围扩展的数。

不断重复该过程，直到没法在扩展位置，答案即为区间右端点 $ + 1$。

这些是在区间内的数递增的情况下考虑的，

利用主席树，依此插入第 $1, 2..n$ 个数，并保存历史版本。

这样的话，我们就能得到由任意区间内的数构成的权值线段树（可以理解成排好序了），

然后就能很方便的计算 $[1, p]$ 范围内所有数字的和。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;
const int mx = 1e9;

int n, m, tot;
int val[maxn], root[maxn];
ll sum[maxn << 5];
int ls[maxn << 5], rs[maxn << 5];

void init () {}

void update (int cnt) {sum[cnt] = sum[ls[cnt]] + sum[rs[cnt]];}

int modify (int pre, int l, int r, ll k) {
	int now = ++tot;
	sum[now] = sum[pre];
	if (l == r) {
		sum[now] += k;
		return now;
	}
	ls[now] = ls[pre], rs[now] = rs[pre];
	int mid = l + r >> 1;
	if (k <= mid) ls[now] = modify (ls[pre], l, mid, k);
	else rs[now] = modify (rs[pre], mid + 1, r, k);
	update (now);
	return now;
}

ll query (int rt1, int rt2, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return sum[rt2] - sum[rt1];
	int mid = l + r >> 1;
	ll res = 0;
	if (ql <= mid) res += query (ls[rt1], ls[rt2], l, mid, ql, qr);
	if (qr > mid) res += query (rs[rt1], rs[rt2], mid + 1, r, ql, qr);
	return res;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		root[i] = modify (root[i - 1], 1, mx, val[i]);
	}
	int l, r;
	ll ans = 0, s;
	for (int i = 1; i <= m; ++i) {
		cin >> l >> r;
		l = (l + ans) % n + 1, r = (r + ans) % n + 1;
		if (l > r) swap (l, r);
		ans = 0;
		while (true) {
			s = query (root[l - 1], root[r], 1, mx, 1, min (1ll * mx, ans + 1));
			if (s <= ans) break;
			ans = s;
		}
		cout << ++ans << endl;
	}
}

signed main () {
	charming ();
	return 0;
}
```

-----

### 收获&总结

做这道题之前一直有个思维定势，就是权值线段树只有离散后才能储存 $[1, 1e9]$的数的信息。

用了这么久的动态开点竟然一直没想到这个问题。现在想来也是，就算是 $[1, 1e9]$，最多一次插入也就增加 $log (1e9)$个节点，如果不卡的话还是爆不了内存的。

然后主席树的一个重要用途就是可以得到由任意区间的数构成的权值线段树。这道题确实加深了我对主席树的理解。