#include <bits/stdc++.h>
#include <wmmintrin.h>
#pragma GCC target("pclmul")

using namespace std;

const int N = 1 << 16;
const int M = 831;

typedef unsigned ui;
typedef unsigned long long ul;

ul mmod(ul a, ul b) {
    int i = __builtin_clzll(a);
    int j = __builtin_clzll(b);
    int t = j - i;
    ul c = b <<= t;
    ul d = 1ull << 63 - i;
    while (t >= 0) {
        if (a & d)
            a ^= c;
        c >>= 1;
        d >>= 1;
        --t;
    }
    return a;
}

ui omul(ui a, ui b) {
    ul c = _mm_cvtsi128_si64(_mm_clmulepi64_si128(_mm_cvtsi32_si128(a), _mm_cvtsi32_si128(b), 0));
    ul d = (1ull << 32) | M;
    int i = __builtin_clzll(c);
    int t = 31 - i;
    ul e = d <<= t;
    ul f = 1ull << (63 - i);
    while (t >= 0) {
        if (c & f)
            c ^= e;
        e >>= 1;
        f >>= 1;
        --t;
    }
    return c;

}

ui xmul(ui a, ui b) {  //  141, 175, 197, 245
    __m128i m = _mm_set_epi32(0, 0, 1, M),
    c = _mm_clmulepi64_si128(_mm_cvtsi32_si128(a), _mm_cvtsi32_si128(b), 0);
    c = _mm_xor_si128(c, _mm_clmulepi64_si128(_mm_srli_epi64(c, 32), m, 0));
    c = _mm_xor_si128(c, _mm_clmulepi64_si128(_mm_srli_epi64(c, 32), m, 0));
    return (ui)_mm_cvtsi128_si32(c);
}

int main(void) {
    ul h = 1ull << 32;
    ///*
    ul m = h | M;
    mt19937_64 mt(time(0));
    const int t = 1e6;
    vector<ul> a(t), b(t);
    for (int i = 0; i != t; ++i) {
        ul x = mt();
        a[i] = x >> 32;
        b[i] = x & (ui)~0;
    }
    auto ts = clock();
    ul s1 = 0, s2 = 0;
    for (int i = 0; i != t; ++i) {
        ul c = xmul(a[i], b[i]);//a[i] * b[i] % 998244353;
        s1 ^= c;
        ul d = omul(a[i], b[i]);
        s2 ^= d;
    }
    cout << clock() - ts << endl;
    cout << s1 << ' ' << s2 << endl;
    return 0;
    //*/
    ///*
    for (ui i = 1; i < 65536; ++i) {
        bool flg = 0;
        for (ui j = 2; j < N; ++j)
            if (mmod(i | h, j) == 0) {
                flg = 1;
                break;
            }        
        if (!flg)
            cout << i << ' ' << endl;
    }
    //*/
    return 0;
}