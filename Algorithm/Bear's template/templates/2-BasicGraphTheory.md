---
title: "BasicGraphTheory"
author: forgottencsc
date: Dec 11, 2020
geometry: margin=1cm
output: pdf_document
---

## 欧拉路径/回路

### 有向图欧拉路

一个有向图存在欧拉路径当且仅当每个点的出入度之差的绝对值小于等于1且之多有一个出度为1的点。

字典序最小。

```cpp
int eulerian_path(int* r, int w) {
    static int s[N], t; s[++t] = w; int m = 0;
    while(t) {
        int u = s[t];
        if (g[u].empty()) r[++m] = u, --t;
        else s[++t] = g[u].back(), g[u].pop_back();
    }
    reverse(r + 1, r + m + 1); return m;
}
```

```cpp
//  Example: 按顺序输出欧拉回路中的每条边
int ans[N];
int cnt = eulerian_path(ans, s);
printf("%d\n", cnt - 1);
for (int i = 1; i <= cnt - 1; ++i) {
    printf("%d %d\n", ans[i], ans[i + 1]);

```

### 无向图欧拉路

非递归，不保证字典序。

```cpp
typedef pair<int, int> pii;
vector<pii> g[N];

void adde(int u, int v) {
    if (u != v) {
        g[u].push_back({ v, g[v].size() });
        g[v].push_back({ u, g[u].size() - 1 });
    }
    else {
        g[u].push_back({ u, g[u].size() });
    }
}

int eulerian_path(int* r, int w) {
    static int s[N], t; int m = 0; s[++t] = w;
    while (t) {
        int u = s[t];
        if (g[u].empty())
            r[++m] = u, --t;
        else {
            pii p = g[u].back();
            int v = p.first, i = p.second;
            if (v != u) {
                if (i + 1 != g[v].size()) {
                    pii& q = g[v].back();
                    g[q.first][q.second].second = i;
                    swap(g[v][i], q);
                }
                g[u].pop_back();
                g[v].pop_back();
                s[++t] = v;
            }
            else {
                g[u].pop_back();
                s[++t] = u;
            }
        }
    }
    return m;
}
```

```cpp
//  Example: 按顺序输出欧拉回路中的每条边
int ans[N];
int cnt = eulerian_path(ans, 1);
printf("%d\n", cnt - 1);
for (int i = 1; i <= cnt - 1; ++i) {
    printf("%d %d\n", ans[i], ans[i + 1]);
```

## Tarjan系列

### 强连通分量(SCC)

| `x`的DFS序 | 顶点`x`所在SCC | SCC数量 |
| ---------- | -------------- | ------- |
| `dfn[x]`   | `bel[x]`       | `scc`   |

定义：若一张有向图中任意两个点可以互相到达，则称其强连通。

强连通分量是有向图中的极大强连通子图。

```cpp
vector<int> g[N];
int dfn[N], low[N], bel[N], dfc, scc;
int dfs_scc(int u) {
    static int s[N], t; s[++t] = u;
    static bool inq[N]; inq[u] = 1;
    dfn[u] = low[u] = ++dfc;
    for (int v : g[u]) {
        if (!dfn[v]) low[u] = min(low[u], dfs_scc(v));
        else if (inq[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) for (++scc; s[t + 1] != u; --t)
        inq[s[t]] = 0, bel[s[t]]=scc;
    return low[u];
}

void tarjan_scc(int n) {
    dfc = scc = 0; fill_n(dfn + 1, n, 0);
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) dfs_scc(i);
}
```

### 边双连通分量(EBCC)

| `x`的DFS序 | 顶点`x`所在EBCC | 边`x`所在EBCC | EBCC数量 |
| ---------- | --------------- | ------------- | -------- |
| `dfn[x]`   | `vbel[x]`       | `ebel[x]`     | `ebcc`   |

定义：若一张无向图在删掉任意一条边后仍然连通，则其边双连通。

边双连通分量是无向图中的极大边双连通子图。

```cpp
//  Tested with CF231E,CF652E,732F(Single testcase)
vector<pii> g[N]; bool vis[M];
int dfn[N], low[N], vbel[N], ebel[M], dfc, ebcc;
int dfs_ebcc(int u, int f) {
    static int s[N + M], t; 
    s[++t] = u; dfn[u] = low[u] = ++dfc;
    for (pii p : g[u]) {
        int v = p.first, i = p.second;
        if (vis[i]) continue; vis[i] = 1; s[++t] = -i;
        if (!dfn[v]) low[u] = min(low[u], dfs_ebcc(v, i));
        else low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u]) {
        for (++ebcc; s[t] != -f; --t)
            s[t] > 0 ? vbel[s[t]] = ebcc : ebel[-s[t]] = ebcc;
        if (t) --t;
    }
    return low[u];
}

void tarjan_ebcc(int n, int m) {
    dfc = ebcc = 0;
    fill_n(vis + 1, m, 0);
    fill_n(ebel + 1, m, 0);
    fill_n(dfn + 1, n , 0);
    for (int u = 1; u <= n; ++u) if (!dfn[u]) dfs_ebcc(u, 0);
}
```

性质：若一个EBCC中存在一个奇环，则该EBCC中每条边都在至少一个奇环中。

### 点双连通分量(VBCC)

| `x`的DFS序 | 顶点`x`所在的所有VBCC | 边`x`所在VBCC | VBCC数量 |
| ---------- | --------------------- | ------------- | -------- |
| `dfn[x]`   | `vbel[x]`             | `ebel[x]`     | `vbcc`   |

定义：若一张无向图在删掉任意一个点后仍然连通，则其点双连通。

点双连通分量是无向图中的极大点双连通子图。

```cpp
//  Tested with CF962F(Single testcase)
vector<pii> g[N]; bool vis[M];
vector<int> vbel[N];
int dfn[N], low[N], ebel[M], dfc, vbcc;
int dfs_vbcc(int u, int f) {
    static int s[N + M], t;
	s[++t] = u; dfn[u] = low[u] = ++dfc;
    for (pii p : g[u]) {
        int v = p.first, i = p.second, z = t;
        if (vis[i]) continue; vis[i] = 1; s[++t] = -i;
        if (!dfn[v]) {
            low[u] = min(low[u], dfs_vbcc(v, i));
            if (dfn[u] <= low[v]) {
                for (++vbcc; t > z; --t) {
                    if (s[t] > 0) vbel[s[t]].push_back(vbcc);
                    else ebel[-s[t]] = vbcc;
                }
                vbel[u].push_back(vbcc);
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if (f == 0) t--;
    return low[u];
}

void tarjan_vbcc(int n, int m) {
    dfc = vbcc = 0;
    fill_n(vis + 1, m, 0);
    fill_n(ebel + 1, m, 0);
    fill_n(dfn + 1, n , 0);
    for (int u = 1; u <= n; ++u) vbel[u].resize(0);
    for (int u = 1; u <= n; ++u) if (!dfn[u]) dfs_vbcc(u, 0);
}
```

### 割点和桥

定义：割点是删除后会使其所在连通块不连通的点，桥是删除后会使其所在连通块不连通的边。

在DFS树上，若从点$u$出发无法在不经过$u$的情况下访问到DFS序比$u$低的点，则$u$为割点。特例：DFS树的根节点是割点当且仅当其至少有两个儿子。

```cpp
vector<int> g[N];
int dfn[N], low[N], dfc; bool cv[N];
int dfs_cvb(int u, int r) {
    dfn[u] = low[u] = ++dfc;
    int cnt = 0;
    for (int v : g[u]) {
        if (!dfn[v]) {
            low[u] = min(low[u], dfs_cvb(v, r));
            if (low[v] == dfn[u] && u != r) cv[u] = 1;
            if (u == r) ++cnt;
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if (u == r && cnt >= 2) cv[u] = 1;
    return low[u];
}

void tarjan_cvb(int n) {
    dfc = 0;
    fill_n(dfn + 1, n, 0);
    fill_n(cv + 1, n, 0);
    for (int i = 1; i <= n; ++i)
        dfs_cvb(i, i);
}
```

## 杂项

### $k$短路

```cpp
typedef long long ll;

namespace kth_shortest_path {

const ll inf = LLONG_MAX;
typedef pair<ll, int> pli;
struct edge { int v, i; ll w; };

//  Persistent Leftist Tree
int ls[M], rs[M], dep[M], nc; pli val[M];
int gn(pli v, int q = 0) {
    int p = ++nc;
    ls[p] = ls[q]; rs[p] = rs[q];
    dep[p] = q ? dep[q] : 1;
    val[p] = q ? val[q] : v;
    return p;
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (val[x] > val[y]) swap(x, y);
    int z = gn({}, x); rs[z] = merge(rs[z], y);
    if (dep[ls[z]] < dep[rs[z]]) swap(ls[z], rs[z]);
    dep[z] = dep[rs[z]] + 1; return z;
}


vector<edge> g[N], gr[N]; vector<int> gt[N];
ll dis[N]; int pre[N], rt[N];

ll solve(int n, int m, int s, int t, int k,
          const vector<pair<pair<int, int>, ll>>& es) {
    for (int i = 1; i <= n; ++i) {
        g[i].resize(0);
        gr[i].resize(0);
        gt[i].resize(0);
    }
    for (int i = 0; i != es.size(); ++i) {
        pair<pair<int, int>, ll> p = es[i];
        int u = p.first.first, v = p.first.second;
        ll w = p.second;
        g[u].push_back({ v, i, w });
        gr[v].push_back({ u, i, w });
    }

    //  Dijkstra
    fill_n(dis + 1, n, inf); fill_n(pre + 1, n, -1);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({ dis[t] = 0, t });
    while (!pq.empty()) {
        pli p = pq.top(); pq.pop();
        int u = p.second; ll du = p.first;
        if (du > dis[u]) continue;
        for (edge e : gr[u]) if (dis[e.v] > du + e.w)
            pq.push({ dis[e.v] = du + e.w, e.v }), pre[e.v] = e.i;
    }

    if (dis[s] == inf) return -1;

    //  Building heaps
    nc = 0; fill_n(rt + 1, n, 0);
    for (int u = 1; u <= n; ++u) {
        if (dis[u] == inf) continue;
        for (edge e : g[u]) {
            if (e.i == pre[u])
                gt[e.v].push_back(u);
            else if (dis[e.v] != inf)
                rt[u] = merge(rt[u], gn({ dis[e.v] + e.w - dis[u], e.v }));
        }
    }

    //  Merging heaps
    queue<int> q; q.push(t);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : gt[u])
            rt[v] = merge(rt[v], rt[u]), q.push(v);
    }

    //  Iterate k times
    if (k == 1) return dis[s]; int cnt = 0;
    if (rt[s]) pq.push({ dis[s] + val[rt[s]].first, rt[s] });
    while (!pq.empty()) {
        pli p = pq.top(); pq.pop();
        int x = p.second, u = val[x].second;
        ll res = p.first; if (++cnt == k - 1) return res;
        if (rt[u]) pq.push({ res + val[rt[u]].first, rt[u] });
        if (ls[x]) pq.push({ res - val[x].first + val[ls[x]].first, ls[x] });
        if (rs[x]) pq.push({ res - val[x].first + val[rs[x]].first, rs[x] });
    }
    return -1;
}

}   //  namespace kth_shortest_path
```

### 最小平均圈

$O(nm)$

```cpp
typedef double dbl;
struct edge { int v; dbl w; };
vector<edge> g[N];

dbl dp[N][N];
dbl minmwc(int n) {
    for (int i = 1; i <= n; ++i)
        g[n + 1].push_back({ i, 0 });
    n++;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = DBL_MAX;
    dp[n][0] = 0;
    for (int k = 0; k < n; ++k) {
        for (int u = 0; u <= n; ++u)
            dp[u][k + 1] = DBL_MAX;
        for (int u = 0; u <= n; ++u)
            if (dp[u][k] != DBL_MAX)
                for (edge e : g[u])
                    dp[e.v][k + 1] = min(dp[e.v][k + 1], dp[u][k] + e.w);
    }
    dbl ans = DBL_MAX;
    for (int u = 1; u <= n; ++u) {
        if (dp[u][n] == DBL_MAX) continue;
        dbl res = -DBL_MAX;
        for (int k = 0; k < n; ++k)
            if (dp[u][k] != DBL_MAX)
                res = max(res, (dp[u][n] - dp[u][k]) / (n - k));
        ans = min(ans, res);
    }
    return ans;
}
```

### 极大团枚举

~~O(猛男)~~$O^*(3^{\frac n 3})$

```cpp
#define N 80
#define ffirst(s) (s)._Find_first()
#define fnext(s, i) (s)._Find_next(i)
#define for_(i, n, s) for (int i = ffirst((s)); i < n; i = fnext((s), i))
typedef bitset<N> bs;

bs g[N];
bs msk(int n) {
    bs b;
    for (int i = 0; i != n; ++i)
        b[i] = 1;
    return b;
}

int max_clique(bs c, bs t, bs d, int n) {
    if (t.none() && d.none())
        return c.count; //  Clique c found!
    int v = -1, w = N; bs s = t | d;
    for_(u, n, s) if ((t & ~g[u]).count() < w) v = u;
    bs e = t & ~g[v];
    if (e.none()) return 0;
    int res = 0;
    for_(v, n, e) {
        bs b = 1ll << v;
        t[v] = 0;
        res = max(res, max_clique(c | b, t & g[v], d & g[v], n));
        d[v] = 1;
    }
    return res;
}
```

```cpp
//  Example:
cout << max_clique(0, msk(n), 0) << endl;
```

### 最大独立集

~~O(猛男)~~$O^*(1.29^n)$

```cpp
#define N 80
#define ffirst(s) (s)._Find_first()
#define fnext(s, i) (s)._Find_next(i)
#define for_(i, n, s) for (int i = ffirst((s)); i < n; i = fnext((s), i))
using namespace std;

typedef bitset<N> bs;

bs g[N];

bs msk(int n) {
    bs b;
    for (int i = 0; i != n; ++i)
        b[i] = 1;
    return b;
}

bs max(bs b1, bs b2) { return b1.count() < b2.count() ? b2 : b1; }

bs mis(bs s, bs c, int n) {
    if (c.none()) return s;
    int dm = -1, v;
    for_(u, n, c) {
        int d = (g[u] & c).count() - 1;
        if (d == 0) return mis(s.set(u), c.reset(u), n);
        if (d == 1) return mis(s.set(u), c & ~g[u], n);
        if (d > dm)
            dm = d, v = u;
    }
    if (dm == 2) {
        for_(u, n, c) {
            int sz = 0;
            for (v = u; v < n; ++sz) {
                if (sz & 1) s[v] = 1;
                c[v] = 0;
                v = ffirst(g[v] & c);
            }
        }
        return s;
    }
    else return max(mis(s.set(v), c & ~g[v], n), mis(s, c.reset(v), n));
}
```

```cpp
//  Example:
cout << mis(bs(), msk(n), n).count() << endl;
```

### 独立集/点覆盖计数

$O(n2^{\frac{n}{2}})$

```cpp
#define W 40

typedef bitset<W> bs;
bs g[W];
typedef long long ll;
ll f[1 << (W / 2)];
ll indset_cnt(int n) {
    int n1 = n / 2, n2 = n - n1;
    fill_n(f, 1 << n1, 0);
    for (int i = 0; i != (1 << n1); ++i) {
        f[i] = 1;
        for (int j = 0; j != n1; ++j)
            if (((1 << j) & i) && (g[j] & bs(i)).any())
                f[i] = 0;
    }
    for (int i = 0; i != n1; ++i)
        for (int j = 0; j != (1 << n1); ++j)
            if (j & (1 << i)) f[j] += f[j ^ (1 << i)];
    ll ans = 0;
    bs msk((1 << n1) - 1);
    for (int i = 0; i != (1 << n2); ++i) {
        bool flg = 0; bs b;
        for (int j = 0; j != n2; ++j) {
            if ((1 << j) & i) {
                if ((g[n1 + j] & (bs(i) << n1)).any()) {
                    flg = 1;
                    break;
                }
                b |= g[n1 + j];
            }
        }
        if (flg) continue;
        ans += f[(~b & msk).to_ulong()];
    }
    return ans;
}
```

### 染色数

$O(n2^n)$

```cpp
#define W 23
#define N 1<<23
typedef bitset<W> bs;
typedef long long ll;
bs g[W];
int w[N]; ll a[N], b[N];

int chromatic_number(int n) {
    fill_n(a, 1 << n, 1); fill_n(b, 1 << n, 1);
    for (int i = 0; i != (1 << n); ++i)
        w[i] = w[i >> 1] + (i & 1);
    for (int i = 0; i != (1 << n); ++i)
        for (int j = 0; j != n; ++j)
            if ((i & (1 << j)) && (g[j] & bs(i)).any())
                a[i] = 0;
    a[0] = 0;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != (1 << n); ++j)
            if (j & (1 << i)) a[j] += a[j ^ (1 << i)];
    int ans = 0;
    for (int k = 1; !ans; ++k) {
        for (int i = 0; i != (1 << n); ++i) b[i] *= a[i];
        ll s = 0;
        for (int i = 0; i != (1 << n); ++i)
            s += (w[i] & 1) ? -b[i] : b[i];
        if (s) ans = k;
    }
    return ans;
}
```

### 斯坦纳树

$O(n3^k+2^k(m+n)\log {m})$，

定义：给出带权无向图$G=(V,E)$与点集$V' \subseteq V,|V'|=k$，求$G$的连通子图$T$使得$V' \subseteq T$且$T$中边权和最小。

状态定义：`dp[s][u]`表示包含点$u$且与$S$中点连通的连通子图最小边权和，其中$S \subseteq V'$。

转移方程：

$$dp[S][v]=\min_{(u,v)=e\in E}\left[w(e)+\min_{\emptyset \neq T \subset S}\left(dp[T][u]+dp[S-T][u]\right)\right]$$

对连通状态$S$求解所有`dp[s][u]`时，先通过$S$的一个划分求出里面的$\min$，再通过最短路进行转移，解出其他`dp[s][u]`。

注：`W`为$k$的最大值，`res[s]`表示使$S$中点连通的最小代价，`s`的第$i$位为$1$代表`e[i]`$\in S$。

注2：$n-k$较小时可考虑暴力计算余下$n-k$个点的子集$S$与$V'$组成的子图的最小生成树，即枚举使$V'$中点连通需要使用哪些点：$S \subseteq V-V'$，复杂度$m \log m + m2^{n-k}$。

```cpp
typedef long long ll;
typedef pair<ll, int> pli;
struct edge { int v; ll w; };
vector<edge> g[N];

ll dp[1 << W][N]; int tag[N];
vector<ll> steiner_tree(int n, const vector<int>& e) {
    int w = e.size();
    fill(tag + 1, tag + n + 1, 0);
    for (int s = 1; s != 1 << w; ++s)
        fill(dp[s] + 1, dp[s] + n + 1, LLONG_MAX);
    for (int i = 0; i != w; ++i)
        tag[e[i]] = 1 << i, dp[1 << i][e[i]] = 0;
    for (int s = 1; s != 1 << w; ++s) {
        priority_queue<pli> q;
        for (int u = 1; u <= n; ++u) {
            for (int t = s & (s - 1); t; t = s & (t - 1)) {
                ll v1 = dp[t][u], v2 = dp[s ^ t][u];
                if (v1 != LLONG_MAX && v2 != LLONG_MAX)
                    dp[s][u] = min(dp[s][u], v1 + v2);
            }
            if (dp[s][u] != LLONG_MAX) q.push({ dp[s][u], u });
        }
        while (!q.empty()) {
            pli p = q.top(); q.pop();
            int u = p.second; ll du = p.first;
            if (du > dp[s][u]) continue;
            for (edge e : g[u]) {
                int v = e.v; ll dv = e.w + du;
                if (dp[s][v] > dv)
                    q.push({ dp[s][v] = dv, v });
            }
        }
    }
    vector<ll> res(1 << w);
    for (int s = 0; s != 1 << w; ++s)
        res[s] = *min_element(dp[s] + 1, dp[s] + n + 1);
    return res;
}
```

### Prufer序列

#### 由树构造Prufer序列

```cpp
int deg[N]; bool del[N];
void encode_tree(int* p, int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    fill(del + 1, del + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        deg[i] = g[i].size();
        if (deg[i] == 1)
            pq.push(i);
    }
    for (int i = 1; i <= n - 2; ++i) {
        int u = pq.top(), v; pq.pop(); del[u] = 1;
        for (int w : g[u]) if (!del[w]) v = w;
        p[i] = v; if (--deg[v] == 1) pq.push(v);
    }
}
```

#### 由Prufer序列构造树

```cpp
int cnt[N];
void decode_tree(int* p, int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n - 2; ++i) cnt[p[i]]++;
    for (int i = 1; i <= n; ++i) if (!cnt[i]) pq.push(i);
    for (int i = 1; i <= n - 2; ++i) {
        int u = p[i], v = pq.top(); pq.pop();
        g[u].push_back(v);
        g[v].push_back(u);
        if (!--cnt[u]) pq.push(u);
    }
    int u = pq.top(); pq.pop();
    int v = pq.top(); pq.pop();
    g[u].push_back(v);
    g[v].push_back(u);
}
```