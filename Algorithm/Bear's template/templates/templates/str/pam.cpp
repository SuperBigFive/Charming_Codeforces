#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500005;
namespace PAM {
char s[N];
int g[N][26], f[N], l[N], nc;
int d[N], t[N];

int gn(int len) {
    int p = nc++; l[p] = len; f[p] = 0;
    fill_n(g[p], 26, 0);
    return p;
}

void init() {
    nc = 0; gn(0); gn(-1);
    f[0] = 1; f[1] = -1;
}

int gf(int p, int i) {
    while (s[i] != s[i - l[p] - 1]) p = f[p];
    return p;
}


int extend(int p, int o, int i) {
    s[i] = o + 'a'; p = gf(p, i);
    int& q = g[p][o];
    if (!q) {
        q = gn(l[p] + 2);
        if (p != 1) f[q] = g[gf(f[p], i)][o];
        d[q] = l[q] - l[f[q]];
        t[q] = d[f[q]] == d[q] ? t[f[q]] : f[q];
    }
    for (int r = q; r > 1; r = t[r]) {
        
    }
    return q;
}


}
