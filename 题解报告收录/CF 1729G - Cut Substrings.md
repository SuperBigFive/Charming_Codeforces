## [CF 1729 - G - Cut Substrings](https://codeforces.com/contest/1729/problem/G) 

### 题目描述

$q$ 组测试，从字符串 $s$ 中删除字符串 $t$（删除后原位置用 $'.'$ 替代），直至 $s$ 中无 $t$ 出现，输出删除的最少次数，并求出删除次数最小时，删除位置的方案数( {2, 3, 5} 和 {2, 3} 视为不同的方案数，{2, 5} 和 {5, 2} 视为相同)。

### 数据范围

$ 1 \leq q \leq 50 ，1 \leq |s|,|t| \leq 500$。

-----

### 题解报告

首先预处理出所有 $s$ 串中成功匹配 $t$ 串的起始位置，考虑用动态规划求解该题。

定义 $mov[i]$ 为考虑前 $i$ 个匹配点时，最小删除次数；

定义 $dp[i]$ 为考虑前 $i$ 个匹配点时删除次数最小的方案数。

这道题的移，要从某个状态可以转移到哪些状态考虑，而不是考虑某个状态可以从哪些状态转移来。

从小到大，依此考虑每个匹配点能够对哪些匹配点产生影响、转移。

对于第 $i$ 个匹配点，假设该匹配点在 $s$ 串上对应的位置是 $[l1, r1]$，

我们从右边找到第一个不与该区间重叠的的匹配点记为 $j$，

找到最后一个与匹配点 $j$ 有重叠的匹配点记为 $k$，

则对于 $j$ 到 $k$ 的所有匹配点，均可从第 $i$ 个匹配点进行转移。

【Tips : $j$ 到 $k$ 所有匹配点都不与 $i$ 的匹配区间重叠，

且与 $i$ 的匹配区间之间不存在别的完整的匹配区间，保证了转移的合法性（能把 $t$ 删完）。】

设 $p \in [j, k]$，若 $mov[p]$ 比 $mov[i] + 1$ 大，则必须强制让 $p$ 点只能从 $i$ 点转移（满足删除次数最小），

更新 $mov[p] = mov[i] + 1, dp[p] = dp[i] + 1$；

若 $mov[p] == mov[i] + 1$，则说明 $p$ 点也可以从 $i$ 点转移而来，

更新 $dp[p] = (dp[p] + dp[i])\  % \  mod$。

$dp$ 初始状态的设置：所有 $mov[i]$ 初始化为无穷大，所有 $dp[i]$ 初始化为0；

所有匹配区间与第一个区间有重叠的匹配点 $i$ （包括第一个匹配点）都初始化为 $mov[i] = dp[i] = 1$。

答案则从匹配区间与最后一个有重叠的匹配点 $i$ （包括最后一个匹配点）里找。

【Tips：为什么一直强调匹配区间重叠？正是因为重叠，才有了多种方案的选择，彼此重叠的匹配点之间任意（若不要求删除次数最小）选择一个就可以了】

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e2 + 5;
const int mod = 1e9 + 7;

int q, n, m;
int nxt[maxn];
int mov[maxn], dp[maxn];
vector <int> pos;
string s, t;

void init () {
	fill (mov, mov + maxn, INT_MAX);
	fill (dp, dp + maxn, 0);
	pos.clear ();
}

void get_nxt () {
	for (int i = 2, j = 0; i <= m; ++i) {
		while (j && t[i] != t[j + 1]) j = nxt[j];
		if (t[i] == t[j + 1]) ++j;
		nxt[i] = j;
	}
}

void kmp () {//这题其实用不到 kmp，完全暴力求就完事了，我只是顺便练习一下 kmp 写法，保持手感
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j && s[i] != t[j + 1]) j = nxt[j];
		if (s[i] == t[j + 1]) ++j;
		if (j == m) {
			pos.emplace_back (i - m + 1);
			j = nxt[j];
		}
	}
}

void charming () {
	init ();
	cin >> s, n = s.size (), s = '#' + s;
	cin >> t, m = t.size (), t = '#' + t;
	get_nxt (), kmp ();
	if (!pos.size ()) {//没有匹配点，直接输出答案
		cout << 0 << " " << 1 << endl;
		return;
	}
	mov[0] = dp[0] = 1;
	for (int i = 1; i < pos.size (); ++i) {
		if (pos[i] > pos[0] + m - 1) break;
		else mov[i] = 1, dp[i] = 1;
	}//初始状态的设置
	for (int i = 0; i < pos.size (); ++i) {
		int j = i + 1;
		while (j < pos.size () && pos[j] <= pos[i] + m - 1) ++j;
		for (int k = j; k < pos.size (); ++k) {//k 的匹配区间不与 i 重叠
			if (pos[k] > pos[j] + m - 1) break;//且 k 与 i 的匹配区间之间无完整的其他匹配点的匹配区间
			if (mov[k] > mov[i] + 1) {//强制令 k 只从 i 转移
				mov[k] = mov[i] + 1;
				dp[k] = dp[i];
			}
			else if (mov[k] == mov[i] + 1) dp[k] = (dp[k] + dp[i]) % mod;//多种转移，累加答案
		}
	}
	int ans_mov = 0, ans_dp = 0;
	for (int i = pos.size () - 1; i >= 0; --i) {
		if (pos[i] + m - 1 < pos.back ()) break;
		if (mov[i] < ans_mov || !ans_mov) {
			ans_mov = mov[i];
			ans_dp = dp[i];
		}
		else if (mov[i] == ans_mov) ans_dp = (ans_dp + dp[i]) % mod;
	}//初始化和求答案的过程其实和转移的过程几乎一样的...
    //所以有个更简洁的写法，添加两个虚点，添加一个匹配点匹配位置负无限大放第一个位置
    //添加一个匹配点匹配位置正无限大，放最后一个位置
    //只设置第一个匹配点的初始状态就行了，求答案时只找最后一个匹配点
	cout << ans_mov << " " << ans_dp << endl;
}

signed main () {
	cin >> q;
	while (q--) charming ();
	return 0;
}
```

-----

### 收获&总结

如果正着考虑走不通，那就反着来考虑。打 $ACM$ 常用的一种思路。

不考虑每个答案通过哪些因素来求得，而考虑每个因素能对哪些答案产生影响。

考虑每个状态能转移给哪些状态，这应该是第一次遇到~~（刷题太少了，也可能遇到了没重视）~~。

还有初始状态的设置，在这方面我也纠结了很久。

也许可以无脑假设只有一种状态时的答案当作初始状态，其余全部赋值无限大或者 $0$ ?