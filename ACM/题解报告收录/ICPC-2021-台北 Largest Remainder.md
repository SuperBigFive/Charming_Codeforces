## ICPC-2021-台北 [Largest Remainder](https://codeforces.com/gym/408288/problem/D) 

### 题目描述

给定 $D$ 个大小为 $1$ ~ $9$ 的数字 $d$，用这些数字拼成一个数，要求该数模 $K$ 值最大。模数相同则输出拼成的数最大的一个。

### 数据范围

$1 \leq D \leq 16, 1 \leq d \leq 9, 1 \leq K \leq 200$

------

### 题解报告

状压 $DP$，令 $dp[s][j]$ 表示，在状态集合为 $s$ 的情况下，余数为 $j$  的最大数。

$s$ 二进制表示下，若第 $i$ 位为 $1$，表示该状态集合中包含 $d[i]$，否则不包含。

状态为 $s$ 时，枚举每个数字 $d[i]$，若 $i$ 不在当前集合 $s$ 中，

则将 $i$  加入 $s$ 集合中，同时枚举余数 $j$。

因为要求数最大，所以转移时 $i$ 自动加入到最后一位，

状态 $dp[s][j]$ 就可以转移到状态 $dp[s | (1 << i)][(j * 10 + d[i]) \% K]$。

也即 $dp[s | (1 << i)][nxt] = max (dp[s | (1 << i)][nxt], dp[s][j] * 10 + d[i])$。

式中 $nxt = (j * 10 + d[i]) \% K$。

时间复杂度 $O(2^{D} \cdot D \cdot K)$，略极限。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e2 + 5;

int D, K;
int d[25];
int dp[1 << 16][maxn];

void init () {}

void charming () {
	cin >> D >> K;
	for (int i = 0; i < D; ++i) cin >> d[i];	
	memset (dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int s = 0; s < (1 << D); ++s) {
		for (int i = 0; i < D; ++i) {
			if ((s >> i) & 1) continue;
			for (int j = 0, nxt; j < K; ++j) {
				if (dp[s][j] == -1) continue;
				nxt = (j * 10 + d[i]) % K;
				dp[s | (1 << i)][nxt] = max (dp[s | (1 << i)][nxt],
				dp[s][j] * 10 + d[i]);
			}
		}
	}
	for (int i = K - 1; i >= 0; --i) {
		if (dp[(1 << D) - 1][i] != -1) {
			cout << dp[(1 << D) - 1][i] << endl;
			break;
		}
	}
}

signed main () {
	charming ();
	return 0;	
}
```

-----

### 收获&总结

状压 $DP$ 压缩的状态常常是某个元素是否存在，转移的过程常常是不断将未在当前元素加入到当前元素的过程。