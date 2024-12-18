#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
