---
title: "Misc"
author: forgottencsc
date: Sept 28, 2020
geometry: margin=1cm
output: pdf_document
---

## 和复杂度有关的数列

其中$\sigma_0$是因子个数，$\pi(n)$是$n$以内的质数个数

|        | $x=\text{argmax} \space \sigma_0$ | $\sigma_0(x)$ | $\prod p_i$               | $\pi(10^n)$ | $\binom {2n}{n}$ |
| ------ | --------------------------------- | ------------- | ------------------------- | ----------- | ---------------- |
| $1$    | 6                                 | 4             | 2                         | 4           | 2                |
| $2$    | 60                                | 12            | 6                         | 25          | 6                |
| $3$    | 840                               | 32            | 30                        | 168         | 20               |
| $4$    | 7560                              | 64            | 210                       | 1229        | 70               |
| $5$    | 83160                             | 128           | 2310                      | 9592        | 252              |
| $6$    | 720720                            | 240           | 30030                     | 78498       | 924              |
| $7$    | 8648640                           | 448           | 510510~5e5                | 664579      | 3432             |
| $8$    | 73513440                          | 768           | 9699690~1e7               | 5761455     | 12870            |
| $9$    | 735134400                         | 1344          | 223092870~2e8             | 50847534    | 48620            |
| ${10}$ | 6983776800                        | 2304          | 6469693230~6e9            | 455052511   | 184756           |
| ${11}$ | 97772875200                       | 4032          | 200560490130~2e11         | 4118054813  | 705432           |
| ${12}$ | 963761198400                      | 6720          | 7420738134810~7e12        | 37607912018 | 2704156          |
| ${13}$ | 9316358251200                     | 10752         | 304250263527210~3e14      |             | 10400600         |
| ${14}$ | 97821761637600                    | 17280         | 13082761331670030~1e16    |             | 40116600         |
| ${15}$ | 866421317361600                   | 26880         | 614889782588491410~6e17   |             |                  |
| ${16}$ | 8086598962041600                  | 41472         | 32589158477190044730~3e19 |             |                  |
| ${17}$ | 74801040398884800                 | 64512         |                           |             |                  |
| ${18}$ | 897612484786617600                | 103680        |                           |             |                  |

## 快速读入

```cpp
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
```

## GCC扩展

### builtin系列

`__builtin_clz`返回高位`0`个数。

`__builtin_ctz`返回低位`0`个数。

`__builtin_popcount`返回`1`个数。

注：类型为`long long`时需要在后面加`ll`。

### bitset

`_Find_first`返回第一个`1`的下标。

`_Find_next(p)`返回第`p`位之后第个`1`的下标。

```cpp
#define ffirst(s) (s)._Find_first()
#define fnext(s, i) (s)._Find_next(i)
#define for_(i, n, s) for (int i = ffirst((s)); i < n; i = fnext((s), i))
```

具体用法可参考图论-最大独立集。

### PBDS

#### 优先队列

```cpp
//	Paring heap
#include <ext/pb_ds/priority_queue.hpp>
typedef __gnu_pbds::priority_queue<int, less<int>> heap;
typedef heap::point_iterator iter;
//	Example:
heap h, h2;
iter it = h.push(2);// h.top() == 2;
h.push(1);			// h.top() == 1;
h.modify(it, 0);	// h.top() == 0;
h.join(h2);
```

#### 红黑树

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbt;
```

`order_of_key`返回小于`v`的元素个数。

`find_by_order`返回第`i`个元素，下标从`0`开始。

不支持多重元素，请考虑使用`pair<int,int>`之类的东西。

#### 哈希表

```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef gp_hash_table<int, int, myhash, myequ> hashtable;
typedef cc_hash_table<int, int, myhash, myequ> hashtable;
```

## 分治

### 三维偏序

第一维排序后分治，每次统计前一半对后一半的贡献，就变成了一个二维偏序问题。

```cpp
int a[N], b[N], c[N], p[N];

ll solve(int l, int r) {
    if (l + 1 == r) return 0;
    int m = (l + r) >> 1;
    ll res = solve(l, m) + solve(m, r);
    inplace_merge(p + l, p + m, p + r, [&](int i, int j) { return b[i] < b[j]; });
    for (int i = l; i < r; ++i) {
        int u = p[i];
        if (a[u] < m) BIT::modify(c[u], 1);
        else res += BIT::query(c[u]);
    }
    for (int i = l; i < r; ++i) {
        int u = p[i];
        if (a[u] < m) BIT::modify(c[u], -1);
    }
    return res;
}

ll solve(int n) {
    iota(p + 1, p + n + 1, 1);
    sort(p + 1, p + n + 1, [&](int i, int j) { return a[i] < a[j]; });
   	return solve(1, n + 1);
}
```

注：代码中未考虑等号！

### 点分治

```cpp
vector<int> g[N];
bool vis[N]; int sz[N], msz[N];
int dfs_sz(int u, int f, int s) {
    int res = msz[u] = 0; sz[u] = 1;
    for (int v : g[u]) {
        if (vis[v] || v == f) continue;
        int r = dfs_sz(v, u, s); sz[u] += sz[v];
        msz[u] = max(msz[u], sz[v]);
        if (!res || msz[r] < msz[res]) res = r;
    }
    msz[u] = max(msz[u], s - sz[u]);
    if (!res || msz[u] < msz[res]) res = u;
    return res;
}

int vdc(int u, int s) {
    vis[u = dfs_sz(u, 0, s)] = 1;

    for (int v : g[u]) {
        if (vis[v]) continue;
        int w = vdc(v, sz[v] < sz[u] ? sz[v] : s - sz[u]);

    }
    return u;
}
```

### 边分治

```cpp
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
struct edge { int v, w; bool f; };
vector<edge> g0[N];
vector<edge> g[N];

int n; bool vit[N];
void dfs_rec(int u, int f) {
    int cnt = g0[u].size() - (f != 0), x = u;
    for (edge e : g0[u]) {
        int v = e.v; if (v == f) continue;
        dfs_rec(v, u);
        g[x].push_back({ v, e.w });
        g[v].push_back({ x, e.w });
        if (--cnt > 1) {
            ++n; vit[n] = 1;
            g[n].push_back({ x, 0 });
            g[x].push_back({ n, 0 });
            x = n;
        }
    }
}

int sz[N];
piii dfs_sz(int u, int f, int s) {
    piii res = { INT_MAX, pii(0, 0) };   
    sz[u] = 1;
    for (edge e : g[u]) {
        int v = e.v; if (e.f || e.v == f) continue;
        res = min(res, dfs_sz(v, u, s));
        sz[u] += sz[v];
    }
    return min(res, piii(max(s - sz[u], sz[u]), pii(f, u)));
}

void dc(int u, int f, int s) {
    if (s == 1) return;
    ++m; it[m] = h0.end();
    piii p = dfs_sz(u, f, s);
    int d = p.first; tie(f, u) = p.second;
    for (edge& e : g[u]) if (e.v == f) e.f = 1, len[m] = e.w;
    for (edge& e : g[f]) if (e.v == u) e.f = 1;
    //	dfs_info(f, u, ...);
    //	dfs_info(u, f, ...);
    
    int su = sz[u];
    dc(u, f, su);
    dc(f, u, s - su);
}

//	Example: After reading edges into g0...
dfs_rec(1, 0);
dc(1, 0, n);
```

注：点数开两倍！

