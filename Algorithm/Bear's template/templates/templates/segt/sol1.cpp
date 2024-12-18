#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000001;
ll a[N]; int n;

void modify(int i, ll x) {
    for (int w = i; w <= n; w += w & -w)
        a[w] += x;
}

ll query(int i) {
    ll sum = 0;
    for (int w = i; w; w -= w & -w)
        sum += a[w];
    return sum;
}

int main(void) {
    int q; scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        modify(i, x);
    }
    while (q--) {
        int o; scanf("%d", &o);
        if (o == 1) {
            int i, x; scanf("%d %d", &i, &x);
            modify(i, x);
        }
        else if (o == 2) {
            int l, r; scanf("%d %d", &l, &r);
            ll sum = query(r) - query(l - 1);
            printf("%lld\n", sum);
        }
    }

    return 0;
}