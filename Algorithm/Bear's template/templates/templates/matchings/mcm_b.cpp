#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
typedef pair<int, int> pii;
namespace matching {

vector<int> g[N];
int l[N], c[N], p[N], d[N], n;
bool bfs() {
    for (int i = 1; i <= n; ++i) p[i] = d[i] = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (c[i] == 1 && !l[i]) q.push(i), d[i] = 1;
    bool fail = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (d[v]) continue;
            d[v] = l[u] ? d[l[u]] : u;
            p[v] = u;
            if (l[v])
                d[l[v]] = d[u] + 1, q.push(l[v]);
            else if (d[d[v]] == 1) {
                fail = 0;
                for (int x = v, y; x; x = y)
                    y = l[p[x]], l[x] = p[x], l[p[x]] = x;
                d[d[v]] = 0;
            }
        }
    }
    return !fail;
}

vector<pii> match(int n1, int n2, const vector<pii>& es) {
    n = n1 + n2;
    for (int i = 1; i <= n; ++i) {
        g[i].clear(); l[i] = 0;
        c[i] = (i <= n1 ? 1 : 2);
    }
    for (pii e : es) {
        int u = e.first, v = e.second;
        v += n1;
        g[u].push_back(v);
        g[v].push_back(u);
        if (!l[u] && !l[v])
            l[u] = v, l[v] = u;
    }
    while (bfs());
    vector<pii> res;
    for (int i = 1; i <= n1; ++i)
        if (l[i]) res.emplace_back(i, l[i] - n1);
    return res;
}


}

int main(void) {
    int n1, n2, m; scanf("%d %d %d", &n1, &n2, &m);
    vector<pii> es;
    for (int i = 1; i <= m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        es.emplace_back(u, v);
    }
    matching::match(n1, n2, es);
    return 0;
}