#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1201;
ll inf = LLONG_MAX;
struct edge { int v, p; ll c; };

vector<edge> g[N];
int dis[N], cur[N];
ll ex[N];

bool inq[N];


namespace LCT {
int ch[3][N], *ls = ch[0], *rs = ch[1], *fa = ch[2];
ll minv[N], tag[N]; int sz[N], vsz[N];
int nxt[N];

inline int id(int x) { return ch[1][fa[x]] == x; }
inline bool isr(int x) { return ch[id(x)][fa[x]] != x; }

void update(int p, ll t) {
    edge& e = g[p][cur[p]];
    if (nxt[p]) {
        e.c += t;
        g[e.v][e.p].c -= t;
    }
    minv[p] += t;
    tag[p] += t;
}

void push_up(int p) {
    sz[p] = sz[ls[p]] + sz[rs[p]] + vsz[p] + 1;
    minv[p] = min(minv[ls[p]], minv[rs[p]]);
    if (nxt[p]) minv[p] = min(minv[p], g[p][cur[p]].c);
}

void push_down(int p) {
    if (!tag[p]) return;
    if (ls[p]) update(ls[p], tag[p]);
    if (rs[p]) update(rs[p], tag[p]);
    tag[p] = 0;
}

inline void rot(int x) {
    int y = fa[x], z = fa[y], o = id(x), w = ch[!o][x];
    if (!isr(y)) ch[id(y)][z] = x; fa[x] = z;
    ch[o][y] = w; if (w) fa[w] = y;
    ch[!o][x] = y; fa[y] = x;
    push_up(y);
    push_up(x);
}

void push_tag(int x) {
    static int s[N];
    static int t; s[++t] = x;
    while (!isr(x)) s[++t] = x = fa[x];
    while (t) push_down(s[t--]);
}

void splay(int x) {
    push_tag(x);
    for (int y; !isr(x); rot(x))
        if (!isr(y = fa[x])) rot(id(x)^id(y)?x:y);
}

void access(int x) {
    for (int y = 0; x; x = fa[y = x])
        splay(x), vsz[x] += sz[rs[x]], vsz[x] -= sz[y], rs[x] = y, push_up(x);
}

int find_root(int x) {
    access(x); splay(x); push_down(x);
    while (ls[x]) push_down(x = ls[x]);
    splay(x); return x;
}

int find_size(int x) {
    return sz[find_root(x)];
}

void link(int x) {
    int y = g[x][cur[x]].v;
    splay(x);
    vsz[y] += sz[x];
    fa[x] = y;
    nxt[x] = y;
    push_up(y);
}

void cut(int x) {
    int y = g[x][cur[x]].v;
    access(y);
    splay(x);
    vsz[y] -= sz[x];
    fa[x] = 0;
    nxt[x] = 0;
    push_up(y);
}

void modify(int x, ll v) {
    access(x);
    splay(x);
    update(x, v);
}

ll find_val(int x) {
    access(x);
    splay(x);
    return nxt[x] ? g[x][cur[x]].c : inf;
}

int find_min(int x) {
    access(x);
    splay(x);
    while (ls[x] || rs[x]) {
        push_down(x);
        if (minv[x] == minv[ls[x]])
            x = ls[x];
        else if ((nxt[x] ? g[x][cur[x]].c : inf) != minv[x])
            x = rs[x];
        else break;
    }
    splay(x);
    return x;
}

}

using namespace LCT;

void adde(int u, int v, ll c) {
    g[u].push_back({ v, (int)g[v].size(), c });
    g[v].push_back({ u, (int)g[u].size() - 1, 0 });
}

void push(int u, int i, ll df) {
    edge &e = g[u][i];
    df = min(df, e.c);
    if (df == 0) return;
    e.c -= df; ex[u] -= df;
    g[e.v][e.p].c += df; ex[e.v] += df;
}

void bfs(int s, int t, int n) {
    fill_n(dis, n, n);
    dis[t] = 0;
    queue<int> q; q.push(t);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (edge e : g[u])
            if (g[e.v][e.p].c >= 1 && dis[e.v] == n)
                dis[e.v] = dis[u] + 1, q.push(e.v);
    }
    dis[s] = n;
}

ll fifopp_LCT(int s, int t, int n) {
    fill_n(LCT::minv, n, inf);
    fill_n(LCT::tag, n, 0);
    fill_n(LCT::nxt, n, 0);
    fill_n(LCT::ls, n, 0);
    fill_n(LCT::rs, n, 0);
    fill_n(LCT::fa, n, 0);
    fill_n(LCT::sz, n, 1); sz[0] = 0;

    queue<int> q;
    bfs(s, t, n);
    ex[s] = 0; inq[s] = inq[t] = 1;
    for (int i = 0; i < g[s].size(); ++i) {
        push(s, i, inf);
        if (!inq[g[s][i].v])
            q.push(g[s][i].v), inq[g[s][i].v] = 1;
    }

    ll del = 0;
    for (int i = 0; i < n; ++i)
        del += g[i].size();
    del = 1ll * n * n / del;
    
    while (!q.empty()) {
        int u = q.front();

        while (cur[u] != g[u].size()) {
            edge e = g[u][cur[u]];
            if (dis[u] == dis[e.v] + 1 && e.c >= 1)
                break;
            ++cur[u];
        }

        if (cur[u] == g[u].size()) {
            cur[u] = 0;
            q.pop();
            dis[u] = 2 * n - 1;
            for (edge e : g[u]) {
                if (e.c >= 1)
                    dis[u] = min(dis[u], dis[e.v] + 1);
                if (nxt[e.v] == u)
                    cut(e.v);
            }
            if (dis[u] < n) q.push(u);
        } else {
            edge e = g[u][cur[u]];
            int r = find_root(u);
            if (r == u) {
                if (find_size(u) + find_size(e.v) <= del)
                    link(u);
                else {
                    push(u, cur[u], ex[u]);
                    if (!ex[u]) q.pop(), inq[u] = 0;
                    if (!inq[e.v]) q.push(e.v), inq[e.v] = 1;
                }
            }
            else {
                int v = LCT::find_min(u);
                ll df = min(LCT::find_val(v), ex[u]);
                LCT::modify(u, -df);
                ex[u] -= df;
                ex[r] += df;
                if (!ex[u]) q.pop(), inq[u] = 0;
                if (!inq[r]) q.push(r), inq[r] = 1;

                while (LCT::find_val(v) == 0) {
                    LCT::cut(v);
                    v = LCT::find_min(u);
                }
            }
        }
    }
    return ex[t];
}

int main(void) {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    n++;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adde(u, v, c);
    }

    printf("%lld\n", fifopp_LCT(s, t, n));

    return 0;
}