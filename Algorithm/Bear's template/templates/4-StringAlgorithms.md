---
title: "StringAlgorithms"
author: forgottencsc
date: Dec 11, 2020
geometry: margin=1cm
output: pdf_document
---

## 基本算法

```cpp
//  f[i]为s以i结束的等于s的某个前缀的最长串长
void getf(const string& s, vector<int>& f) {
    int n = s.size(); f.resize(n, 0);
    for (int i = 1, j = 0; i != n; ++i) {
        while (j && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) ++j;
        f[i] = j;
    }
    //for (int i = 0; i != n; ++i) cout << f[i] << " \n"[i == n - 1];
}

//  l[i]为t以i结束的等于s的某个前缀的的最长串长
void getl(const string& s, const string& t, const vector<int>& f, vector<int>& l) {
    int n = s.size(), m = t.size(); l.resize(m, 0);
    for (int i = 0, j = 0; i != m; ++i) {
        while(j && t[i] != s[j]) j = f[j - 1];
        if (t[i] == s[j]) ++j;
        l[i] = j;
        if (j == n) j = f[j - 1];
    }
    for (int i = 0; i != m; ++i) cout << l[i] << " \n"[i == m - 1];
}

//  z[i]为s以i为起始的等于s的某个前缀的最长串长
void getz(const string& s, vector<int>& z) {
    int n = s.size(); z.resize(n, 0);
    for (int i = 1, l = 0, r = 0; i != n; ++i) {
        int j = z[i - l];
        if (i+j>r) for (j=max(0, r-i); i+j!=n&&s[ia+j]==s[j]; ++j);
        z[i] = j; if (i+j-1>r) l=i, r=i+j-1;
    }
    z[0] = n;
    //for(int i = 0; i != n; ++i) cout << z[i] << " \n"[i == n - 1];
}

//  e[i]为t以i起始的等于s的某个前缀的最长串长
void gete(const string& s, const string& t, const vector<int>& z, vector<int>& e) {
    int n = s.size(), m = t.size(); e.resize(m, 0);
    for (int i = 0, l = 0, r = 0; i != m; ++i) {
        int j = z[i - l];
        if (i+j>r) for (j=max(0, r-i); i+j!=m&&t[i+j]==s[j]; ++j);
        e[i] = j; if (i+j-1>r) l=i, r=i+j-1;
    }
    //for (int i = 0; i != m; ++i) cout << e[i] << " \n"[i == m - 1];
}

//  r[i]为t串以i为中心的回文半径：t[i+r[i]]==t[i-r[i]]
void getr(const string& s, vector<int>& r) {
    int n = s.size(), m = 2 * n + 1; r.resize(m, 0);
    string t(m, '#');
    for (int i = 0; i != n; ++i) t[2 * i + 1] = s[i];
    for (int i = 1, p = 0, w = 0; i != m; ++i) {
        int j = (i>p+w ? 0 : min(r[p-(i-p)], p+w-i));
        while(0<=i-j-1 && i+j+1<m && t[i-j-1]==t[i+j+1]) ++j;
        r[i] = j; if (i + j > p + w)  p = i, w = j;
    }
    //for (int i = 0; i != m; ++i) cout << r[i] << " \n"[i == m - 1];
}

//  判断区间[l,u)是否为回文
bool ispal(vector<int>& r, int l, int u) {
    return r[l + u] >= u - l;
}
```

## 哈希

字符串$s=s_0s_1s_2\cdots s_{n-1}$，其哈希被定义为$\displaystyle h(s)=\sum_{x=0}^{n-1}b^{n-1-x}s_x$。

因此
$$
h(s_{0...r})=h(s_{0...r-1})b+s_{r}\\
h(s_{l...r-1})=h(s_{0...r-1})-h(s_{0...l-1})b^{r-l}
$$
$\mathbb F_{2^{32}}$上的神奇哈希

```cpp
#include <wmmintrin.h>
#pragma GCC target("pclmul")
typedef unsigned ui;
ui xmul(ui a, ui b) {
    __m128i m = _mm_set_epi32(0, 0, 1, 999),  //  141, 175, 197, 245
    c = _mm_clmulepi64_si128(_mm_cvtsi32_si128(a), _mm_cvtsi32_si128(b), 0);
    c = _mm_xor_si128(c, _mm_clmulepi64_si128(_mm_srli_epi64(c, 32), m, 0));
    c = _mm_xor_si128(c, _mm_clmulepi64_si128(_mm_srli_epi64(c, 32), m, 0));
    return (ui)_mm_cvtsi128_si32(c);
}

using namespace std;

const ui b = 1145141919;
ui pb[N];
void init_hash() {
    for (int i = pb[0] = 1; i < N; ++i)
        pb[i] = xmul(pb[i - 1], b);
}
void get_hash(char* s, ui* h) {
    for (int i = 0; s[i]; ++i)
        h[i] = s[i] ^ xmul(i ? h[i - 1] : 0, b);
}
ui get_hash(ui* h, int l, int r) {
    return h[r - 1] ^ xmul(pb[r - l], l ? h[l - 1] : 0);
}
```

## 后缀数组

```cpp
int sa[N], rk[N], sh[N];
int st[N][21], lg2[N];
int sw1[N], sw2[N], sc[N];
void build_sa(const char* s) {
    int n = strlen(s + 1), m = 128, *x = sw1, *y = sw2;
    memset(sc + 1, 0, m << 2);
    for (int i = 1; i <= n; ++i) sc[x[i] = s[i]]++;
    for (int i = 1; i <= m; ++i) sc[i] += sc[i - 1];
    for (int i = 1; i <= n; ++i) sa[sc[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (int i = n - k + 1; i <= n; ++i) y[++p] = i;
        for (int i = 1; i <= n; ++i) if (sa[i] > k) y[++p] = sa[i] - k;
        memset(sc + 1, 0, m << 2);
        for (int i = 1; i <= n; ++i) sc[x[i]]++;
        for (int i = 1; i <= m; ++i) sc[i] += sc[i - 1];
        for (int i = n; i >= 1; --i) sa[sc[x[y[i]]]--] = y[i];
        swap(x, y); p = x[sa[1]] = 1;
        for (int i = 2; i <= n; ++i)
            x[sa[i]] = (y[sa[i] + k] == y[sa[i - 1] + k]
            && y[sa[i]] == y[sa[i - 1]]) ? p: ++p;
        m = p; if (m == n) break;
    }
    for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; ++i) {
        if (rk[i] == 1) continue; if (k) --k;
        int j = sa[rk[i] - 1];
        while (j + k <= n && i + k <= n && s[i + k] == s[j + k])
            ++k;
        sh[rk[i]] = k;
    }
    for (int i = 2; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
    for (int i = 1; i <= n; ++i) st[i][0] = sh[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) <= n + 1; ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int lcp(int u, int v) {
    int l = rk[u], r = rk[v];
    if (l > r) swap(l, r); l++; r++;
    int k = lg2[r - l];
    return min(st[l][k], st[r - (1 << k)][k]);
}
//	设lb=getl(p,w), rb=getr(p,w), 则s[p...p+w-1]为sa[lb...rb]中所有后缀的前缀。
int getl(int p, int w) {
    int l = 1, r = rk[p] - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (lcp(p, sa[mid]) < w)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int getr(int p, int w) {
    int l = rk[p] + 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (lcp(p, sa[mid]) < w)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return r;
}
```

## 自动机

### ACAM

```cpp
int g[N][26], f[N], e[N], nc;

int gn() {
    int p = nc++; f[p] = e[p] = 0;
    memset(g[p], 0, sizeof(g[p]));
    return p;
}

void clr() { nc = 0; gn(); }

void ins(const string& s) {
    int p = 0;
    for (int i = 0; i != s.size(); ++i) {
        int o = s[i] - 'a';
        if (!g[p][o]) g[p][o] = gn();
        p = g[p][o];
    }
    e[p] = 1;
}

void build() {
    queue<int> q;
    for (int o = 0; o != 26; ++o)
        if (g[0][o]) q.push(g[0][o]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if (e[f[u]]) e[u] = 1;
        for (int o = 0; o != 26; ++o) {
            int& v = g[u][o];
            if (!v) v = g[f[u]][o];
            else {
                f[v] = g[f[u]][o];
                q.push(v);
            }
        }
    }
}
```

### SAM

记得清理根的`g[]`

```cpp
namespace SAM {
int g[N][26], f[N], l[N], nc;
int split(int p, int o) {
    int q = g[p][o]; if (l[p] + 1 == l[q]) return q;
    int nq = ++nc; l[nq] = l[p] + 1;
    copy_n(g[q], 26, g[nq]); f[nq] = f[q]; f[q] = nq;
    for (; p && g[p][o] == q; p = f[p]) g[p][o] = nq;
    return nq;
}
int extend(int r, int p, int o) {
	if (g[p][o]) return split(p, o);
    int np = ++nc; l[np] = l[p] + 1;
    fill_n(g[np], 26, 0);
    for (; p && g[p][o] == 0; p = f[p]) g[p][o] = np;
    f[np] = p ? split(p, o) : r;
    return np;
}
void clear(int r) {
    fill_n(g[r], 26, 0);
}
}
```

### PAM

```cpp
char s[N];
int g[N][26], f[N], l[N], w[N], nc;

int gn(int len) {
    int p = nc++; l[p] = len; f[p] = 0;
    memset(g[p], 0, sizeof(g[p]));
    return p;
}

int gf(int p, int i) {
    while (s[i] != s[i - l[p] - 1])
        p = f[p];
    return p;
}

void clr() {
    nc = 0; gn(0); gn(-1);
    f[0] = 1; f[1] = -1;
}

int extend(int p, int i) {
    int o = s[i] - 'a'; p = gf(p, i);
    if (!g[p][o]) {
        int q = gn(l[p] + 2); g[p][o] = q;
        if (p != 1) f[q] = g[gf(f[p], i)][o];
    }
    p = g[p][o];
    return p;
}
```

### PAM2

```cpp
namespace pam {

char s[N]; int tl, tr;
int g[N][26], f[N], l[N], nc;
int pl, pr;

int gn(int len) {
    int q = nc++; l[q] = len; f[q] = 0;
    memset(g[q], 0, sizeof(g[q]));
    return q;
}

void clr() {
    fill(s + tl, s + tr + 1, 0);
    nc = 0; gn(0); gn(-1); f[0] = 1;
    tr = N; tl = tr + 1;
    pl = pr = 0;
}

int gfl(int p, int i) {
    while (s[i] != s[i + l[p] + 1]) p = f[p];
    return p;
}

int gfr(int p, int i) {
    while (s[i] != s[i - l[p] - 1]) p = f[p];
    return p;
}

int extl(int o) {
    s[--tl] = o + 'a'; int p = gfl(pl, tl);
    if (!g[p][o]) {
        int q = gn(l[p] + 2); g[p][o] = q;
        if (p != 1) f[q] = g[gfl(f[p], tl)][o];
    }
    pl = g[p][o];
    if (tl + l[pl] - 1 == tr) pr = pl;
    return h[pl];
}

int extr(int o) {
    s[++tr] = o + 'a'; int p = gfr(pr, tr);
    if (!g[p][o]) {
        int q = gn(l[p] + 2); g[p][o] = q;
        if (p != 1) f[q] = g[gfr(f[p], tr)][o];
    }
    pr = g[p][o];
    if (tr - l[pr] + 1 == tl) pl = pr;
    return h[pr];
}

}
```

