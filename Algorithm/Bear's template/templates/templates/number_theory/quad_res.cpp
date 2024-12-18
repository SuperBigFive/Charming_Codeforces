#include <bits/stdc++.h>
using namespace std;

int p = 167772161;
inline int add(int a, int b) { a += b; return a < p ? a : a - p; }
inline int sub(int a, int b) { a -= b; return a < 0 ? a + p : a; }
inline int mul(int a, int b) { return 1ll * a * b % p; }
inline int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}

//  Tonelli-Shanks's algorithm. O(log^2p). 1s-1e6 if p is const, 1s-3e5 otherwise.
int msqrt_ts(int x) {
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

//  Cipolla's algorithm. O(logn). 1s-2.5e6 if p is const, 1s-7e5 otherwise
inline pair<int, int> mul(int a1, int a2, int b1, int b2, int t) {
    return { add(mul(a1, b1), mul(t, mul(a2, b2))), add(mul(a1, b2), mul(a2, b1)) };
}
int msqrt_cp(int x) {
    if (!x) return 0;
    if (qpm(x, (p - 1) / 2) != 1) return -1;
    if (p % 4 == 3) return qpm(x, (p + 1) / 4);
    int z = 2, t; while (qpm(t = sub(mul(z, z), x), (p - 1) / 2) == 1) ++z;
    int a1 = z, a2 = 1, b = (p + 1) / 2, r1 = 1, r2 = 0;
    do if (b & 1) tie(r1, r2) = mul(r1, r2, a1, a2, t);
    while (tie(a1, a2) = mul(a1, a2, a1, a2, t), b >>= 1);
    assert(!r2);
    return r1;
}

int main(void) {
    // int T; scanf("%d", &T);
    // while (T--) {
    //     int x; scanf("%d %d", &x, &p);
    //     int r = msqrt_cp(x);
    //     if (r == 0)
    //         printf("0\n");
    //     else if (r == -1)
    //         printf("Hola!\n");
    //     else {
    //         int r2 = p - r;
    //         if (r2 < r) swap(r, r2);
    //         printf("%d %d\n", r, r2);
    //         assert(mul(r2, r2) == x && mul(r, r) == x);
    //     }
    // }
    int t; scanf("%d", &t);
    auto ts = clock();
    uniform_int_distribution<int> uid(1, p - 1);
    mt19937_64 mt(time(0));
    int x;
    while (t--) {
        int w = uid(mt);
        int z = msqrt_cp(w);
        if (z != -1) assert(mul(z, z) == w); 
        x ^= z;
    }
    printf("%d\n", x);
    fprintf(stderr, "%d\n", (int)(clock() - ts));
    return 0;
}