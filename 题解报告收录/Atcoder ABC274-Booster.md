## Atcoder [ABC274-Booster ](https://atcoder.jp/contests/abc274/tasks/abc274_e) 

### 题目描述

给定 $n$ 个点 $(x_i, y_i)$，要求从原点 $(0, 0)$ 开始经过所有点后返回原点。

另外有 $m$ 个不必要经过的点 $(p_i, q_i)$，但这些点一旦经过，你的速度就会加倍。

初始速度为 $1$，求最小花费时间。

### 数据范围

- $1≤N≤12$
- $0 \leq M \leq 5$
- $-10^9 \leq X_i,Y_i,P_i,Q_i \leq 10^9$
- $(0,0), (X_i,Y_i)$, and $(P_i,Q_i)$ 互不相同
- 所有输入均为整数

------

### 题解报告

不能暴力枚举所有点的经过顺序，$11!$ 已经是极限了。

考虑状压$DP$来优化搜索过程。

$dp[i][s]$ 表示 "$j$" 状态时位于 $i$ 的最小花费时间。

”$s$“ 状态是指，考虑 $s$ 的二进制形式，若第 $k$ 位数是 $1$，即代表已经访问过第 $k$ 个点。

"$s$"状态即为已经访问过的点的集合。

（这里为了方便，把所有没必要经过的点从 $n + 1$ 开始编号）

枚举所有 $s$ 的状态，对于每个状态，枚举每个已经访问的点和未访问的点，

已访问的点都可以转移到未访问到的点。

例如，设当前状态为 $s$，$i$ 为 $s$ 中一个已经访问到的点， $j$ 为一个未访问的点，

那么有 $dp[j][s] = min (dp[j][s], dp[i][s] + dis[i][j] * coef)$。

因为 $s$ 状态可能已经走过了一些没必要经过的点，速度增大了，相当于距离缩减了，

转移方程里的 $coef$ 即为这个缩减系数。

答案就从所有子集包含“$111...1$($n$个$1$，代表 $n$ 个必须要经过的点都已经经过)”的状态中找。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 20;
const int maxm = 2e6 + 5;

int n, m;
double x[maxn], y[maxn];
double dp[maxn][maxm];

void init () {
	for (int i = 0; i < maxn; ++i) 
	fill (dp[i], dp[i] + maxm, LLONG_MAX);
}

bool bit (int s, int i) {return (s >> i) & 1;}

void charming () {
	init ();
	scanf ("%lld%lld", &n, &m);
	for (int i = 0; i < n + m; ++i) {
		scanf ("%lf%lf", &x[i], &y[i]);
	}
	for (int i = 0; i < n + m; ++i) 
	dp[i][1 << i] = hypot (x[i], y[i]);
	for (int s = 1; s < (1 << n + m); ++s) {
		double coef = pow (0.5, __builtin_popcount (s >> n));
		for (int i = 0; i < n + m; ++i) if (bit (s, i)) {
			for (int j = 0; j < n + m; ++j) if (!bit (s, j)) {
				dp[j][s ^ (1 << j)] = fmin (dp[j][s ^ (1 << j)], 
				dp[i][s] + hypot (x[i] - x[j], y[i] - y[j]) * coef);
			}
		}
	}
	double res = LLONG_MAX;
	for (int i = 0; i < n + m; ++i) {
		for (int s = (1 << n) - 1; s < (1 << n + m); s += (1 << n)) {
			double coef = pow (0.5, __builtin_popcount (s >> n));
			res = fmin (res, dp[i][s] + hypot (x[i], y[i]) * coef);
		}
	}
	printf ("%.10lf\n", res);
}

signed main () {
	charming ();
	return 0;
}
```

-----

### 收获&总结

状压$DP$！暑假一轮集训的时候见过一次，当时就觉得挺神奇的，想不到在 $ABC$ 里又碰到了。

状态压缩，本质上是利用二进制各位 $0$ 或 $1$ 来储存状态的信息，一般适用数据量很小的题目。

（想到暴力 $dfs$，又看出了题目中的“状态”的概念，不妨试一下状压$dp$）

$Codeforces$ 的题更有趣些，但思维题太多了，算法题基本 $div2\ E$ 题开始才有；

$Atcoder$ 的题质量要更好一点，而且思维难度更大，$ABC \ D、E$ 题开始就涉及算法了。

（有时候 $C$ 题 $dfs$ 或 $bfs$ 这种比较基础的算法） 