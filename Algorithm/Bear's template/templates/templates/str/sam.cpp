#include <bits/stdc++.h>
using namespace std;

const int N = 2000001;

namespace SAM {
int g[N][26], f[N], l[N], nc;
int split(int p, int o) {
    int q = g[p][o]; if (l[p] + 1 == l[q]) return q;
    int nq = ++nc; l[nq] = l[p] + 1;
    copy_n(g[q], 26, g[nq]); f[nq] = f[q]; f[q] = nq;
    for (; p && g[p][o] == q; p = f[p]) g[p][o] = nq;
    return nq;
}
int extend(int r, int p, int o) {
    //  if (g[p][o]) return split(p, o);
    int np = ++nc; l[np] = l[p] + 1;
    fill_n(g[np], 26, 0);
    for (; p && g[p][o] == 0; p = f[p]) g[p][o] = np;
    f[np] = p ? split(p, o) : r;
    return np;
}
}

char s[N];

int main(void) {
    int n; scanf("%d", &n);
    int r = SAM::nc = 1;
    while (n--) {
        scanf("%s", s);
        int p = r;
        for (int i = 0; s[i]; ++i)
            p = SAM::extend(r, p, s[i] - 'a');
    }
    long long sum = 0;
    for (int i = 1; i <= SAM::nc; ++i)
        sum += SAM::l[i] - SAM::l[SAM::f[i]];
    printf("%lld\n", sum);
    return 0;
}