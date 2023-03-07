## HDU [2328-Corporate Identity](https://vjudge.net/problem/HDU-2328) 

### 题目描述

给 $n$ 个串，询问问最长相同字串。

### 数据范围

$1 ≤ n ≤ 4 \times 10^{3}$，每个串长度最大为 $100$。

------

### 题解报告

后缀数组套路题，先把 $n$ 个串拼起来，中间插入非英文字符以区分，

对后缀排序后，求出 $height[i]$ 数组，

二分最大长度，对于每次二分到的长度，

遍历 $height[i]$ 数组，连续的一段大于当前二分长度的 $height[i]$ 中，

若他们在每个串都出现过一次，

则证明一定存在一个长度为当前二分的值的字串是 $n$ 个串共有的。

关键在于如何判断在每个串出现过一次。

拼接过程中，给每个位置打上标记，表示当前位置的字符属于第几个串。

再开一个 $set$，把每段连续的满足 $height[i]$ 大于等于当前二分值的 $sa[i]$ 位置对应的标记塞进 $set$ 中，

若 $set$ 的大小等于 $n$ ，则代表在每个串都出现过了，返回 $true$。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int n, len, m, w, tot;
int bel[maxn];
int sa[maxn], rk[maxn], height[maxn];
int id[maxn], old_rk[maxn], cnt[maxn];
string s, t, res;
set <int> vis;

void init () {
	tot = 0;
	fill (cnt + 1, cnt + 1 + 300, 0);
	s.clear ();
	vis.clear ();
	res.clear ();
}

void key2_sort () {
	tot = 0;
	for (int i = len; i > len - w; --i) id[++tot] = i;
	for (int i = 1; i <= len; ++i) if (sa[i] > w) {
		id[++tot] = sa[i] - w;
	}
}

void key1_sort () {
	fill (cnt + 1, cnt + 1 + m, 0);
	for (int i = 1; i <= len; ++i) ++cnt[rk[id[i]]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = len; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
}

void update () {
	tot = 0;
	memcpy (old_rk, rk, sizeof rk);
	for (int i = 1; i <= len; ++i) {
		if (old_rk[sa[i]] == old_rk[sa[i - 1]]
		&& old_rk[sa[i] + w] == old_rk[sa[i - 1] + w])
		rk[sa[i]] = tot;
		else rk[sa[i]] = ++tot;
	}
}

void get_height () {
	for (int i = 1, k = 0; i <= len; ++i) {
		if (rk[i] == 1) continue;
		if (k) --k;
		while (s[sa[rk[i]] + k] == s[sa[rk[i] - 1] + k]) ++k;
		height[rk[i]] = k;
	}
}

bool check (int mid) {
	vis.clear ();
	for (int i = 2; i <= len; ++i) {
		if (height[i] < mid) vis.clear ();
		else {
			vis.insert (bel[sa[i]]);
			vis.insert (bel[sa[i - 1]]);
			if (vis.size () >= n) {
				res = s.substr (sa[i], mid);
				return true;
			}
		}
	}
	return false;
}

void charming () {
	init ();
	s += '#';
	int mn = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		len = t.size ();
		s += '#';
		for (int j = s.size (); j <= s.size () + len - 1; ++j)
		bel[j] = i;
		s += t;
		mn = min (mn, len);
	}
	m = 300, len = s.size () - 1;
	for (int i = 1; i <= len; ++i) ++cnt[rk[i] = s[i]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = len; i >= 1; --i) sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < len && tot < len; m = tot, w <<= 1) {
		key2_sort ();
		key1_sort ();
		update ();
	}
	
	get_height ();
	int l = 0, r = mn, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	if (ans && res != "#") cout << res << endl;
	else cout << "IDENTITY LOST" << endl;
}

signed main () {
	while (true) {
		cin >> n;
		if (!n) break;
		charming ();
	}
	return 0;
}
```

-----

### 收获&总结

理解了 $height[i]$ 数组含义，再练几道题之后，感觉这题就纯模板题了，典型二分 + $height[i]$ + $sa[i]$。