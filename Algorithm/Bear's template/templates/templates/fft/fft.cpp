#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace FFT {

typedef long double dbl;
typedef complex<dbl> cplx;
const cplx I(0, 1);
const dbl pi = acos(-1);

const int W = 21, S = 1 << W;

int r[S], m, s; cplx w[S];

void init(int n) {
    for (s = 0, m = 1; m < n; m <<= 1) ++s;
    for (int i = 0; i != m; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (s - 1));
    for (int i = 0; i <= m; ++i) w[i] = { cos(2 * pi * i / m), sin(2 * pi * i / m) };
}

void fft(cplx* p) {
    for (int i = 0; i != m; ++i) if (i < r[i]) swap(p[i], p[r[i]]);
    for (int i = 1, z = 0; i != m; i <<= 1, z++)
        for (int j = 0; j != m; j += (i << 1))
            for (int k = 0; k != i; k++) {
                cplx u = p[j + k], v = w[k<<s-z-1] * p[i + j + k];
                p[j + k] = u + v; p[i + j + k] = u - v;
            }
    
}

cplx pa[S], pb[S], pc[S], pd[S];
vector<int> conv(const vector<int>& a, const vector<int>& b) {
    int n1 = a.size(), n2 = b.size(), n3 = n1 + n2 - 1;
    init(n3);
    for (int i = 0; i < m; ++i) pa[i] = cplx(i < n1 ? a[i] : 0, i < n2 ? b[i] : 0);
    fft(pa);
    for (int i = 0; i < m; ++i) {
        int j = i ? m - i : 0;
        pb[i] = (conj(pa[j]) + pa[i]) * (conj(pa[j]) - pa[i]) * I / cplx(4);
    }
    fft(pb);
    vector<int> c(n3);
    for (int i = 0; i < n3; ++i) c[i] = round(pb[i ? m - i : 0].real() / m);
    return c;
}

vector<ll> conv2(const vector<int>& a, const vector<int>& b) {
    int n1 = a.size(), n2 = b.size(), n3 = n1 + n2 - 1;
    const int s = 15, msk = (1 << s) - 1; init(n3);
    for (int i = 0; i < m; ++i) {
        pa[i] = (i < n1 ? cplx(a[i] & msk, a[i] >> s) : cplx(0));
        pb[i] = (i < n2 ? cplx(b[i] & msk, b[i] >> s) : cplx(0));
    }
    fft(pa); fft(pb);
    for (int i = 0; i < m; ++i) {
        int j = i ? m - i : 0;
        pc[i] = (conj(pa[j]) + pa[i]) * pb[i] / cplx(2);
        pd[i] = (conj(pa[j]) - pa[i]) * pb[i] * I / cplx(2);
    }
    fft(pc); fft(pd);
    reverse(pc + 1, pc + m);
    reverse(pd + 1, pd + m);
    vector<ll> c(n3);
    for (int i = 0; i < n3; ++i) {
        pc[i] /= m; pd[i] /= m;
        ll ac = round(pc[i].real()), bc = round(pc[i].imag());
        ll ad = round(pd[i].real()), bd = round(pd[i].imag());
        c[i] = ac + ((bc + ad) << s) + (bd << (2 * s));
    }
    return c;
}

}  // namespace FFT

using namespace FFT;

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

const int N = 1000002;

namespace io {

    const int S = 1<<24;
    char s[S], *t, *p;

    bool get() { t = s + fread(s, 1, S, stdin); p = s; return s != t; }
    bool eof() { return p == t && !get(); }
    char getc(int c = 1) { if (eof()) return -1; while (--c) ++p; return *p++; }
    void skip() { while (!isgraph(getc())); p--;}

    template<class T>
    void readi(T& i) {
        skip(); i = 0; char ch = getc(); bool neg = (ch == '-');
        if (neg) ch = getc();
        for (; isdigit(ch); ch = getc()) i = 10 * i + (ch - '0');
        if (neg) i = -i;
    }

    int readl(char* s) {
        int n = 0; while ((*s++ = getc()) != '\n') ++n;
        return n;
    }

}

using io::readi;


int main(void) {
    int n, m, p;
    readi(n); readi(m); readi(p); n++; m++;
    vector<int> a(n), b(m);
    for (int& i : a) readi(i);
    for (int& i : b) readi(i);
    vector<int> c = FFT::conv2(a, b, p);
    for (int i = 0; i < n + m - 1; ++i)
        printf("%d%c", c[i], " \n"[i + 1 == n + m - 1]);
    return 0;
}