#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int> g[N];
int dfn[N], low[N], bel[N], dfc, scc;
int dfs_scc(int u) {
    static int s[N], t;
    static bool ins[N];
    s[++t] = u; ins[u] = 1;
    dfn[u] = low[u] = ++dfc;
    for (int v : g[u]) {
        if (!dfn[v]) low[u] = min(low[u], dfs_scc(v));
        else if (ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++scc;
        int v;
        do {
            v = s[t--];
            bel[v] = scc;
            ins[v] = 0;
        } while (v != u);
    }
    return low[u];
}

int main(void) {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) dfs_scc(i);

    for (int i = 1; i <= n; ++i)
        printf("%d%c", bel[i], " \n"[i == n]);

    return 0;
}