## 杂项

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

### 最小树形图

定义：在一个带权的有向图$G$中，给定一个点$r$，找出一个包含所有点的子图$T$使得：

1. 该子图中$r$的入度为$0$，除$r$外任意一点入度均为1。
2. 从$r$出发可到达其他任意一点，这等价于无环。
3. 边权和最小。

则$T$是$G$的一个最小树形图(DMST)。

一个最朴素的想法是对$r$以外的每个点选取一条边权最小的入边。

若所得结果无环，则得到的就是最小树形图。

否则可以证明，对于结果中的每一个环，存在一个最小树形图使得环上仅有一条边未被包含。

命题：设$H$是$G$的一个包含所有点的子图满足$r$的入度为$0$，其他点入度均为$1$且除$r$外每个点的入边边权最小，则对于$H$中的某一个环$C$，存在一个$H$中的最小树形图$T$包含$C$中的$|C|-1$条边。

证明：设$T$是$G$的任意一个以$r$为根的最小树形图，可以用以下操作构造出一个满足条件的$T'$。

1. 令$u$为$C$中的任意一个点，$v$为$T$中从$r$到$u$的路径上的第一个属于$C$的点。
2. 将$T$中所有指向$C$中除了$v$以外的所有点的入边全部删去。
3. 将$C$中除了指向$v$的边之外的所有边加入第二步的结果，将所得新图记为$T'$。

命题：操作3不会形成环。

证明：若形成了环，则环上一定包含至少一条$C$中的边，且这条边没有指向$v$。

沿着这条边往回走一定能够走到$v$，因为$C$中的所有除了指向$v$以外的边都被加入了$T$。

走到$v$之后，因为这三步操作没有修改$C$以外的任何一个点的入边，因此沿着$v$继续往回走一定能够走到$r$。而$r$是没有入边的，因此这个环不存在。

命题：$w(T') \leq w(T)$，因此$T'$是$G$的一个最小树形图。

证明：这三步操作将$T$中的$C$中除了$v$以外的点的入边都换成了原来在$C$中的边。

由$C$的定义，$C$是由每个点边权最小的入边组成的，因此换边后权值只会变得更小或不变。

由此可以得到一个朴素的寻找最小树形图的算法 ，即朱刘算法。

1. 将$G$中的自环去掉，令$r$以外的每个点的入边为边权最小的那一条。
2. 若所得的图中不存在环则直接结束。
3. 否则对于环$C$上的每个点$u$，将$u$的其他所有入边权值减去$u$在环上的入边的权值，然后将环缩成一个新点$z$。即对于每条边$(u,v)$，若$u$属于$C$则将$u$改成$z$，对$v$同理。
4. 令所得的新图为$G'$，则$G$中最小树形图的权值为$G'$中最小树形图的权值加上环$C$上所有边的权值和。递归下去即可。

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
#define ffirst(s) (s)._Find_first()
#define fnext(s, i) (s)._Find_next(i)
#define for_(i, n, s) for (int i = ffirst((s)); i < n; i = fnext((s), i))
using namespace std;

const int N = 80;
typedef bitset<N> bs;
bs g[N];

bs msk(int n) {
    bs b;
    for (int i = 0; i != n; ++i) b[i] = 1;
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

### 