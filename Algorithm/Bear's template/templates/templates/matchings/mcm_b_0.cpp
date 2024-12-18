#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<int> g[N];
bool vis[N]; int lnk[N];
bool ff[N];

bool dfs(int u) {
    vis[u] = 1;
    for (int v : g[u])
        if (!lnk[v] || (!vis[lnk[v]] && dfs(lnk[v])))
            return lnk[v] = u;
    return false;
}

int main(void) {
    int n1, n2, m; scanf("%d %d %d", &n1, &n2, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        g[v].push_back(u);
        if (!lnk[u] && !ff[v])
            lnk[u] = v, ff[v] = 1;
    }

    for (int i = 1; i <= n2; ++i) {
        if (ff[i]) continue;
        fill_n(vis + 1, n2, 0);
        dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= n1; ++i)
        if (lnk[i]) ans++;
    printf("%d\n", ans);
    for (int i = 1; i <= n1; ++i)
        printf("%d%c", lnk[i], " \n"[i == n1]);

    return 0;
}