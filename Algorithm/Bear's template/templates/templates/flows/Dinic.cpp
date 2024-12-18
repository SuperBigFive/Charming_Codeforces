#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1201;
ll inf = LLONG_MAX;
struct edge { int v, p; ll c; };

vector<edge> g[N];
int dis[N], cur[N], pv[N], pe[N];

void adde(int u, int v, ll c) {
    g[u].push_back({ v, (int)g[v].size(), c });
    g[v].push_back({ u, (int)g[u].size() - 1, 0 });
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
}

ll dinic(int s, int t, int n) {
    ll f = 0;
    while (1) {
        bfs(s, t, n);
        if (dis[s] >= n) break;

        fill_n(cur, n, 0);
        pv[s] = -1;
        for (int u = s; u != -1;) {
            if (u == t) {
                ll df = inf;
                for (int v = u; v != s; v = pv[v])
                    df = min(df, g[pv[v]][pe[v]].c);
                for (int v = u; v != s; v = pv[v]) {
                    g[pv[v]][pe[v]].c -= df;
                    g[v][g[pv[v]][pe[v]].p].c += df;
                }

                f += df;
                u = s;
            }
            while (cur[u] != g[u].size()) {
                edge e = g[u][cur[u]];
                if (dis[u] == dis[e.v] + 1 && e.c >= 1 && cur[e.v] != g[e.v].size())
                    break;
                ++cur[u];
            }

            if (cur[u] == g[u].size())
                u = pv[u];
            else {
                int v = g[u][cur[u]].v;
                pv[v] = u;
                pe[v] = cur[u];
                u = v;
            }
        }
    }
    return f;
}

int main(void) {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    s--;
    t--;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--;
        v--;
        adde(u, v, c);
    }

    printf("%lld\n", dinic(s, t, n));

    return 0;
}