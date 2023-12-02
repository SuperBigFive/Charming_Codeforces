#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

ll qmi(ll a, ll b, ll mod) {
    ll res = 1 % mod;
    while(b) { if(b & 1) res = (LL)res * a % mod; a = (LL)a * a % mod; b >>= 1; }
    return res;
}

ll get_phi(ll x) {
    ll res = x;
    for(ll i = 2; i <= x / i; i ++)
        if(x % i == 0)
        {
            res = res / i * (i - 1);
            while(x % i == 0)   x /= i;
        }
    if(x > 1)   res = res / x * (x - 1);
    return res;
}

bool check(ll a, ll n, ll phi) {
    if(n == 0)  return phi <= 1;
    if(a >= phi)    return true;
    return check(a, n - 1, log(phi) / log(a));
}

ll f(ll a, ll n, ll m) {
    if(m == 1)  return 0;
    if(n <= 1)  return qmi(a, n, m);
    
    ll phi = get_phi(m);
    if(__gcd(a, m) == 1)    return qmi(a, f(a, n - 1, phi), m);
    if(check(a, n - 1, phi))    return qmi(a, f(a, n - 1, phi) + phi, m);
    return qmi(a, f(a, n - 1, phi), m); 
}

int main() {
    ll a, n, m;
    cin >> a >> n >> m;
    cout << f(a, n, m) << endl;
    return 0;
}

