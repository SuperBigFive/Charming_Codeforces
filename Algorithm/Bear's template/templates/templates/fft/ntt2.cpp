#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int P = 998244353;
mt19937_64 mt(time(0));
uniform_int_distribution<int> uid(1, P - 1);
inline int add(int a, int b) { int r = a + b; return r < P ? r : r - P; }
inline int sub(int a, int b) { int r = a - b; return r < 0 ? r + P : r; }
inline int mul(int a, int b) { return 1ll * a * b % P; }
inline int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}
inline int inv(int x) { return qpm(x, P - 2); }


namespace NTT1 {

void init() {}

vi pmul(const vi& a, const vi& b) {

}

vi pinv(const vi& a) {


}

}

using NTT1::init;
using NTT1::pmul;
using NTT1::pinv;

struct timer {
    clock_t t;
    timer() : t(clock()) {}
    ~timer() { printf("%dms\n", clock() - t); }
};

const int N = 100000000;
int a[N];

int main(void) {
    for (int i = 0; i < N; ++i)
        a[i] = uid(mt);
    {
        timer _;
        int sum = 1;
        for (int i = 0; i < N; ++i)
            sum = (1ll * sum * a[i]) % P;
        printf("%d\n", sum);
    }
    {
        timer _;
        long long sum = 1;
        for (int i = 0; i < N; ++i)
            sum = sum * a[i] % P;
        printf("%lld\n", sum);
    }

    return 0;
}