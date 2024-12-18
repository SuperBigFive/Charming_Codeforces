#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1201;
ll inf = LLONG_MAX;
struct edge { int v, p; ll c; };

vector<edge> g[N];
int dis[N], cur[N];

namespace LCT {
int ch[3][N], *ls = ch[0], *rs = ch[1], *fa = ch[2];
int nxt[N];
ll minv[N], tag[N];

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
    if (isr(x))
        assert(false);
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
        splay(x), rs[x] = y, push_up(x);
}

int find_root(int x) {
    access(x); splay(x); push_down(x);
    while (ls[x]) push_down(x = ls[x]);
    splay(x); return x;
}

void link(int x) {
    int y = g[x][cur[x]].v;
    splay(x);
    fa[x] = y;
    nxt[x] = y;
    push_up(x);
    splay(x);
}

void cut(int x) {
    int y = g[x][cur[x]].v;
    access(y);
    splay(x);
    fa[x] = 0;
    nxt[x] = 0;
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

void bfs(int s, int t, int n, ll del) {
    fill_n(dis, n, n);
    dis[t] = 0;
    queue<int> q; q.push(t);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (edge e : g[u]) 
            if (g[e.v][e.p].c >= del && dis[e.v] == n)
                dis[e.v] = dis[u] + 1, q.push(e.v);
    }
}

ll Dinic_CS_LCT(int s, int t, int n) {
    ll f = 0;
    for (ll del = 1 << 30; del >= 1; del >>= 5) {
        while (1) {
            bfs(s, t, n, del);
            if (dis[s] >= n) break;
            fill_n(LCT::minv, n, inf);
            fill_n(LCT::tag, n, 0);
            fill_n(LCT::nxt, n, 0);
            fill_n(LCT::ls, n, 0);
            fill_n(LCT::rs, n, 0);
            fill_n(LCT::fa, n, 0);

            fill_n(cur, n, 0);
            int u = s;
            while (1) {
                while (cur[u] != g[u].size()) {
                    edge e = g[u][cur[u]];
                    if (dis[u] == dis[e.v] + 1 && e.c >= del && cur[e.v] != g[e.v].size())
                        break;
                    ++cur[u];
                }
                if (cur[u] == g[u].size()) {
                    if (u == s) break;
                    for (edge e : g[u])
                        if (nxt[e.v] == u)
                            LCT::cut(e.v);
                    u = LCT::find_root(s);
                }
                else {
                    LCT::link(u);
                    int v = g[u][cur[u]].v;
                    u = LCT::find_root(v);
                    if (u == t) {
                        u = LCT::find_min(s);
                        ll df = LCT::find_val(u);
                        LCT::modify(s, -df);
                        while (LCT::find_val(u) == 0) {
                            LCT::cut(u);
                            u = LCT::find_min(s);
                        }
                        f += df;
                        u = LCT::find_root(s);
                    }
                }
            }
        }
    }
    return f;
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

    printf("%lld\n", Dinic_CS_LCT(s, t, n));

    return 0;
}