#include <bits/stdc++.h>
using namespace std;

template<int P>
struct mint {
    int v;
    mint(int x = 0) : v(x) {}
    mint(const mint&) = default;
    mint& operator=(const mint&) = default;
    friend inline mint operator+(mint a, mint b) { int r = a.v + b.v; return { r < P ? r : r - P }; }
    friend inline mint operator-(mint a, mint b) { int r = a.v - b.v; return { r < 0 ? r + P : r }; }
    friend inline mint operator*(mint a, mint b) { return { (int)(1ll * a.v * b.v % P) }; }
    mint& operator+=(mint b) { (*this) = (*this) + b; return (*this); }
    mint& operator-=(mint b) { (*this) = (*this) - b; return (*this); }
    mint& operator*=(mint b) { (*this) = (*this) * b; return (*this);}
    mint pow(int b) {
        mint r = 1, a = (*this);
        do if (b & 1) r *= a; while (a *= a, b >>= 1);
        return r;
    }
    mint inv() { return pow(P - 2); }
    friend inline mint operator/(mint a, mint b) { return a * b.inv(); }
    mint& operator/=(mint b) { (*this) = (*this) / b; return (*this); }

};

int main(void) {
    int a, b; cin >> a;
    mint<7> x(a);
    cout << (x * x.inv()).v  << endl;
    return 0;
}