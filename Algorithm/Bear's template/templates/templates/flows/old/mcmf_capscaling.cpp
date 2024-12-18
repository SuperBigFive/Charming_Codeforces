#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace mcmf {

const int N = 1001;
const ll inf = LLONG_MAX;
struct edge { int v, p; ll c, f, w; };
vector<edge> g[N]; int n;
ll dis[N], pot[N];
int vis[N], cur[N];

int addv(int c) {
    while (c--) g[n++].clear();
    return n - 1;
}

void adde(int u, int v, ll c, ll w) {
    g[u].push_back({ v, (int)g[v].size(), c, 0, w });
    g[v].push_back({ u, (int)g[u].size() - 1, c, c, -w });
}

bool dijkstra(int s, int t) {
    typedef pair<ll, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    fill_n(dis, n, inf);
    fill_n(vis, n, 0);
    q.push({ dis[s] = 0, s });
    while (!q.empty()) {
        int u; ll du; tie(du, u) = q.top(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (const edge& e : g[u]) {
            int v = e.v; ll dv = du + e.w + pot[v] - pot[u];
            if (e.c != e.f && dv < dis[v])
                q.push({ dis[v] = dv, v });
        }
    }
    return dis[t] != inf;
}

bool dinic_bfs(int s, int t, ll z) {
    queue<int> q;
    fill_n(vis, n, 0);
    q.push(s); vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (edge e : g[u]) {
            int v = e.v;
            if (vis[v] || e.c - e.f < z) continue;
            if (dis[v] != dis[u] + e.w + pot[v] - pot[u]) continue;
            vis[v] = vis[u] + 1; q.push(v);
        }
    }
    return vis[t] != 0;
}

ll dinic_dfs(int u, int t, ll z, ll df) {
    if (u == t) return df;
    ll sf = 0;
    for (int& i = cur[u]; i != g[u].size(); ++i) {
        edge& e = g[u][i]; int v = e.v;
        if (e.c - e.f < z || vis[v] != vis[u] + 1) continue;
        if (dis[v] != dis[u] + e.w + pot[v] - pot[u]) continue;
        ll f = dinic_dfs(v, t, z, min(e.c - e.f, df));
        sf += f; df -= f; e.f += f; g[v][e.p].f -= f;
        if (!df) break;
    }
    return sf;
}

ll dinic(int s, int t, ll mf) {
    ll sf = 0;
    for (ll z = (1 << 28); z >= 1; z >>= 2) {
        while (dinic_bfs(s, t, z)) {
            fill_n(cur, n, 0);
            ll df = dinic_dfs(s, t, z, mf);
            mf -= df; sf += df;
            if (!mf) break;
        }
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
            if (e.c == e.f || dv >= pot[e.v]) continue;
            pot[e.v] = dv;
            if (!vis[e.v]) q.push(e.v), vis[e.v] = 1;
        }
    }
}

pair<ll, ll> primal_dual(int s, int t, ll mf) {
    ll sf = 0, sc = 0;
    fill_n(pot, n, 0);
    initiate_potential();
    while (dijkstra(s, t)) {
        ll f = dinic(s, t, mf);
        sf += f; sc += (dis[t] - pot[t]) * f;
        for (int i = 0; i < n; ++i) pot[i] -= dis[i];
        if (!mf) break;
    }
    return { sf, sc };
}

}

int main(void) {
    int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t);
    mcmf::n = 0; mcmf::addv(n);
    for (int i = 0; i != m; ++i) {
        int u, v; ll c, w;
        scanf("%d%d%lld%lld", &u, &v, &c, &w);
        
        mcmf::adde(u - 1, v - 1, c, w);
    }
    pair<ll, ll> res = mcmf::primal_dual(s - 1, t - 1, mcmf::inf);
    printf("%lld %lld\n", res.first, res.second);
    return 0;
}