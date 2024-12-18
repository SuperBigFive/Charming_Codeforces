---
title: "NetworkAlgorithms"
author: forgottencsc
date: Dec 11, 2020
geometry: margin=1cm
output: pdf_document
---

## 匹配

定理（Berge）：**对于一张图$G=(V,E)$与其上的一个匹配$M$，$M$是$G$的一个最大匹配当且仅当不存在增广路。**

定理（Berge）：**对于一张图$G=(V,E)$与其上的一个匹配$M$，若$M$中不存在从$u$出发的增广路，则存在某个最大匹配$M'$使得$u$在$M'$中未被匹配**

定理（Konig）：若$G=(X \cup Y,E)$是二分图，则最大匹配等于最小点覆盖。

定理（Hall）：对于二分图$G=(X \cup Y,E)$，设$\Gamma(S)$为点集$S$的邻点集合，则其对于$X$完美匹配当且仅当对于任意一个点集$A\subseteq X$有$|\Gamma(A)| \geq |A|$。

定理：每一个最大权完美匹配都在KM算法运行完毕后最终的相等子图中。

定理：$(u,v)$在$M$中且不属于任何一个交错环或偶数条边的交错链是$(u,v)$一定在最大匹配中的充要条件。

定理：$(u,v)$属于某个交错环或偶数条边的交错链是$(u,v)$可能在最大匹配中的充要条件。

定理：$(u,v)$只属于奇数条边的交错链是$(u,v)$一定不在最大匹配中的充要条件。

判断一般图是否有完美匹配：设$G$是一个简单无向图，$G'$是将$G$中所有边任意定向所得有向图，定义Tutte矩阵
$$
T(G')_{uv}= \begin{cases}
x_{uv} & (u,v) \in G'\\
-x_{vu} & (v,u) \in G'\\
0 & other
\end{cases}
$$
定理(Tutte)：$G$有完美匹配当且仅当$|T(G')|$不恒为$0$。

### 稳定婚姻问题

有$n$个男的和$m$个女的。每个人有自己的标准。

一组匹配稳定当且仅当不存在$(u,v)$使得$(u,v)$未被匹配且$u$和$v$都对互相更满意（相对于当前配偶而言）。

`g[u]`中为一个排列，优先级从低到高。

`rk[v][u]`为`v`眼中的男性排名，越低优先级越高。

`lnk[v]`为`v`当前的配偶。

$m \geq n$时一定能找到稳定解。(?)

```cpp
queue<int> q;
for (int i = 1; i <= n; ++i)
    q.push(i);
while (!q.empty()) {
    int u = q.front(); q.pop();
    if (g[u].empty()) {
        printf("impossible\n");
        return 0;
    }
    int v = g[u].back();
    int w = lnk[v];
    if (!w) lnk[v] = u;
    else if (rk[v][w] < rk[v][u]) {
        g[u].pop_back();
        q.push(u);
    }
    else {
        lnk[v] = u;
        q.push(w);
        assert(g[w].back() == v);
        g[w].pop_back();
    }
}
```

### 二分图最大匹配

#### 匈牙利

```cpp
vector<int> g[N];
bool vis[N]; int lnk[N];
bool ff[N];

bool dfs(int u) {
    vis[u] = 1;
    for (int v : g[u])
        if (!lnk[v] || (!vis[lnk[v]] && dfs(lnk[v])))
            return lnk[v] = u;
    return false;
}

void match(int n) {
    for (int i = 1; i <= n2; ++i) {
        fill_n(vis + 1, n2, 0);
        dfs(i);
    }
}
```

#### Hopcroft-Karp

```cpp
typedef pair<int, int> pii;
namespace matching {

vector<int> g[N];
int l[N], c[N], p[N], d[N], n;
bool bfs() {
    for (int i = 1; i <= n; ++i) p[i] = d[i] = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (c[i] == 1 && !l[i]) q.push(i), d[i] = 1;
    bool fail = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (d[v]) continue;
            d[v] = l[u] ? d[l[u]] : u;
            p[v] = u;
            if (l[v])
                d[l[v]] = d[u] + 1, q.push(l[v]);
            else if (d[d[v]] == 1) {
                fail = 0;
                for (int x = v, y; x; x = y)
                    y = l[p[x]], l[x] = p[x], l[p[x]] = x;
                d[d[v]] = 0;
            }
        }
    }
    return !fail;
}

vector<pii> match(int n1, int n2, const vector<pii>& es) {
    n = n1 + n2;
    for (int i = 1; i <= n; ++i) {
        g[i].clear(); l[i] = 0;
        c[i] = (i <= n1 ? 1 : 2);
    }
    for (pii e : es) {
        int u = e.first, v = e.second;
        v += n1;
        g[u].push_back(v);
        g[v].push_back(u);
        if (!l[u] && !l[v])
            l[u] = v, l[v] = u;
    }
    while (bfs());
    vector<pii> res;
    for (int i = 1; i <= n1; ++i)
        if (l[i]) res.emplace_back(i, l[i] - n1);
    return res;
}


}
```

### 一般图最大匹配

```cpp
typedef pair<int, int> pii;
namespace matching {

vector<int> g[N];
int l[N], c[N], f[N], p[N], m[N], t, n;
int find(int x) { return f[x] ? f[x] = find(f[x]) : x; }
int lca(int x, int y) {
    for(++t; ; x = p[l[x]], swap(x, y)) {
        if (m[x = find(x)] == t) return x;
        else m[x] = x ? t : 0;
    }   
}
void blossom(int x, int y, int z, queue<int>& q) {
    for (; find(x) != z; x = p[y]) {
        p[x] = y; y = l[x]; f[x] = f[y] = z;
        if (c[y] == 2) q.push(y), c[y] = 1;
    }
}
void bfs(int s) {
    for (int i = 1; i <= n; ++i)
        c[i] = f[i] = m[i] = p[i] = 0;
    queue<int> q; q.push(s); c[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (c[v] == 2) continue;
            if (c[v] == 1) {
                int w = lca(u, v);
                blossom(u, v, w, q);
                blossom(v, u, w, q);                
            }
            else if (l[v]) {
                c[v] = 2; c[l[v]] = 1;
                p[v] = u; q.push(l[v]);
            }
            else {
                p[v] = u;
                for (int x = v, y; x; x = y)
                    y = l[p[x]], l[x] = p[x], l[p[x]] = x;
                return;
            }
        }
    }
}
vector<pii> match(int n0, const vector<pii>& es) {
    n = n0;
    fill_n(l + 1, n, 0);
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (pii e : es) {
        int x = e.first, y = e.second;
        g[x].push_back(y); g[y].push_back(x);
        if (!l[x] && !l[y]) l[x] = y, l[y] = x;
    }
    for (int i = 1; i <= n; ++i) if (!l[i]) bfs(i);
    vector<pii> res;
    for (int i = 1; i <= n; ++i) if (i < l[i])
        res.emplace_back(i, l[i]);
    return res;
}

}
```

### 二分图最大权完美匹配

重边需要提前去掉。

```cpp
​```cpp
const ll inf = LLONG_MAX;

namespace matching {

vector<int> g[N];
int lnk[N], pre[N];
bool vis[N];

ll a[N], b[N], w[N][N], sl[N];

vector<pair<pii, ll>> match(int nl, int nr, const vector<pair<pii, ll>>& es) {
    nr = max(nl, nr);
    fill_n(g + 1, nl, vector<int>());
    fill_n(lnk + 1, nr, 0);
    for (int i = 1; i <= nl; ++i)
        fill_n(w[i], nr, 0);
    for (pair<pii, ll> e : es)
        w[e.first.first][e.first.second] = e.second;
    for (int i = 1; i <= nl; ++i)
        a[i] = *max_element(w[i] + 1, w[i] + nr + 1);
    fill_n(b + 1, nr, 0);
    for (int i = 1, j, u, vt; i <= nl; ++i) {
        fill_n(vis + 1, nr, 0);
        fill_n(sl, nr + 1, inf);
        lnk[0] = i;
        for (j = 0; u = lnk[j]; j = vt) {
            ll d = inf; vis[j] = 1;
            for (int v = 1; v <= nr; ++v) {
                ll t = a[u] + b[v] - w[u][v];
                if (vis[v]) continue;
                if (sl[v] > t)
                    sl[v] = t, pre[v] = j;
                if (sl[v] < d)
                    d = sl[v], vt = v;
            }
            for (int v = 0; v <= nr; ++v) {
                if (vis[v]) a[lnk[v]] -= d, b[v] += d;
                else sl[v] -= d;
            }
        }
        for (; j; j = pre[j]) lnk[j] = lnk[pre[j]];
    }
    vector<pair<pii, ll>> res;
    for (int i = 1; i <= nr; ++i)
        res.emplace_back(pii(lnk[i], i), a[lnk[i]] + b[i]);
    return res;
}

}
```

## 最大流

```cpp
namespace dinic {

struct edge { int v, p; ll c; };
vector<edge> g[N]; int n;
int dis[N], cur[N];

int addv(int cnt = 1) {
    while (cnt--) g[n++].clear();
    return n - 1;
}

void adde(int u, int v, ll c) {
    g[u].push_back({ v, (int)g[v].size(), c });
    g[v].push_back({ u, (int)g[u].size() - 1, 0 });
}

bool bfs(int s, int t) {
    fill_n(dis, n, INT_MAX);
    queue<int> q; q.push(t); dis[t] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const edge& e : g[u]) {
            int v = e.v;
            if (dis[v] != INT_MAX || !g[e.v][e.p].c) continue;
            dis[v] = dis[u] + 1; q.push(v);
        }
    }
    return dis[s] != INT_MAX;
}

ll dfs(int u, int t, ll f) {
    if (u == t) return f;
    ll sf = 0;
    for (int& i = cur[u]; i != g[u].size(); ++i) {
        edge& e = g[u][i]; int v = e.v;
        if (!e.c || dis[v] + 1 != dis[u]) continue;
        ll df = dfs(v, t, min(e.c, f));
        sf += df; f -= df; e.c -= df; g[v][e.p].c += df;
        if (!f) break;
    }
    return sf;
}

ll maxflow(int s, int t, ll mf) {
    ll sf = 0;
    while (bfs(s, t)) {
        fill_n(cur, n, 0);
        ll f = dfs(s, t, mf);
        sf += f; mf -= f;
        if (!mf) break;
    }
    return sf;
}

}
```

## 费用流

有负权边的话需要`initiate_potential()`。

```cpp

namespace mcmf {

const int N = 4001;
const ll inf = INT_MAX;
struct edge { int v, p; ll c, w; };
vector<edge> g[N];
int vis[N], cur[N], n;
ll dis[N], pot[N];

int addv(int c) {
    while (c--) g[n++].clear();
    return n - 1;
}

void adde(int u, int v, ll c, ll w) {
    g[u].push_back({ v, (int)g[v].size(), c, w });
    g[v].push_back({ u, (int)g[u].size() - 1, 0, -w });
}

bool dijkstra(int s, int t) {
    fill_n(dis, n, inf);
    fill_n(vis, n, 0);
    typedef pair<ll, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({ dis[s] = 0, s });
    while (!q.empty()) {
        int u; ll du; tie(du, u) = q.top(); q.pop();
        if (vis[u]) continue; vis[u] = 1;
        for (edge e : g[u]) {
            int v = e.v; ll dv = du + pot[u] + e.w - pot[v];
            if (!e.c || vis[v] || dis[v] <= dv) continue;
            assert(e.w - pot[v] + pot[u] >= 0);
            q.push({ dis[v] = dv, v });
        }
    }
    return vis[t];
}

bool dinic_bfs(int s, int t) {
    fill_n(vis, n, 0);
    queue<int> q; q.push(s); vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (edge e : g[u]) {
            int v = e.v;
            if (vis[v] || !e.c) continue;
            if (dis[v] != dis[u] + e.w - pot[v] + pot[u]) continue;
            vis[v] = vis[u] + 1; q.push(v);
        }
    }
    return vis[t] != 0;
}

ll dinic_dfs(int u, int t, ll f) {
    if (u == t)
        return f;
    ll sf = 0;
    for (int& i = cur[u]; i != g[u].size(); ++i) {
        edge& e = g[u][i]; int v = e.v;
        if (!e.c || vis[v] != vis[u] + 1) continue;
        if (dis[v] != dis[u] + e.w - pot[v] + pot[u]) continue;
        ll df = dinic_dfs(v, t, min(e.c, f));
        sf += df; f -= df; e.c -= df; g[v][e.p].c += df;
        if (!f) break;
    }
    return sf;
}

void initiate_potential() {
    queue<int> q;
    for (int i = 0; i < n; ++i)
        q.push(i), vis[i] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop(); vis[u] = 0;
        for (edge e : g[u]) {
            ll dv = pot[u] + e.w;
            if (!e.c || dv >= pot[e.v]) continue;
            pot[e.v] = dv;
            if (!vis[e.v]) q.push(e.v), vis[e.v] = 1;
        }
    }
}

pair<ll, ll> mincostflow(int s, int t, ll mf) {
    ll sf = 0, sc = 0;
    fill_n(pot, n, 0);
    //  initiate_potential();
    while (dijkstra(s, t)) {
        ll f = 0;
        while (dinic_bfs(s, t)) {
            fill_n(cur, n, 0);
            ll df = dinic_dfs(s, t, mf);
            mf -= df; f += df;
            if (!mf) break;
        }
        sf += f; sc += (dis[t] + pot[t]) * f;
        for (int i = 0; i < n; ++i) pot[i] += dis[i];
        if (!mf) break;
    }
    return { sf, sc };
}

}

```

## 上下界流

### 无费用

```cpp
namespace bounded_flow {

using dinic::n;
using dinic::g;
using dinic::addv;
using dinic::adde;

ll df[N];
void adde_c(int u, int v, ll cl, ll cr) {
    adde(u, v, cr - cl);
    df[u] -= cl;
    df[v] += cl;
}

bool feasible_circulation() {
    int s = addv(1), t = addv(1);
    ll sf = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (!df[i]) continue;
        if (df[i] > 0) adde(s, i, df[i]), sf += df[i];
        else adde(i, t, -df[i]);
    }
    ll res = dinic::maxflow(s, t, sf); n -= 2;
    for (int i = 0; i < n; ++i)
        while (!g[i].empty() && g[i].back().v >= n) g[i].pop_back();
    return res == sf;
}

ll feasible_flow(int s, int t) {
    adde(t, s, inf);
    if (!feasible_circulation()) return -1;
    ll sf = g[s].back().c;
    g[s].pop_back(); g[t].pop_back();
    return sf;    
}

ll maxflow(int s, int t, ll mf) {
    ll res = feasible_flow(s, t);
    if (res == -1) return -1;
    return dinic::maxflow(s, t, mf - res) + res;
}

ll minflow(int s, int t) {
    ll res = feasible_flow(s, t);
    if (res == -1) return -1;
    return res - dinic::maxflow(t, s, inf);
}
    
}
```

### 有费用

这坨东西是用来求满足上下界限制的最小费用循环流的。

```cpp
//  Tested with CF1288F, LGP4043, LGP4542
namespace mcmf {

struct edge { int v, p; int c, w, i; };
vector<edge> g[N];
int vis[N], cur[N], n;
int dis[N], pot[N];

bool dijkstra(int s, int t) {
    fill_n(dis, n, inf);
    fill_n(vis, n, 0);
    typedef pair<int, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({ dis[s] = 0, s });
    while (!q.empty()) {
        int u; int du; tie(du, u) = q.top(); q.pop();
        if (vis[u]) continue; vis[u] = 1;
        for (edge e : g[u]) {
            int v = e.v; int dv = du + pot[u] + e.w - pot[v];
            if (!e.c || vis[v] || dis[v] <= dv) continue;
            q.push({ dis[v] = dv, v });
        }
    }
    return vis[t];
}

bool dinic_bfs(int s, int t) {
    fill_n(vis, n, 0);
    queue<int> q; q.push(s); vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (edge e : g[u]) {
            int v = e.v;
            if (vis[v] || !e.c) continue;
            if (dis[v] != dis[u] + e.w - pot[v] + pot[u]) continue;
            vis[v] = vis[u] + 1; q.push(v);
        }
    }
    return vis[t] != 0;
}

int dinic_dfs(int u, int t, int f) {
    if (u == t)
        return f;
    int sf = 0;
    for (int& i = cur[u]; i != g[u].size(); ++i) {
        edge& e = g[u][i]; int v = e.v;
        if (!e.c || vis[v] != vis[u] + 1) continue;
        if (dis[v] != dis[u] + e.w - pot[v] + pot[u]) continue;
        int df = dinic_dfs(v, t, min(e.c, f));
        sf += df; f -= df; e.c -= df; g[v][e.p].c += df;
        if (!f) break;
    }
    return sf;
}

pair<int, ll> mincostflow(int s, int t, int mf) {
    int sf = 0; int sc = 0;
    fill_n(pot, n, 0);
    while (dijkstra(s, t)) {
        int f = 0;
        while (dinic_bfs(s, t)) {
            fill_n(cur, n, 0);
            int df = dinic_dfs(s, t, mf);
            mf -= df; f += df;
            if (!mf) break;
        }
        sf += f; sc += (dis[t] + pot[t]) * f;
        for (int i = 0; i < n; ++i) pot[i] += dis[i];
        if (!mf) break;
    }
    return { sf, sc };
}

int ex[N], sc;
int addv(int cnt = 1) {
    while (cnt--) g[n++].clear();
    return n - 1;
}

void clear() {
    fill_n(ex, n, 0); sc = 0;
}

void adde(int u, int v, int c, int w, int id = 0) {
    g[u].push_back({ v, (int)g[v].size(), c, w, id });
    g[v].push_back({ u, (int)g[u].size() - 1, 0, -w, 0 });
}

void adde2(int u, int v, int l, int r, int w) {
    adde(u, v, r - l, w);
    ex[u] -= l; ex[v] += l; sc += w * l;
}

int feasible_flow() {
    int s = addv(), t = addv(), sf = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (ex[i] > 0)
            adde(s, i, ex[i], 0), sf += ex[i];
        if (ex[i] < 0)
            adde(i, t, -ex[i], 0);
    }
    auto res = mincostflow(s, t, sf);
    return res.first == sf ? sc + res.second : -1;
}

}
```

## 无向图全局最小割

### 稀疏图

```cpp
typedef pair<ll, int> pli;

//  Assuming the graph is connected!
namespace stoer_wagner_sparse {

const int N = 1201;
const ll inf = 1145141919810810;
struct edge { int v, p; ll w; };

vector<edge> g[N];
bool vis[N];
ll val[N];
void adde(int u, int v, ll w) {
    g[u].push_back({ v, (int)g[v].size(), w });
    g[v].push_back({ u, (int)g[u].size() - 1, w });
}

void delv(int u, int n) {
    for (edge e : g[u]) {
        int v = e.v;
        if (e.p + 1 != g[v].size()) {
            edge& e2 = g[v].back();
            g[e2.v][e2.p].p = e.p;
            swap(g[v][e.p], e2);
        }
        g[v].pop_back();
    }
}

ll solve(int n) {
    int n0 = n;
    ll ans = inf;
    for (int i = 1, x = 1; i <= n0 - 1; ++i) {
        int s, t; ll tv;
        fill_n(vis + 1, n, 0);
        fill_n(val + 1, n, 0);
        priority_queue<pli> pq; pq.push({ inf, x });
        while (!pq.empty()) {
            pli p = pq.top(); pq.pop();
            int u = p.second;
            if (vis[u]) continue; vis[u] = 1;
            for (edge e : g[u]) if (!vis[e.v])
                pq.push({ val[e.v] += e.w, e.v });
            s = t; t = u; tv = p.first;
        }
        ans = min(ans, tv);
        fill_n(val + 1, n, 0);
        for (edge e : g[s]) val[e.v] += e.w;
        for (edge e : g[t]) val[e.v] += e.w;
        delv(s, n); delv(t, n);
        x = ++n;
        for (int j = 1; j <= n - 1; ++j)
            if (j != s && j != t && val[j])
                adde(x, j, val[j]);
    }
    return ans;
}

}
```

### 稠密图

```cpp
namespace stoer_wagner_dense {

const int N = 1001;
const ll inf = 1145141919810810;
ll g[N][N];
ll val[N]; bool vis[N];

void clear(int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = 0;
}

void adde(int u, int v, int w) {
    g[u][v] += w; g[v][u] += w;
}

ll solve(int n) {
    ll ans = inf;
    while (n > 1) {
        fill_n(val + 1, n, 0);
        fill_n(vis + 1, n, 0);
        int s = -1, t = 1;
        for (int i = 1; i <= n - 1; ++i) {
            vis[t] = 1; int u = 0;
            for (int v = 1; v <= n; ++v) {
                if (vis[v]) continue;
                val[v] += g[t][v];
                if (!u || val[u] < val[v]) u = v;
            }
            s = t; t = u;
        }
        ans = min(ans, val[t]);
        for (int v = 1; v <= n; ++v) {
            g[s][v] += g[t][v];
            g[v][s] += g[v][t];
        }
        for (int i = t; i < n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = g[i + 1][j];
        for (int j = t; j < n; ++j)
            for (int i = 1; i < n; ++i)
                g[i][j] = g[i][j + 1];
        n--;
    }
    return ans;
}

}
```

## 最小树形图

`N`需要开到点数加边数的级别。

```cpp
struct edge { int u, v; ll w; } es[N];
int ls[N], rs[N], dis[N];
ll val[N], tag[N];

void update(int x, ll t) { val[x] += t;tag[x] += t; }
void push_down(int x) {
    if (ls[x]) update(ls[x], tag[x]);
    if (rs[x]) update(rs[x], tag[x]);
    tag[x] = 0;
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (val[x] > val[y]) swap(x, y);
    push_down(x);
    rs[x] = merge(rs[x], y);
    if (dis[ls[x]] < dis[rs[x]]) swap(ls[x], rs[x]);
    dis[x] = dis[rs[x]] + 1;
    return x;
}

int top[N], fa[N], ine[N];
int f[N]; int find(int x) { return f[x] ? f[x] = find(f[x]) : x; }
vector<int> ch[N];

ll ans[N];
void dfs(int u, ll s) {
    if (ch[u].empty())
        ans[u] = s >= inf ? -1 : s;
    else for (int v : ch[u])
        dfs(v, s - val[ine[v]]);
}

void solve(int n, int m) {
    for (int i = 1; i <= 2 * n; ++i) top[i] = fa[i] = ine[i] = f[i] = 0, ch[i].clear();
    for (int i = 1; i <= n; ++i) es[++m] = { i % n + 1, i, inf };
    for (int i = 1; i <= m; ++i) {
        ls[i] = rs[i] = tag[i] = dis[i] = 0;
        val[i] = es[i].w;
        top[es[i].v] = merge(top[es[i].v], i);
    }
    int x = 1;
    while (top[x]) {
        int i = top[x], y = find(es[i].u);
        top[x] = merge(ls[i], rs[i]);
        if (y == x) continue;
        ine[x] = i;
        if (!ine[es[i].u]) x = y;
        else for (int z = ++n; x != z; x = find(es[ine[x]].u)) {
            fa[x] = f[find(x)] = z;
            ch[z].push_back(x);
            if (top[x]) update(top[x], -val[ine[x]]);
            top[z] = merge(top[z], top[x]);
        }
    }
    
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += val[ine[i]];
    dfs(n, sum);
}

int fa2[N], ine2[N];
vector<int> expand(int n, int r) {
    copy_n(fa + 1, nc, fa2 + 1);
    copy_n(ine + 1, nc, ine2 + 1);
    vector<int> s, res; s.push_back(r);
    while (!s.empty()) {
        int x = s.back(); s.pop_back();
        int i = ine2[x]; ine2[es[i].v] = i;
        for (int y = es[i].v; fa2[y]; y = fa2[y]) {
            for (int z : ch[fa2[y]]) {
                if (z == y) continue; fa2[z] = 0;
                if (!ch[z].empty()) s.push_back(z);
            }
        }
    }
    for (int i = 1; i <= n; ++i) if (i != r) res.push_back(ine2[i]);
    return res;
}
```

