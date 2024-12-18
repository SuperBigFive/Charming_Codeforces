#include <bits/stdc++.h>
using namespace std;

typedef double dbl;
typedef long long ll;
struct vec { dbl x, y; };
bool operator==(vec a, vec b) { return a.x == b.x && a.y == b.y; }
mt19937 mt(time(0)); const dbl pi = acos(-1);
int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(mt); }
dbl rnd(dbl x, dbl y) { return uniform_real_distribution<dbl>(x, y)(mt); }
dbl r, k, dx, dy, kx, ky; int m, n, q;
vec rndv(bool round = true, bool nz = false) {
    vec res;
    do {
    if (round) {
        r += poisson_distribution<int>(k)(mt);
        dbl f = rnd(0., 2 * pi);
        dbl x = kx * cos(f) * r + dx, y = ky * sin(f) * r + dy;
        res =  { x, y };
    } 
    else res = { rnd(-m, m), rnd(-m, m) };
    } while (nz && res == vec{ 0, 0 });
    return res;
}

ostream& operator<<(ostream& os, vec v) {
    return os << (ll)v.x << ' ' << (ll)v.y;
}


int main(int c, char** v) {
    m = atoi(v[1]), n = atoi(v[2]), q = atoi(v[3]);
    k = atof(v[4]);
    cout << n << endl;
    r = rnd(0., m / 2.);
    kx = 1, ky = 1, dx = 0, dy = 0;
    for (int i = 1; i <= n; ++i) {
        cout << rndv() << endl;
    }
    cout << q << endl;
    for (int i = 1; i <= q; ++i) {
        int t = rnd(1, 5);
        cout << t << ' ';
        if (1 <= t && t <= 5)
            cout << rndv(t == 1 || (t == 2 && !rnd(0, 0)), t==3 || t==4) << endl;
        else if (t == 6) {
            int e = rnd(0, 3);
            if (!e) r *= 2;
            cout << rndv(false) << ' ' << rndv(false) << endl;
            if (!e) r *= 0.5;
        }
    }
    return 0;
}