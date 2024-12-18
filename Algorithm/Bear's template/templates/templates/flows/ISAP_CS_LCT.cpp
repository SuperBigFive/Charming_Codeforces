#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1201;
ll inf = LLONG_MAX;
struct edge { int v, p; ll c; };

vector<edge> g[N];
int dis[N], cur[N], cnt[N];

namespace LCT {
int ch[3][N], *ls = ch[0], *rs = ch[1], *fa = ch[2];
int nxt[N];
ll val[N], minv[N], tag[N];

inline int id(int x) { return ch[1][fa[x]] == x; }
inline bool isr(int x) { return ch[id(x)][fa[x]] != x; }

void update(int p, ll t) {
    if (nxt[p]) val[p] += t;
    minv[p] += t;
    tag[p] += t;
}

void push_up(int p) {
    minv[p] = min(min(minv[ls[p]], minv[rs[p]]), val[p]);
}

void push_down(int p) {
    if (!tag[p]) return;
    if (ls[p]) update(ls[p], tag[p]);
    if (rs[p]) update(rs[p], tag[p]);
    tag[p] = 0;
}

inline void rot(int x) {
    int y = fa[x], z = fa[y], o = id(x), w = ch[!o][x];
    push_down(y); push_down(x);
    if (!isr(y)) ch[id(y)][z] = x; fa[x] = z;
    ch[o][y] = w; if (w) fa[w] = y;
    ch[!o][x] = y; fa[y] = x;
    push_up(y); push_up(x);
}

void splay(int x) {
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
    fa[x] = nxt[x] = y;
    val[x] = g[x][cur[x]].c;
    push_up(x);
}

void cut(int x) {
    int y = g[x][cur[x]].v;
    access(y);
    splay(x);
    fa[x] = nxt[x] = 0;
    edge& e = g[x][cur[x]];
    g[e.v][e.p].c += e.c - val[x];
    e.c = val[x];
    val[x] = inf;
    push_up(x);
}

void modify(int x, ll v) {
    access(x);
    splay(x);
    update(x, v);
}

int find_min(int x) {
    access(x);
    splay(x);
    while (ls[x] || rs[x]) {
        push_down(x);
        if (minv[x] == minv[ls[x]])
            x = ls[x];
        else if (val[x] != minv[x])
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
    fill_n(cnt, n, 0);
    for (int i = 0; i < n; ++i) cnt[dis[i]]++;
}

ll ISAP_CS_LCT(int s, int t, int n) {
    ll f = 0;
    fill_n(LCT::val, n, inf);
    fill_n(LCT::minv, n, inf);
    for (ll del = 1 << 28; del >= 1; del >>= 4) {
        bfs(s, t, n, del);
        fill_n(cur, n, 0);
        for (int u = s; dis[s] < n;) {
            while (cur[u] != g[u].size()) {
                edge e = g[u][cur[u]];
                if (dis[u] == dis[e.v] + 1 && e.c >= del)
                    break;
                ++cur[u];
            }
            if (cur[u] == g[u].size()) {
                cur[u] = 0;
                if (!--cnt[dis[u]]) break;
                dis[u] = n;
                for (edge e : g[u]) {
                    if (nxt[e.v] == u)
                        LCT::cut(e.v);
                    if (e.c >= del)
                        dis[u] = min(dis[u], dis[e.v] + 1);
                }
                cnt[dis[u]]++;
                u = LCT::find_root(s);
            }
            else {
                LCT::link(u);
                int v = g[u][cur[u]].v;
                u = LCT::find_root(v);
                if (u == t) {
                    u = LCT::find_min(s);
                    ll df = val[u];
                    LCT::modify(s, -df);
                    f += df;
                    do {
                        LCT::cut(u);
                        u = LCT::find_min(s);
                    } while (val[u] == 0);
                    u = LCT::find_root(s);
                }
            }
        }
        for (int i = 0; i < n; ++i) if (nxt[i]) cut(i);
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

    printf("%lld\n", ISAP_CS_LCT(s, t, n));

    return 0;
}