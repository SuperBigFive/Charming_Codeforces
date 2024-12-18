#include <bits/stdc++.h>
 
#define N 200
#define ffirst(s) (s)._Find_first()
#define fnext(s, i) (s)._Find_next(i)
#define for_(i, n, s) for (int i = ffirst((s)); i < n; i = fnext((s), i))
using namespace std;
 
typedef bitset<N> bs;
 
bs g[N];
 
bs msk(int n) {
    bs b;
    for (int i = 0; i != n; ++i)
        b[i] = 1;
    return b;
}
 
bs max(bs b1, bs b2) { return b1.count() < b2.count() ? b2 : b1; }
 
bs mis(bs s, bs c, int n) {
    if (c.none()) return s;
    int dm = -1, v;
    for_(u, n, c) {
        bs t = g[u] & c;
        int d = t.count();
        if (d == 0) return mis(s.set(u), c.reset(u), n);
        if (d == 1) return mis(s.set(u), c.reset(u).reset(ffirst(t)), n);
        if (d > dm) dm = d, v = u;
    }
    if (dm == 2) {
        for_(u, n, c) {
            int sz = 0;
            for (v = u; v < n; ++sz) {
                if (sz & 1) s[v] = 1;
                v = ffirst(g[v] & c.reset(v));
            }
        }
        return s;
    }
    else {
        c.reset(v);
        bs e = mis(s, c, n);
        s.set(v);
        return max(e, mis(s, c & ~g[v], n));
    }
}
 


int main(void) {
    int n, m; scanf("%d %d", &n, &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        u--; v--;
        g[u][v] = g[v][u] = 1;
    }
    
    bs res = mis(bs(), msk(n), n);
    bs t;
    for (int i = 0; i != n; ++i)
        if (res[i])
            assert((res & g[i]).none());
    for (int i = 0; i < n; ++i)
        if (res[i]) 
            cout << i + 1 << ' ';
    cout << endl;
    return 0;
}