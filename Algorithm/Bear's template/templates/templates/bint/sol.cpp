#include <bits/stdc++.h>


using namespace std;
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ul;
typedef unsigned ui;

template<class I>
struct ext : array<I, 2> {

    ext(I u, I v) {
        this->at(0) = u;
        this->at(1) = v;
    }

    ext(ui i = 0) : ext(I(i),I(0)) {}
};

template<class I>
bool operator<(ext<I> a, ext<I> b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

template<class I>
bool operator==(ext<I> a, ext<I> b) {
    return a[0] == b[0] && a[1] == b[1];
}

template<class I>
ext<I> operator&(ext<I> a, ext<I> b) {
    return { a[0] & b[0], a[1] & b[1] };
}

template<class I>
ext<I> operator>>(ext<I> a, ui c) {

}

template<class I>
ext<I> add(ext<I> a, ext<I> b) {
    ext<I> c;
    c[0] = a[0] + b[0];
    c[1] = a[1] + b[1] + (c[0] < a[0] && c[0] < b[0]);
    return c;
}

ext<ui> mul(ui a, ui b) {
    ul r = (ul)a * (ul) b;
    return { (ui)r, (ui)(r >> 32) };
}

template<class I>
ext<ext<I>> mul(ext<I> a, ext<I> b) {
    ext<ext<I>> c;
    ext<ext<I>> d;
    ext<I> x = mul(a[0], b[0]), y = mul(a[0], b[1]), z = mul(a[1], b[0]), w = mul(a[1], b[1]);
    c[0] = x;
    c[1] = w;
    d[0][1] = y;
    c = add(c, d);
    d[0][1] = z;
    c = add(c, d);
    return c;
}

template<class I>
ext<I> qpm(ext<I> a, ext<I> b) {
    ext<I> c(1);
    
}

string bin(ui a) {
    return bitset<32>(a).to_string();
}

template<class I>
string bin(ext<I> a) {
    return bin(a[1]) + bin(a[0]);
}

int main(void) {

    ext<ext<ext<ui>>> a(114514);

    return 0;
}


int main(void) {
    bint<unsigned> a;
    a = a + a;
    return 0;
}