#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

template<class Clock = system_clock>
struct timer {
    typename Clock::time_point t;
    timer() : t(Clock::now()) {}
    ~timer() { cerr << duration_cast<milliseconds>(Clock::now() - t).count() << endl; }
};

typedef double dbl;
struct vec { dbl x, y, z; };
vec operator+(vec v1, vec v2) { return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }; }
vec operator-(vec v1, vec v2) { return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }; }
dbl operator*(vec v1, vec v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
vec operator^(vec v1, vec v2) {
	return { v1.y * v2.z - v1.z * v2.y,
		     v1.z * v2.x - v1.x * v2.z,
		     v1.x * v2.y - v1.y * v2.x };
}
vec operator*(vec v, dbl k) { return { v.x * k, v.y * k, v.z * k }; }
vec operator/(vec v, dbl k) { return { v.x / k, v.y / k, v.z / k }; }

struct plane {
    dbl a, b, c, d;
    dbl operator()() { return a * a + b * b + c * c; }
    dbl operator()(vec v) { return (a*v.x+b*v.y+c*v.z+d); }
};
dbl dis(plane p, vec v) { return fabs(p(v)) / sqrt(p()); }

vec sym(plane p, vec v) {
    return v - vec{p.a, p.b, p.c} * 2 * p(v) / p();
}

int main(void) {
    const int m = 114514;
    uniform_real_distribution<double> ur(-m, m);
    mt19937_64 mt(time(0));

    timer<> _;
    int T = 1145141;
    while (T--) {
        vec v = { ur(mt), ur(mt), ur(mt) };
        plane p = { ur(mt), ur(mt), ur(mt), ur(mt) };
        vec u = sym(p, v), w = (u + v) / 2;
        printf("%f\n", p(w));
    }

}