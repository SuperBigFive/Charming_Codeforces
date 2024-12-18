#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = LLONG_MAX;
const int N = 50005;

struct edge { int u, v; ll c; };

namespace capacityscaling_dinic {

struct arc { int v, p; ll c; };
vector<arc> g[N]; int n;
int dis[N], cur[N];

bool bfs(int s, int t) {
    queue<int> q; fill_n(dis, n, 0);
    q.push(t); dis[t] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const arc& e : g[u]) {
            int v = e.v;
            if (dis[v] || !g[e.v][e.p].c) continue;
            dis[v] = dis[u] + 1; q.push(v);
        }
    }
    return dis[s] != 0;
}

ll dfs(int u, int t, ll df) {
    if (u == t) return df;
    ll sf = 0;
    for (int& i = cur[u]; i != g[u].size(); ++i) {
        arc& e = g[u][i]; int v = e.v;
        if (!e.c || dis[v] + 1 != dis[u]) continue;
        ll f = dfs(v, t, min(e.c, df));
        sf += f; df -= f; e.c -= f; g[v][e.p].c += f;
        if (!df) break;
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

ll maxflow(int n_, vector<edge> es, int s, int t, ll mf) {
    n = n_;
    ll sf = 0;
    sort(es.begin(), es.end(), [&](edge e1, edge e2) { return e1.c > e2.c; });
    auto it = es.begin();
    for (ll z = 1ll << 28; z >= 1; z >>= 2) {
        while (it != es.end() && it->c >= z) {
            g[it->u].push_back({ it->v, (int)g[it->v].size(), it->c});
            g[it->v].push_back({ it->u, (int)g[it->u].size() - 1, 0 });
            ++it;
        }
        ll f = maxflow(s, t, mf);
        sf += f; mf -= f;
        if (!mf) break;
    }
    return sf;
}

}


int main(void) {
    int n, m; scanf("%d%d", &n, &m);
    int s, t; scanf("%d%d", &s, &t); s--; t--;

    vector<edge> es;
    for (int i = 1; i <= m; ++i) {
        int u, v; ll c; scanf("%d%d%lld", &u, &v, &c);
        u--; v--;
        es.push_back({ u, v, c });
    }

    ll res = capacityscaling_isap::maxflow(n, es, s, t, inf);
    printf("%lld\n", res);

    return 0;
}