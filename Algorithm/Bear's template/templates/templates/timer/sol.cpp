#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template<class Clock = chrono::system_clock>
struct timer {
    typename Clock::time_point t;
    timer() : t(Clock::now()) {}
    ~timer() { cerr << duration_cast<milliseconds>(Clock::now() - t).count() << endl; }
};

int main(void) {
    timer<> _;
    int sum = 0, t = 1, p = 145140019;
    for (int i = 1; i <= 200000000; ++i) {
        sum = (sum + t) % p;
        t = (1ll * t * t + i) % p;
    }
    printf("%d\n", sum);
    return 0;
}