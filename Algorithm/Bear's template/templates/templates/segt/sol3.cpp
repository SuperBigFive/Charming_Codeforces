#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT {
    vector<ll> a, b; int n;
    BIT(int m) : n(m + 2), a(m + 2, 0), b(m + 2, 0) {}
    void m(int x, int v) { for (ll w=1ll*x*v; x<=n-1;x+=x&-x) a[x]+=v,b[x]+=w; }
    ll q(int x) { ll u=0,v=0,k=x+1; for (; x; x-=x&-x) u+=a[x], v+=b[x]; return u*k-v; }
    void modify(int l, int r, int v) { m(l, v); m(r+1,-v); }
    ll query(int l, int r) { return q(r) - q(l - 1);}
};

int main(void) {
    int n, q; scanf("%d %d", &n, &q);
    BIT bit(n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        bit.modify(i, i, x);
    }
    while (q--) {
        int o; scanf("%d", &o);
        if (o == 1) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            bit.modify(l, r, x);            
        }
        else if (o == 2) {
            int l, r; scanf("%d %d", &l, &r);
            ll sum = bit.query(l, r);
            printf("%lld\n", sum);
        }
    }

    return 0;
}