#include <bits/stdc++.h>
using namespace std;


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

//  Tonelli-Shanks's algorithm. O(log^2n). 1s-5e5
inline int msqrt_ts(int x) {
    if (!x) return 0;
    if (qpm(x, (p - 1) / 2) != 1) return -1;
    if (p % 4 == 3) return qpm(x, (p + 1) / 4);
    int z = 2; while (qpm(z, (p - 1) / 2) == 1) ++z;
    const int s = __builtin_ctz(p - 1), q = (p - 1) >> s;
    int r = qpm(x, (q + 1) / 2), t = qpm(x, q);
    z = qpm(z, q);
    for (int i = 1; i < s; ++i) {
        int y = mul(z, z);
        if (qpm(t, 1 << (s - i - 1)) != 1)
            t = mul(t, y), r = mul(r, z);
        z = y;
    }
    return r;
}

//  Cipolla's Algorithm 1s~1e6
pair<int, int> mul(int a1, int a2, int b1, int b2, int t) {
    return { add(mul(a1, b1), mul(t, mul(a2, b2))), add(mul(a1, b2), mul(a2, b1)) };
}
inline int msqrt_cp(int x) {
    if (!x) return 0;
    if (qpm(x, (p - 1) / 2) != 1) return -1;
    if (p % 4 == 3) return qpm(x, (p + 1) / 4);
    int z = 2, t; while (qpm(t = sub(mul(z, z), x), (p - 1) / 2) == 1) ++z;
    int a1 = z, a2 = 1, b = (p + 1) / 2, r1 = 1, r2 = 0;
    do if (b & 1) tie(r1, r2) = mul(r1, r2, a1, a2, t);
    while (tie(a1, a2) = mul(a1, a2, a1, a2, t), b >>= 1);
    return r1;
}

int main(void) {
    //p = 1000000009;
    auto ts = clock();
    int t; scanf("%d", &t);
    uniform_int_distribution<int> uid(1, p - 1);
    mt19937_64 mt(time(0));
    while (t--) {
        printf("%d\n", msqrt_ts(uid(mt)));
    }
    fprintf(stderr, "%d\n", (int)(clock() - ts));
    return 0;
}