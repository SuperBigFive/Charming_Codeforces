#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

namespace blossom {

const int N = 1001;
vector<int> g[N], h[N];
int l[N], d[N], p[N], f[N], n;
bool e[N];

int bfs(int s) {
    while (f[s]) s = f[s];
    //printf("%d\n", s);
    if (l[s]) return 0;
    queue<int> q;
    fill_n(d + 1, n, -1);
    fill_n(p + 1, n, 0);
    fill_n(e + 1, n, 0);
    q.push(s); d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (e[v]) continue;
            if (d[v] == -1) {
                d[v] = d[u] + 1; p[v] = u;
                int w = l[v];
                if (!w) {
                    do {
                        w = p[v];
                        l[v] = w;
                        l[w] = v;
                    } while (v = p[w]);
                    // for (int i = 1; i <= n; ++i)
                    //     printf("%d%c", l[i], " \n"[i == n]);
                    // fflush(stdout);
                    return 1;
                }
                assert(d[w] == -1);
                d[w] = d[v] + 1; p[w] = v;
                q.push(w);
            }
            else if (d[v] % 2 == 0) {
                int b = ++n; h[b].clear(); e[b] = 0;
                for (int i = u; i; i = p[i]) e[i] ^= 1;
                for (int i = v; i; i = p[i]) e[i] ^= 1;
                int i = u;
                while (e[i]) h[b].push_back(i), i = p[i];
                reverse(h[b].begin(), h[b].end());
                int j = v;
                while (e[j]) h[b].push_back(j), j = p[j];
                h[b].push_back(j); e[j] = 1;
                if (l[j]) l[b] = l[j], l[l[j]] = b;
                // printf("Contract to %d with w=%d:", b, j);
                // for (int w : h[b])
                //     printf(" %d", w);
                // printf("\n");
                
                
                for (int w : h[b]) {
                    f[w] = b;
                    for (int x : g[w])
                        if (!e[x] && g[x].back() != b) {
                        g[x].push_back(b);
                        g[b].push_back(x);
                        //printf("New edge %d %d\n", x, b);
                    }
                }
                // for (int i = 1; i <= n; ++i) {
                //     printf("%d:", i);
                //     for (int j : g[i])
                //         printf(" %d", j);
                //     printf("\n");
                // }
                // printf("\n");
                //fflush(stdout);
                return -1;
            }
        }
    }
    return 0;
}

vector<pii> match(const vector<pii>& es) {
    n = 0;
    for (pii e : es) n = max(n, max(e.first, e.second));
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (pii e : es) {
        int u, v; tie(u, v) = e;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fill_n(l + 1, n, 0);
    fill_n(e + 1, n, 0);
    int n0 = n, cnt = 0;
    for (int u = 1; u <= n; ++u) {
        while (bfs(u) == -1);
        while (n != n0) {
            int b = n;
            if (l[b]) {
                bool fail = true;
                int i = -1;
                while (fail) {
                    int u = h[b][++i];
                    for (int v : g[u]) if (v == l[b]) fail = false;
                }
                rotate(h[b].begin(), h[b].begin() + i, h[b].end());
                int w = h[b].front();
                l[w] = l[b];
                l[l[b]] = w;
                for (int i = 1; i != h[b].size(); i += 2) {
                    int u = h[b][i], v = h[b][i + 1];
                    l[u] = v; l[v] = u;
                }
            }
            for (int u : g[b]) {
                assert(g[u].back() == b);
                g[u].pop_back();
                f[u] = 0;
            }
            g[b].clear();
            h[b].clear();
            l[b] = p[b] = d[b] = e[b] = f[b] = 0;
            --n;
        }
    }
    
    vector<pii> res;
    for (int i = 1; i <= n0; ++i) {
        if (!l[i]) continue;
        assert(l[l[i]] == i);
        assert(l[i] != i);
        if (l[i] > i) res.emplace_back(i, l[i]);
    }
    // for (pii p : res)
    //     printf("%d %d\n", p.first, p.second);
    printf("%d\n", (int)res.size());
    for (int i = 1; i <= n0; ++i)
        printf("%d%c", l[i], " \n"[i == n0]);
    return res;
}

}

int main(void) {
    int n, m; scanf("%d%d", &n, &m);
    vector<pii> es;
    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        es.emplace_back(u, v);
    }
    blossom::match(es);

    return 0;
}