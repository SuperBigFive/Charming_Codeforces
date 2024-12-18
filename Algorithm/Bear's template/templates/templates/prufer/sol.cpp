#include <bits/stdc++.h>
using namespace std;

vector<int> encode(const vector<vector<int>>& g) {
    const int n = g.size();
    vector<int> res, deg(n);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
        if (deg[i] == 1)
            q.push(i);
    }
    for (int i = 0; i < n - 2; ++i) {
        int u = q.top(); q.pop();
        int z = -1;
        deg[u]--;
        for (int v : g[u]) {
            if (deg[v] == 0)
                continue;
            deg[v]--;
            assert(z == -1);
            z = v;
        }
        assert(z != -1);
        if (deg[z] == 1)
            q.push(z);
        res.push_back(z);
    }
    return res;
}

vector<vector<int>> decode(vector<int> a) {
    int n = a.size() + 2;
    vector<int> cnt(n, 0);
    for (int i : a) cnt[i]++;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i)
        if (cnt[i] == 0) q.push(i);
    vector<vector<int>> g(n);
    for (int i = 0; i < a.size(); ++i) {
        int u = a[i], v = q.top(); q.pop();
        g[u].push_back(v);
        g[v].push_back(u);
        if (!--cnt[u])
            q.push(u);
    }
    int u = q.top(); q.pop();
    int v = q.top(); q.pop();
    g[u].push_back(v);
    g[v].push_back(u);
    return g;
}

typedef pair<int, int> pii;
mt19937_64 mt(123);//chrono::system_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(mt); }

int main(void) {
    const int n = 114514;
    while (1) {
        set<pii> es;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            int j = rnd(0, i - 1);
            g[i].push_back(j);
            g[j].push_back(i);
        }
        vector<int> b = encode(g);
        vector<vector<int>> h = decode(b);
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end());
            sort(h[i].begin(), h[i].end());
        }
        if (h == g)
            cout << "AC" << endl;
        else {
            for (int i = 0; i < n; ++i)
                for (int v : g[i])
                    if (i < v)
                        cout << i << ' ' << v << endl;
            for (int i = 0; i < n - 2; ++i)
                cout << b[i] << ' ';
            cout << endl;
            for (int i = 0; i < n; ++i)
                for (int v : h[i])
                    if (i < v)
                        cout << i << ' ' << v << endl;
        }
    }
    return 0;
}