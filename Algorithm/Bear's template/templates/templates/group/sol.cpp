#include <bits/stdc++.h>
using namespace std;
const int S = 8;

typedef vector<int> vi;

vi operator*(vi v1, vi v2) {
    int n = v1.size();
    vi v(n);
    for (int i = 0; i != n; ++i) v[i] = v1[v2[i]];
    return v;
}

vi I(int n) {
    vi v(n);
    iota(v.begin(), v.end(), 0);
    return v;
}

vi R(int n) {
    static mt19937_64 mt(time(0));
    vi y = I(n);
    shuffle(y.begin(), y.end(), mt);
    return y;
}

vi W(int n, vector<vi> w) {
    vi x = I(n);
    for (vi v : w) for (int i = 0; i != v.size(); ++i) {
        x[v[i] - 1] = v[(i+1)%v.size()] - 1;
    }
    return x;
}

ostream& operator<<(ostream& os, vi x) {
    for (int i = 0; i != x.size(); ++i)
        os << x[i] + 1 << " \n"[i + 1 == x.size()];
    return os;
}

vi f = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };

int cexp(vi x) {
    int s = 0, n = x.size();
    for (int i = 0; i != n; ++i) {
        int c = 0;
        for (int j = i + 1; j != n; ++j)
            if (x[j] < x[i]) ++c;
        s += f[n - i - 1] * c;
    }
    return s;
}

set<vi> gen(set<vi> s) {
    set<vi> g = s;
    queue<vi> q;
    for (vi p : g) q.push(p);
    while (!q.empty()) {
        vi u = q.front(); q.pop();
        for (vi w : g) {
            vi v1 = u * w, v2 = w * u;
            if (g.insert(v1).second) q.push(v1);
            if (g.insert(v2).second) q.push(v2);
        }
    }
    return g;
}



int main(int, char** x) {
    int n = atoi(x[1]), l = atoi(x[2]);
    set<vi> s;
    //s.insert(W(10,{ vi{ 1, 2, 3, 4 }, vi { 4, 5, 6, 7 }, vi { 7, 8, 9, 10 }}));
    for (int i = 1; i + l - 1 <= n; ++i) {
        vi v;
        for (int j = i; j <= i + l - 1; ++j)
            v.push_back(j);
        s.insert(W(n, {v}));
    }
    set<vi> g = gen(s);
    cout << g.size() << endl;
    //for (vi x : g) cout << cexp(x) << endl;
    
    return 0;
}