//  https://loj.ac/s/1289650; 1790 ms
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1201;
ll inf = LLONG_MAX;
struct edge { int v, p; ll c; };

vector<edge> g[N];
int dis[N], cur[N];
ll ex[N]; 

bool inq[N];

void adde(int u, int v, ll c) {
    g[u].push_back({ v, (int)g[v].size(), c });
    g[v].push_back({ u, (int)g[u].size() - 1, 0 });
}

void push(int u, int i, ll df) {
    edge &e = g[u][i];
    df = min(df, e.c);
    if (df == 0) return;
    e.c -= df; ex[u] -= df;
    g[e.v][e.p].c += df;ex[e.v] += df;
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
    dis[s] = n;
}

ll fifopp(int s, int t, int n) {
    queue<int> q;
    bfs(s, t, n);
    ex[s] = 0; inq[s] = inq[t] = 1;
    for (int i = 0; i < g[s].size(); ++i) {
        push(s, i, inf);
        if (!inq[g[s][i].v])
            q.push(g[s][i].v), inq[g[s][i].v] = 1;
    }
    
    while (!q.empty()) {
        int u = q.front();

        while (cur[u] != g[u].size()) {
            if (dis[u] == dis[g[u][cur[u]].v] + 1 && g[u][cur[u]].c >= 1)
                break;
            ++cur[u];
        }

        if (cur[u] == g[u].size()) {
            cur[u] = 0;
            q.pop();
            dis[u] = 2 * n - 1;
            for (edge e : g[u]) if (e.c >= 1)
                dis[u] = min(dis[u], dis[e.v] + 1);
            if (dis[u] < n) q.push(u);
        } else {
            push(u, cur[u], ex[u]);
            if (!ex[u]) 
                q.pop(), inq[u] = 0;
            if (!inq[g[u][cur[u]].v])
                q.push(g[u][cur[u]].v), inq[g[u][cur[u]].v] = 1;
        }
    }
    return ex[t];
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

    printf("%lld\n", fifopp(s, t, n));

    return 0;
}