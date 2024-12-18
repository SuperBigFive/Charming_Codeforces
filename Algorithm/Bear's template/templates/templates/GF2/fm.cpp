#include <bits/stdc++.h>
#include <wmmintrin.h>
#pragma GCC target("pclmul")

using namespace std;

const int N = 1 << 16;

typedef unsigned ui;
typedef unsigned long long ul;

ul mmul(ui a, ui b) {
    return _mm_cvtsi128_si64(_mm_clmulepi64_si128(
        _mm_cvtsi32_si128(a), _mm_cvtsi32_si128(b), 0
    ));
}

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

int main(void) {
    for (ui i = 1; i < 65536; ++i) {
        bool flg = 0;
        for (ui j = 2; j < N; ++j)
            if (mmod(i | (1ull << 32), j) == 0) {
                flg = 1;
                break;
            }        
        if (!flg)
            cout << i << endl;
    }
    return 0;
}