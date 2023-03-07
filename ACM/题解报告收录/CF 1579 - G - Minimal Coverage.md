## [CF 1579 - G - Minimal Coverage](https://codeforces.com/contest/1579/problem/G) 

### 题目描述

坐标轴上从 $0$ 开始，每次可以选择向左或向右跳 $a[i]$ 步，令 $l，r$ 分别表示 $n$ 步之间最左边界和最右边界，问 $r - l + 1$ 的最小值。

### 数据范围

$ 1 \leq n \leq 10^4, 1 \leq a[i] \leq 1000$。

-----

### 题解报告

$[l, r]$ 表示一个连续的区间，不难发现该区间的最大值一定不超过 $2001$，即 $max (a) + 1$。

于是首先想到了记忆化搜索，开个 $vis[N][M]$ 数组，$vis[i][j]$ 表示考虑前 $i$ 步时，位于数轴上 $j$ 点时的最优值。

然后发现这么做不对，还应该考虑左边界和有边界，这样 $vis$ 数组就得开四维的，时间和空间复杂度都得爆炸。

进行个简单的优化，可以开个三维数组 $dp[N][M][M]$，$dp[i][j][k]$ 表示考虑前 $i$ 步时，左边界为 $j$ 时，位于数轴上 $k$ 点的最小右边界，这样就变成了三维的了，但是时间和空间复杂度还是太大。

然后发现，第二维和第三维可以合并为一维。我们考虑前 $i$ 步的最优情况时，$dp[i][j][k]$，$dp[i][j + p][k + p]$，$dp[i][j + 2p][k + 2p]$... 这么多状态我们只要一个就行了，同时 $dp$ 数组的含义也要改改，取消了左边界的固定，自然也要取消右边界的固定。$dp[i][j]$ 表示考虑前 $i$ 步时，当前位置距离左边界为 $j$ 时，距离右边界的最小值。

这样的话，答案就是 $min (dp[n][i] + i)$，转移方程如下：

若选则向左跳，则 $dp[i + 1][max (0, j - a[i])] = min (dp[i + 1][max (0, j - a[i])], dp[i][j] + a[i])$；

若选择向右跳，则 $dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], max(0, dp[i][j] - a[i]))$。

三维数组能压缩成二维的，本质上是因为，统计答案时用不到第三维。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e4 + 5;
const int M = 2e3 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	for (auto &it : a) cin >> it;
	vector <vector <int> > dp (n + 1, vector <int> (M, INT_MAX));
	int res = INT_MAX;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dp[i][j] >= INT_MAX) continue;
			dp[i + 1][max (0ll, j - a[i])] = min (dp[i][j] + a[i],
			dp[i + 1][max (0ll, j - a[i])]);
			if (j + a[i] < M) {
				dp[i + 1][j + a[i]] = min (dp[i + 1][j + a[i]],
				max (dp[i][j] - a[i], 0ll));
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		res = min (res, i + dp[n][i]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
```

-----

### 收获&总结

记忆化搜索就像一种暴力，本题的优化过程类似一种剪枝。感觉 $dp$ 本质上就是一种对搜索的剪枝。