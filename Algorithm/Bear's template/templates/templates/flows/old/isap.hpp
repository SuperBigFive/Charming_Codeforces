#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = LLONG_MAX;
const int N = 50005;

struct edge { int u, v; ll c; };

namespace capacityscaling_isap {

struct arc { int v, p; ll c; };
vector<arc> g[N]; int n;
int dis[N], cur[N], gap[N];

int addv(int cnt) {
    while (cnt--) g[n++].clear();
    return n - 1;
}

void adde(int u, int v, ll c) {
    g[u].push_back({ v, (int)g[v].size(), c });
    g[v].push_back({ u, (int)g[u].size() - 1, 0 });
}

ll dfs(int u, int s, int t, ll f) {
    if (u == t) return f;
    ll sf = 0;
    for (int& i = cur[u]; i < g[u].size(); ++i) {
        arc& e = g[u][i]; int v = e.v;
        if (!e.c || dis[u] != dis[v] + 1) continue;
        ll df = dfs(v, s, t, min(e.c, f));
        e.c -= df; f -= df; sf += df; g[v][e.p].c += df;
        if (!f) break;
    }
    int nd = INT_MAX;
    for (const arc& e : g[u]) if (e.c) nd = min(nd, dis[e.v] + 1);
    cur[u] = 0;
    if (!--gap[dis[u]]) dis[s] = n;
    if (nd != INT_MAX)
        ++gap[dis[u] = nd];
    return sf;
}

ll maxflow(int s, int t, ll mf) {
    fill_n(dis, n, -1);
    fill_n(cur, n, 0);
    fill_n(gap, n, 0);
    queue<int> q; q.push(t); dis[t] = 0; gap[0] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const arc& e : g[u]) {
            if (dis[e.v] != -1 || e.c) continue;
            ++gap[dis[e.v] = dis[u] + 1];
            q.push(e.v);
        }
    }
    ll sf = 0;
    while (sf < mf && dis[s] < n) 
        sf += dfs(s, s, t, mf - sf);
    return sf;
}

}