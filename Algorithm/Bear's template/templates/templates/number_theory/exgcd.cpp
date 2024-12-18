#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll exgcd(ll a, ll b, ll& u, ll& v) {
    ll d;
    if (b) d = exgcd(b, a % b, v, u), v -= (a / b) * u;
    else d = a, u = 1, v = 0;
    printf("%lld*%lld+%lld*%lld=%lld\n", a, u, b, v, d);
    return d;
}

int main(void) {
    ll a, b;
    while (~scanf("%lld %lld", &a, &b)) {
        ll u, v;
        exgcd(a, b, u, v);
    }

    return 0;
}