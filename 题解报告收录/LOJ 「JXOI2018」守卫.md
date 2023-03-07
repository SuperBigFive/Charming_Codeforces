## LOJ [「JXOI2018」守卫](https://loj.ac/p/2545)

### 题目描述

一座山可以描述为一条折线，折线的下方是岩石。 折线上有 $n$ 个点，第 $i$ 个点的坐标为 $(i,h_i)$。

考虑在一些点放置监视器，使得每个点都能被观测到。

一个点能被某个监视器观测，当且仅当该点的横坐标小于监视器的横坐标，且两点之间的连线不经过岩石与折线上其他点。

对于每个 $1 \leq l \leq r \leq n$，分别求出只考虑区间 $[l, r]$ 时满足每个点能被观测到的最小监视器数量。

输出这些答案的异或和。

### 数据范围

$n \leq 5 \times 10^{3},1 \leq h_i \leq 10^9$。

------

### 题解报告

区间 $dp$。一般来说区间 $dp$ 题目的套路就是区间长度从 $1$ 递增到 $n$，

依次求出区间长度为 $1，2...n$ 时所有 $dp$ 值，大的区间从小的区间转移。

这道题有些不同。

考虑到对于每个区间 $[l, r]$，首先第 $r$ 个位置一定会被观测到，所以这里一定放上一个守卫。

放上守卫后，区间 $[l, r]$ 一定被分成一些连续可以被 $r$ 观测到的和不可以被 $r$ 观测到的区间。

对于不可以被 $r$ 观测到的区间 $[l_i, r_i]$，它们之间是相互独立的。

即在区间 $[l_i, r_i]$ 放上监视器，不会使 $[l_j, r_j]$ 被观测到。

~~（有点猜结论的感觉，可以自己在纸上试试）~~

所以 $dp[i][j] = 1 + $使所有未被 $r$ 观测到的连续区间被观测到所需放置的监视器之和。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e3 + 5;

int n;
int h[maxn];
int see[maxn][maxn];
int dp[maxn][maxn];

void init () {
	for (int i = 1; i < maxn; ++i)
	for (int j = i; j < maxn; ++j)
	dp[i][j] = 0;
}

void get_see () {
	for (int i = 1, id; i < n; ++i) {
		see[i][i] = see[i][i + 1] = 1;
		id = i + 1;
		for (int j = i + 2; j <= n; ++j) {
			if ((h[j] - h[i]) * (id - i) > (h[id] - h[i]) * (j - i)) {
				see[i][j] = 1;
				id = j;
			}
		}
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	get_see ();
	for (int i = 1, id, last, sum; i <= n; ++i) {
		id = i;
		last = sum = 0;
		dp[i][i] = 1;
		for (int j = i - 1; j >= 1; --j) {
			if (see[j][i]) {
				sum += last;
				id = j;
			}
			last = min (dp[j][id], dp[j][id - 1]);
			dp[j][i] = sum + last + 1;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = i; j <= n; ++j)
	res ^= dp[i][j];
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}
```

-----

### 收获&总结

$dp$ 好难，太考验思维了。最近太摆了，一个月没怎么更新题单，希望以后每天都能腾出时间练几题。$emo$。