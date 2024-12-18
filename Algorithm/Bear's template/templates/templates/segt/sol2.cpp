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
        modify(i + 1, -x);
    }
    while (q--) {
        int o; scanf("%d", &o);
        if (o == 1) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            modify(l, x);
            if (r < n) modify(r + 1, -x);            
        }
        else if (o == 2) {
            int i; scanf("%d", &i);
            ll sum = query(i);
            printf("%lld\n", sum);
        }
    }

    return 0;
}