#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
typedef int ll;
typedef pair<int, int> pii;
const int inf = INT_MAX;

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