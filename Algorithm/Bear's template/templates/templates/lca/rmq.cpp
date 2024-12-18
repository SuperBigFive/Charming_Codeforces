#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
typedef long long ll;
struct edge { int v, w; };
vector<edge> g[N];

template<class T>
struct RMQ {
    int n;
    vector<int> l2;
    vector<vector<T>> s;

    template<class It>
    void build(int n_, It a) {
        n = n_; l2.assign(n + 1, 0); s.clear();
        for (int i = 2; i <= n; ++i) l2[i] = l2[i >> 1] + 1;
        for (int i = 0; i <= l2[n]; ++i) {
            s.emplace_back(n - (1 << i) + 1);
            if (!i) copy_n(a, n, s[i].begin());
            else for (int j = 0; j < s[i].size(); ++j)
                s[i][j] = min(s[i - 1][j], s[i - 1][j + (1 << i - 1)]);
        }
    }

    T query(int l, int r) {
        if (l > r) swap(l, r);
        r++; int w = l2[r - l];
        return min(s[w][l], s[w][r - (1 << w)]);
    }
};


struct LCA {
    vector<int> pos, dep;
    vector<ll> dis;
    typedef pair<int, int> pii;
    RMQ<pii> rmq;
    void dfs(const vector<edge>* g, vector<pii>& et, int u, int f, ll w) {
        dep[u] = dep[f] + 1;
        dis[u] = dis[f] + w;
        et.emplace_back(dep[u], u);
        pos[u] = et.size() - 1;
        for (edge e : g[u]) if (e.v != f)
            dfs(g, et, e.v, u, e.w),
            et.emplace_back(dep[u], u);
    }

    void build(const vector<edge>* g, int n, int r = 1) {
        dep.assign(n + 1, 0);
        dis.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        vector<pii> et;
        dfs(g, et, r, 0, 0);
        rmq.build(et.size(), et.begin());
    }

    pii query(int u, int v) {
        return rmq.query(pos[u], pos[v]);
    }
};

int main(void) {



    return 0;
}