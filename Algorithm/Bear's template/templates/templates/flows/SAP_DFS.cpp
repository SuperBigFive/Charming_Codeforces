#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1201;
ll inf = LLONG_MAX;
struct edge { int v, p; ll c; };

vector<edge> g[N];
int dis[N], cur[N], cnt[N];

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

ll dfs(int s, int t, int n, int u, ll f, ll del) {
    if (u == t) return f;
    ll sf = 0;
    do {
        for (int& i = cur[u]; i < g[u].size(); ++i) {
            edge& e = g[u][i];
            if (dis[u] != dis[e.v] + 1 || e.c < del) continue;
            ll df = dfs(s, t, n, e.v, min(e.c, f), del);
            e.c -= df; f -= df;
            g[e.v][e.p].c += df; sf += df;
            if (!f) return sf;
        }
        cur[u] = 0;
        if (!--cnt[dis[u]]) return dis[s] = n, sf;
        dis[u] = n;
        for (edge e : g[u]) if (e.c >= del) dis[u] = min(dis[u], dis[e.v] + 1);
        ++cnt[dis[u]];
    } while (u == s && dis[s] < n);
    return sf;
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
    ll sf = 0;
    for (ll del = 1 << 28; del >= 1; del >>= 1) {
        bfs(s, t, n, del);
        sf += dfs(s, t, n, s, inf, del);
    }

    printf("%lld\n", sf);

    return 0;
}