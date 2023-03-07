## [ICPC-43th-西安-E Tree](https://nanti.jisuanke.com/t/39272)

### 题目描述

$n$ 个节点的树， $m$ 次操作。每个节点都有点权 $a[i]$，共有三种操作。

- 操作$1$：把 $1$ 号节点到 $s$ 号节点的路径上所有点权 $a[i]$ 修改为 $a[i]\  |\  t$。

- 操作$2$：把 $1$ 号节点到 $s$ 号节点的路径上所有点权 $a[i]$ 修改为 $a[i]\  \&\  t$。

- 操作$3$：询问 $1$ 号节点到 $s$ 号节点路径的点权异或和与 $t$ 的异或值。

### 数据范围

$1 ≤ n, m ≤ 10^{5},0≤a_i≤10^9$

$1 \le opt \le 3, 1 \le s \le 10^5, 0 \le t \le 10^9$

------

### 题解报告

先上个树剖，结合线段树 + 懒惰标记把树变成一个数组。

**（1）考虑区间或操作，会对区间异或和产生什么影响。**

或操作可以使一个位变成1，不论之前是否是1。

区间异或和，其实就相当于这个区间内某位有奇数个1还是偶数个1。

这个时候很自然地想到要分区间长度奇偶。

如果区间长度是偶数，

那么我们就要把异或和中所有是1而 $t$ 中也是1的位都变成0；

如果区间长度是奇数，

那么我们就要把异或和中所有是0而 $t$ 中是1的位都变成1；

**（2）考虑区间和操作，会对区间异或和产生什么影响**

一个很直观的感受就是，对区间和操作后，我们只用考虑 $t$ 中有 $1$ 的位置。

区间异或和的某位是1是0，取决于区间内该位的1的个数的奇偶性，

而区间和操作是不改变这个奇偶性的（原来是1那就还是1，原来是0现在也是0）。

若异或和某位是1，而 $t$ 的该位是0，那么我们就要把异或和的该位变成0。

**综上：** 对于操作1，若区间长度为偶数，则修改为$sum = sum - (sum\  \& \ lazy)$

若区间长度为奇数，则修改为 $sum = sum\  | \ lazy$。

对于操作2，不论区间长度为奇数偶数，区间异或和直接修改为 $sum = sum\  \& \ lazy$。

**（3）分别考虑懒惰标记对自身如何下传**

如果对上述过程理解，很容易想到，或标记的下传就是直接或等于，和标记的下传就是直接和等于。

$lazy[son[cnt]]\  |= \ lazy[cnt]$，$lazy[son[cnt]]\ \&= \ lazy[cnt]$。

**（4）考虑懒惰标记互相之间如何影响及下传的顺序**

## 不会。

直接说结论吧，有点复杂，想不下去了，就直接看别人怎么写的了。

先下传和标记，再下传或标记。

或标记不对和标记产生影响，和标记对或标记产生影响（或标记要和和标记一起 \& 某值）

就以上两点。

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m, tot;
int val[maxn];
int fa[maxn], son[maxn], siz[maxn], dep[maxn];
int dfn[maxn], rk[maxn], top[maxn];
int sum[maxn << 2], lazy_1[maxn << 2], lazy_2[maxn << 2]; 
int ls[maxn << 2], rs[maxn << 2];
vector <int> adj[maxn];

void build (int cnt, int l, int r) {
	lazy_1[cnt] = 0, lazy_2[cnt] = -1;
	if (l == r) {
		sum[cnt] = val[rk[l]];
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
	sum[cnt] = sum[ls[cnt]] ^ sum[rs[cnt]];
}

void pushdown (int cnt, int l, int mid, int r) {
	if (lazy_2[cnt] != -1) {
		sum[ls[cnt]] &= lazy_2[cnt], sum[rs[cnt]] &=  lazy_2[cnt];
		lazy_2[ls[cnt]] &= lazy_2[cnt], lazy_1[ls[cnt]] &= lazy_2[cnt];
		lazy_2[rs[cnt]] &= lazy_2[cnt], lazy_1[rs[cnt]] &= lazy_2[cnt];
		lazy_2[cnt] = -1;
	}
	if (lazy_1[cnt] != 0){
		if ((mid - l + 1) & 1) sum[ls[cnt]] |= lazy_1[cnt], lazy_1[ls[cnt]] |= lazy_1[cnt];
		else sum[ls[cnt]] -= sum[ls[cnt]] & lazy_1[cnt], lazy_1[ls[cnt]] |= lazy_1[cnt];
		if((r-mid)&1) sum[rs[cnt]] |= lazy_1[cnt],lazy_1[rs[cnt]] |= lazy_1[cnt];
		else sum[rs[cnt]] -= sum[rs[cnt]] & lazy_1[cnt], lazy_1[rs[cnt]] |= lazy_1[cnt]; 
		lazy_1[cnt] = 0;
	}
}

void modify (int cnt, int l, int r, int ql, int qr, int op, int k) {
	if (l >= ql && r <= qr) {
		if (op == 1) {
			if ((r - l + 1) & 1) sum[cnt] |= k;
			else sum[cnt] -= sum[cnt] & k;
			lazy_1[cnt] |= k;
		}
		else {
			sum[cnt] &= k;
			lazy_1[cnt] &= k;
			lazy_2[cnt] &= k;
		}
		return;
	}
	int mid = l + r >> 1;
	pushdown (cnt, l, mid, r);
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, op, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, op, k);
	sum[cnt] = sum[ls[cnt]] ^ sum[rs[cnt]];
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return sum[cnt];
	int mid = l + r >> 1, res = 0;
	pushdown (cnt, l, mid, r);
	if (ql <= mid) res ^= query (ls[cnt], l, mid, ql, qr);
	if (qr > mid) res ^= query (rs[cnt], mid + 1, r, ql, qr);
	return res;
}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
		siz[u] += siz[it];
		if (siz[it] > siz[son[u]]) son[u] = it;
	}
}

void dfs2 (int f, int u, int tp) {
	dfn[u] = ++tot, rk[tot] = u, top[u] = tp;
	if (son[u]) dfs2 (u, son[u], tp);
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		dfs2 (u, it, it);
	}
}

void add_or (int s, int t) {
	while (top[s] != 1) {
		modify (0, 1, n, dfn[top[s]], dfn[s], 1, t);
		s = fa[top[s]];
	}
	modify (0, 1, n, 1, dfn[s], 1, t);
}

void add_and (int s, int t) {
	while (top[s] != 1) {
		modify (0, 1, n, dfn[top[s]], dfn[s], 2, t);
		s = fa[top[s]];
	}
	modify (0, 1, n, 1, dfn[s], 2, t);
}

bool check (int s, int t) {
	int res = 0;
	while (top[s] != 1) {
		res ^= query (0, 1, n, dfn[top[s]], dfn[s]);
		s = fa[top[s]];
	}
	res ^= query (0, 1, n, 1, dfn[s]);
	return res ^ t;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1), dfs2 (0, 1, 1);
	tot = 0;
	build (0, 1, n);
	for (int i = 1, op, s, t; i <= m; ++i) {
		cin >> op >> s >> t;
		if (op == 1) add_or (s, t);
		else if (op == 2) add_and (s, t);
		else cout << (check (s, t) ? "YES" : "NO") << endl;
	}
}

signed main () {
	charming ();
	return 0;
}
```

-----

### 收获&总结

这道题的树剖 + 线段树其实并不是关键所在，打 $ACM$ 的基本都能想到这样处理。

麻烦的就是对于懒惰标记之间的影响的分析。

在寝室训练有点懒，总不想把问题往深处考虑，不知道赛场的环境下能不能 $A$ 掉这题。