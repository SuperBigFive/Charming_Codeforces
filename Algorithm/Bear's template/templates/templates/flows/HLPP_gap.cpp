//  https://loj.ac/s/1289652;   1275 ms
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1201;
ll inf = LLONG_MAX;
struct edge { int v, p; ll c; };

vector<edge> g[N];
int dis[N], cur[N], cnt[N];
ll ex[N]; 

int maxv;
bool inq[N];
list<int> lst[N];
list<int>::iterator it[N];
void lheap_ins(int u) {
    inq[u] = 1;
    maxv = max(maxv, dis[u]);
    lst[dis[u]].push_front(u);
    it[u] = lst[dis[u]].begin();
}
void lheap_del(int u) {
    inq[u] = 0;
    lst[dis[u]].erase(it[u]);
    it[u] = lst[dis[u]].end();
}
int lheap_top() {
    while (maxv >= 0 && lst[maxv].empty())
        maxv--;
    return maxv < 0 ? -1 : lst[maxv].front();
}


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
    fill_n(cnt, n, 0);
    for (int i = 0; i < n; ++i) cnt[dis[i]]++;
}

ll hlpp(int s, int t, int n) {
    bfs(s, t, n);
    ex[s] = 0; inq[s] = inq[t] = 1;
    for (int i = 0; i < g[s].size(); ++i) {
        push(s, i, inf);
        if (!inq[g[s][i].v])
            lheap_ins(g[s][i].v);
    }

    while (1) {
        int u = lheap_top();
        if (u == -1) break;
        while (cur[u] != g[u].size()) {
            if (dis[u] == dis[g[u][cur[u]].v] + 1 && g[u][cur[u]].c >= 1)
                break;
            ++cur[u];
        }

        if (cur[u] == g[u].size()) {
            cur[u] = 0;
            if (cnt[dis[u]] == 1) {
                int d = dis[u];
                while (1) {
                    int v = lheap_top();
                    if (v == -1 || dis[v] < d) break;
                    lheap_del(v);
                    cnt[dis[v]]--;
                    dis[v] = n;
                }
            }
            else {
                lheap_del(u);
                cnt[dis[u]]--;
                dis[u] = 2 * n - 1;
                for (edge e : g[u]) if (e.c >= 1)
                    dis[u] = min(dis[u], dis[e.v] + 1);
                cnt[dis[u]]++;
                if (dis[u] < n) lheap_ins(u);
            }
        } else {
            push(u, cur[u], ex[u]);
            if (!ex[u]) 
                lheap_del(u);
            if (!inq[g[u][cur[u]].v])
                lheap_ins(g[u][cur[u]].v);
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

    printf("%lld\n", hlpp(s, t, n));

    return 0;
}