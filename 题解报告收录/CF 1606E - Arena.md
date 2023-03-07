## [CF 1606E Arena](https://codeforces.com/contest/1606/problem/E) 

### 题目描述

$n$ 个人参加游戏，每个人都有不超过 $x$ 的生命值，每轮每人可对其他所有玩家造成 $1$ 的伤害。

给定 $n$ 和 $x$，问有多少种生命值的给定方案，使得最终无人存活（即在最后一轮中所有玩家生命值低于$1$）。模数 $998244353$。

若用$[x_1,x_2...x_n]$ 表示每个人的生命值，则 $[1, 2, 3]$ 和 $[2, 1, 3]$ 是两种不同的方案。

### 数据范围

$2 \leq n \leq 500,1 \leq x \leq 500$。

------

### 题解报告

每轮游戏每个人的生命值会减少“当前人数减 $1$ ”，

若某玩家生命值低于该值，则本轮游戏后该名玩家死亡。

假如 $x$ 小于 $n$ 的话，无论如何安排，所有人都会在第一轮死亡，

答案就是 $x^n$。

假如 $x$ 大于等于 $y$，我们枚举本轮游戏过后多少人死亡，

设 $k$ 个人死亡的话，则有 $\sum _{k = 0}^{n - 2} · (^n_k) · (n - 1)^k$ 种情况

（ $n$ 个人中选 $k$ 个死亡，死亡人数的生命值可以是 $[1, n - 1]$）。

可以发现，在 $k$ 个人死亡的前提下，游戏等价为

$n - k$ 个玩家，生命上限为 $x - (n - 1)$。

这是一个递归求解的过程。

用数组 $dp[i][j]$ 表示人数为 $i$，生命上限为 $x$ 时的方案数。

利用记忆化搜索避免多次访问同一种状态。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
const int maxn = 5e2 + 5;
const int mod = 998244353;

int n, x;
int dp[maxn][maxn];
int POW[maxn][maxn], C[maxn][maxn];

void init () {
	for (int i = 0; i < maxn; ++i)
	std :: fill (dp[i], dp[i] + maxn, -1);
}

void get_pow () {
	for (int i = 1; i < maxn; ++i) {
		POW[i][0] = 1;
		for (int j = 1; j < maxn; ++j) {
			POW[i][j] = (POW[i][j - 1] * i) % mod; 
		}
	}
}
	
void get_c () {
	C[0][0] = 1;
	for (int i = 1; i < maxn; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
}

int dfs (int n, int x) {
	if (dp[n][x] != -1) return dp[n][x];
	if (x < n) return dp[n][x] = POW[x][n];
	if (n == 2) return dp[n][x] = x;
	dp[n][x] = POW[n - 1][n];
	for (int i = 0; i <= n - 2; ++i) {
		dp[n][x] = (dp[n][x] + 
		((dfs (n - i, x - (n - 1)) * C[n][i]) % mod)
		 * POW[n - 1][i]) % mod;
	}
	return dp[n][x];
}

void charming () {
	init ();
	int n, x;
	std :: cin >> n >> x;
	std :: cout << dfs (n, x) << std :: endl;
}

signed main () {
	get_pow (), get_c ();
	charming ();
	return 0;
}
```

-----

### 收获&总结

第一次正式地写记忆化搜索。现在想起来其实已经见过很多次记忆化搜索了，但一直不知道叫啥名字。

感觉记忆化搜索挺好用的，也是个挺常见的技巧（我竟然现在才学到？），

关键是要想到递归的过程（把一个大问题转化成若干子问题），

如果构建的递归过程用到的状态数不多的话就可以利用记忆化搜索来优化搜索过程。

作为零基础开始自学 $ACM$ 的菜鸡，相比于周围 $OI$ 生，感觉自己基础很薄弱...就算学了不少算法，

但经常因为思维能力不够、基础题写挂导致根本开不到用到算法的题目。现在只能不断刷题了，反正算

法、技巧见一个少一个。