#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
typedef pair<int, int> pii;
namespace matching {

vector<int> g[N];
int l[N], c[N], f[N], p[N], m[N], t, n;
int find(int x) { return f[x] ? f[x] = find(f[x]) : x; }
int lca(int x, int y) {
    for(++t; ; x = p[l[x]], swap(x, y)) {
        if (m[x = find(x)] == t) return x;
        else m[x] = x ? t : 0;
    }   
}
void blossom(int x, int y, int z, queue<int>& q) {
    for (; find(x) != z; x = p[y]) {
        p[x] = y; y = l[x]; f[x] = f[y] = z;
        if (c[y] == 2) q.push(y), c[y] = 1;
    }
}
void bfs(int s) {
    for (int i = 1; i <= n; ++i)
        c[i] = f[i] = m[i] = p[i] = 0;
    queue<int> q; q.push(s); c[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (c[v] == 2) continue;
            if (c[v] == 1) {
                int w = lca(u, v);
                blossom(u, v, w, q);
                blossom(v, u, w, q);                
            }
            else if (l[v]) {
                c[v] = 2; c[l[v]] = 1;
                p[v] = u; q.push(l[v]);
            }
            else {
                p[v] = u;
                for (int x = v, y; x; x = y)
                    y = l[p[x]], l[x] = p[x], l[p[x]] = x;
                return;
            }
        }
    }
}
vector<pii> match(int n0, const vector<pii>& es) {
    n = n0;
    fill_n(l + 1, n, 0);
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (pii e : es) {
        int x = e.first, y = e.second;
        g[x].push_back(y); g[y].push_back(x);
        if (!l[x] && !l[y]) l[x] = y, l[y] = x;
    }
    for (int i = 1; i <= n; ++i) if (!l[i]) bfs(i);
    vector<pii> res;
    for (int i = 1; i <= n; ++i) if (i < l[i])
        res.emplace_back(i, l[i]);
    return res;
}

}

int main(void) {
    int n, m; scanf("%d %d", &n, &m);
    vector<pii> es;
    for (int i = 1; i <= m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        es.emplace_back(x, y);
    }
    matching::match(n, es);
    return 0;
}