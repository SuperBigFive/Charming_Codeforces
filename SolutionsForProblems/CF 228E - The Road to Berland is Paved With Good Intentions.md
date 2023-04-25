## [CF 228 - E -  The Road to Berland is Paved With Good Intentions ](https://codeforces.com/contest/228/problem/E) 

### 题目描述

给定 $n$ 个节点，$m$ 条无向边（无重边），每条边权值为 $0$ 或 $1$，每次操作可以将与 $i$ 节点相连的边的权值异或 $1$，问是否存在不多于 $n$ 次的操作，使得所有边的权值变为 $1$。

### 数据范围

$1 \leq n\leq 100, 1 \leq m \leq \frac {n \cdot (n - 1)} {2}$。

-----

### 题解报告

若要满足题意，则对于所有权值为 $0$ 的边，假设其两端节点分别为 $i$，$j$，

那么，必然 $i$ 与 $j$ 两个节点其中一个要进行一次操作，

即 $\overline {i} \rightarrow j,\overline {j} \rightarrow i, i \rightarrow \overline {j}, j \rightarrow \overline{i}$ 这四个必须全部满足；

对于所有权值为 $1$ 的边，假设其两端节点分别为 $i, j$，

那么，必然 $i$ 与 $j$ 要同时进行操作，

即 $i \rightarrow j,j \rightarrow i, \overline {i} \rightarrow \overline {j}, \overline {j} \rightarrow \overline{i}$ 这四个必须全部满足。

经过上述分析后，可以发现，直接建好图跑一遍 $2-Sat$ 就行了...

### AC代码：

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, tot, cnt, scc_cnt, tail;
int dfn[maxn], low[maxn];
int bel[maxn], stk[maxn];
int to[maxn], nxt[maxn], head[maxn];
vector <int> scc[maxn], adj[maxn];

void add (int u, int v) {
	to[cnt] = v, nxt[cnt] = head[u], head[u] = cnt++;
}

void tarjan (int u) {
	dfn[u] = low[u] = ++tot;
	stk[++tail] = u;
	for (int i = head[u], v; i != -1; i = nxt[i]) {
		v = to[i];
		if (!dfn[v]) {
			tarjan (v);
			low[u] = min (low[u], low[v]);
		}
		else if (!bel[v]) {
			low[u] = min (low[u], dfn[v]);
		}
	}
	if (low[u] >= dfn[u]) {
		++scc_cnt;
		while (true) {
			scc[scc_cnt].emplace_back (stk[tail]);
			bel[stk[tail]] = scc_cnt;
			if (stk[tail--] == u) break;
		}
	}
}

void init () {
	fill (head, head + maxn, -1);
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		if (w) {
			add (u, v);
			add (v, u);
			add (u + n, v + n);
			add (v + n, u + n);
		}
		else {
			add (u, v + n);
			add (v, u + n);
			add (u + n, v);
			add (v + n, u);
		}
	}
	for (int i = 1; i <= (n << 1); ++i) if (!dfn[i]) {
		tarjan (i);
	}
	vector <int> res;
	for (int i = 1; i <= n; ++i) {
		if (bel[i] < bel[i + n]) res.emplace_back (i);
		if (bel[i] == bel[i + n]) {
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << res.size () << endl;
	for (auto it : res) cout << it << " \n"[it == res.back ()];
}

signed main () {
	charming ();
	return 0;	
}
```

-----

### 收获&总结

$2-Sat$ 算法的模板性很强，重点是把问题转化成一个 $2-Sat$ 问题和建图。