#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

//  Assuming the graph is connected!
namespace stoer_wagner_sparse {

const int N = 1201;
const ll inf = 1145141919810810;
struct edge { int v, p; ll w; };

vector<edge> g[N];
bool vis[N];
ll val[N];
void adde(int u, int v, ll w) {
    g[u].push_back({ v, (int)g[v].size(), w });
    g[v].push_back({ u, (int)g[u].size() - 1, w });
}

void delv(int u, int n) {
    for (edge e : g[u]) {
        int v = e.v;
        if (e.p + 1 != g[v].size()) {
            edge& e2 = g[v].back();
            g[e2.v][e2.p].p = e.p;
            swap(g[v][e.p], e2);
        }
        g[v].pop_back();
    }
}

ll solve(int n) {
    int n0 = n;
    ll ans = inf;
    for (int i = 1, x = 1; i <= n0 - 1; ++i) {
        int s, t; ll tv;
        fill_n(vis + 1, n, 0);
        fill_n(val + 1, n, 0);
        priority_queue<pli> pq; pq.push({ inf, x });
        while (!pq.empty()) {
            pli p = pq.top(); pq.pop();
            int u = p.second;
            if (vis[u]) continue; vis[u] = 1;
            for (edge e : g[u]) if (!vis[e.v])
                pq.push({ val[e.v] += e.w, e.v });
            s = t; t = u; tv = p.first;
        }
        ans = min(ans, tv);
        fill_n(val + 1, n, 0);
        for (edge e : g[s]) val[e.v] += e.w;
        for (edge e : g[t]) val[e.v] += e.w;
        delv(s, n); delv(t, n);
        x = ++n;
        for (int j = 1; j <= n - 1; ++j)
            if (j != s && j != t && val[j])
                adde(x, j, val[j]);
    }
    return ans;
}

}

//  Assuming the graph is connected!
namespace stoer_wagner_dense {

const int N = 1001;
const ll inf = 1145141919810810;
ll g[N][N];
ll val[N]; bool vis[N];

void clear(int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = 0;
}

void adde(int u, int v, int w) {
    g[u][v] += w; g[v][u] += w;
}

ll solve(int n) {
    ll ans = inf;
    while (n > 1) {
        fill_n(val + 1, n, 0);
        fill_n(vis + 1, n, 0);
        int s = -1, t = 1;
        for (int i = 1; i <= n - 1; ++i) {
            vis[t] = 1; int u = 0;
            for (int v = 1; v <= n; ++v) {
                if (vis[v]) continue;
                val[v] += g[t][v];
                if (!u || val[u] < val[v]) u = v;
            }
            s = t; t = u;
        }
        ans = min(ans, val[t]);
        for (int v = 1; v <= n; ++v) {
            g[s][v] += g[t][v];
            g[v][s] += g[v][t];
        }
        for (int i = t; i < n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = g[i + 1][j];
        for (int j = t; j < n; ++j)
            for (int i = 1; i < n; ++i)
                g[i][j] = g[i][j + 1];
        n--;
    }
    return ans;
}

}

int main(void){
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v; ll w; scanf("%d%d%lld", &u, &v, &w);
        stoer_wagner_dense::adde(u, v, w);
    }
    ll res = stoer_wagner_dense::solve(n);
    printf("%lld\n", res);
    return 0;
}