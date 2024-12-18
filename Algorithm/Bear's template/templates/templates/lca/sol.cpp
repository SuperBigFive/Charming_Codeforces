#include <bits/stdc++.h>
#include <cctype>
using namespace std;

namespace io {

    const int S = 1<<24;
    char s[S], *t, *p;

    bool get() { t = s + fread(s, 1, S, stdin); p = s; return s != t; }
    bool eof() { return p == t && !get(); }
    char getc(int c = 1) { if (eof()) return -1; while (--c) ++p; return *p++; }
    void skip() { while (!isgraph(getc())); p--;}

    template<class T>
    void readi(T& i) {
        skip(); i = 0; char ch = getc(); bool neg = (ch == '-');
        if (neg) ch = getc();
        for (; isdigit(ch); ch = getc()) i = 10 * i + (ch - '0');
        if (neg) i = -i;
    }

    int readl(char* s) {
        int n = 0; while ((*s++ = getc()) != '\n') ++n;
        return n;
    }

}

using io::readi;

template<class T>
struct RMQ {
    int n;
    vector<int> l2;
    vector<vector<T>> s;

    template<class It>
    void build(int n_, It a) {
        n = n_; l2.assign(n + 1, 0);
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
    typedef pair<int, int> pii;
    RMQ<pii> rmq;
    void dfs(const vector<int>* g, vector<pii>& et, int u, int f) {
        dep[u] = dep[f] + 1;
        et.emplace_back(dep[u], u);
        pos[u] = et.size() - 1;
        for (int v : g[u]) if (v != f)
            dfs(g, et, v, u),
            et.emplace_back(dep[u], u);
    }

    void build(const vector<int>* g, int n, int r = 1) {
        dep.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        vector<pii> et;
        dfs(g, et, r, 0);
        rmq.build(et.size(), et.begin());
    }

    pii query(int u, int v) {
        return rmq.query(pos[u], pos[v]);
    }
};

const int N = 500001;
vector<int> g[N];

int main(void) {
    int n, m, r;
    readi(n);
    readi(m);
    readi(r);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; readi(u); readi(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCA lca;
    lca.build(g, n, r);

    while (m--) {
        int u, v;
        readi(u);
        readi(v);
        printf("%d\n", lca.query(u, v).second);
    }


    return 0;
}