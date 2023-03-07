## [CF 803F - Coprime Subsequences](https://codeforces.com/contest/803/problem/F) 

### 题目描述

给定 $n$ 个数 $a_1, a_2...a_n$，求满足子序列内所有数的 $gcd$ 为 $1$ 的子序列个数，答案模 $10^9 + 7$。

### 数据范围

$1 \leq n \leq 10^5, 1\leq a_i \leq 10^5$

------

### 题解报告

若某个子序列所有数的 $gcd$ 为 $x$，则意味着该序列中所有数字都是 $x$ 的倍数。

预处理出所有数 ($1$ 到 $10^5$) 的约数，用 $cnt[i]$ 数组存储给定的 $n$ 个数中，

是 $i$ 的倍数的数的个数。

$n$ 个数中每个 $a_i$ 对其所有约数 $x$ 的 $cnt[x]$ 贡献为 $1$。

令 $res[i]$ 表示所有数的 $gcd$ 为 $i$ 的子序列的个数，

则 $res[i] = 2^{cnt[i]} - 1$，但是，其中可能存在子序列中所有数的 $gcd$ 为 $2i, 3i...$ 的情况，

（因为 $cnt[i]$ 存的是  $i$ 的倍数的数的个数）

可以倒序更新答案，$res[i] = 2^{cnt[i]} - 1 - \sum _{j = k * i} res[j]$。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int n;
ll cnt[maxn], res[maxn], pow2[maxn];
vector <int> fac[maxn];

void init () {}

void get_fac () {
	for (int i = 1; i < maxn; ++i) {
		for (int j = i; j < maxn; j += i) {
			fac[j].emplace_back (i);
		}
	}
}

void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		pow2[i] = (pow2[i - 1] * 2) % mod;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		for (auto it : fac[x]) ++cnt[it];
	}
	for (int i = maxn - 1; i >= 1; --i) {
		res[i] = pow2[cnt[i]] - 1;
		for (int j = i + i; j < maxn; j += i) {
			res[i] = (res[i] - res[j] + mod) % mod;
		}
	}
	cout << res[1] << endl;
}

signed main () {
	get_fac ();
	get_pow2 ();
	charming ();
	return 0;
}
```

-----

### 收获&总结

第一次写容斥 + 组合数学...对 $gcd$ 的认识还不是很深刻，发现有关多个数的 $gcd$ 的问题，意识到这些数都是 $gcd$ 的倍数这一点很关键。