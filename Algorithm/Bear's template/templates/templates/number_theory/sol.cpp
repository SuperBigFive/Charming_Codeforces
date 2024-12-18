#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p = 1000000009;
inline int add(int a, int b) { a += b; return a < p ? a : a - p; }
inline int sub(int a, int b) { a -= b; return a < 0 ? a + p : a; }
inline int mul(int a, int b) { return 1ll * a * b % p; }
inline int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}

typedef pair<int, int> pii;
const int d = 11;
pii add(pii a, pii b) { return { add(a.first, b.first), add(a.second, b.second) }; }
pii sub(pii a, pii b) { return { sub(a.first, b.first), sub(a.second, b.second) }; }
pii mul(pii a, pii b) {
    return { add(mul(a.first, b.first), mul(d, mul(a.second, b.second))), add(mul(a.second, b.first), mul(a.first, b.second)) };
}

pii qpm(pii a, ll b) {
    pii r = { 1, 0 };
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}

int main(void) {
    int a, b;
    while (cin >> a >> b) {
        pii r = qpm({ a, b }, 2 * p);
        cout << r.first << ' ' << r.second << endl;
    }
    return 0;
}