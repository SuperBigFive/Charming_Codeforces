#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = LLONG_MAX;
const int N = 50005;

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