---
title: "Datastructures"
author: forgottencsc
date: Sept 28, 2020
geometry: margin=1cm
output: pdf_document
---

## 可撤回并查集

```cpp
int f[N], z[N], s[N], t;

void init(int n) {
    t = 0;
    fill_n(f + 1, n, 0);
    fill_n(z + 1, n, 1);
}

int find(int x) {
    while (f[x]) x = f[x];
    return x;
}

bool unite(int x, int y) {
    if (x == y) return k;
    if (z[x] > z[y]) swap(x, y);
    f[x] = y; s[++t] = x; z[y] += z[x];
    return true;
}

void rollback(int l) {
    for (int u; t != l; t--)
        u = s[t], z[f[u]] -= z[u], f[u] = w[u] = 0;
}
```

## 树状数组

区间加区间和，闭区间。

```cpp
struct BIT {
    vector<ll> a, b; int n;
    BIT(int m) : n(m + 2), a(m + 2, 0), b(m + 2, 0) {}
    void m(int x, int v) { for (ll w=1ll*x*v; x<=n-1;x+=x&-x) a[x]+=v,b[x]+=w; }
    ll q(int x) { ll u=0,v=0,k=x+1; for (;x;x-=x&-x) u+=a[x],v+=b[x]; return u*k-v; }
    void modify(int l, int r, int v) { m(l, v); m(r+1,-v); }
    ll query(int l, int r) { return q(r) - q(l - 1);}
};
```

## 线段树

### 合并+持久化

```cpp
const int M = 20 * N;
int ls[M], rs[M], st[M], rt[N], nc;

int cp(int q) {
    int p = ++nc;
    ls[p] = ls[q];
    rs[p] = rs[q];
    st[p] = st[q];
    return p;
}

void modify(int x, int v, int p, int lb, int rb) {
    st[p] += v;
    if (lb + 1 == rb) return;
    else {
        int mid = (lb + rb) >> 1;
        if (x < mid) modify(x, v, ls[p] = cp(ls[p]), lb, mid);
        else modify(x, v, rs[p] = cp(rs[p]), mid, rb);
    }
}

int query(int l, int r, int p, int lb, int rb) {
    if (l <= lb && rb <= r) return st[p];
    else {
        int mid = (lb + rb) >> 1, res = 0;
        if (l < mid) res += query(l, r, ls[p], lb, mid);
        if (r > mid) res += query(l, r, rs[p], mid, rb);
        return res;
    }
}

int merge(int lp, int rp, int lb, int rb) {
    if (!lp || !rp) return lp | rp;
    int p = cp(0); st[p] = st[lp] + st[rp];
    if (lb + 1 == rb);
    else {
        int mid = (lb + rb) >> 1;
        ls[p] = merge(ls[lp], ls[rp], lb, mid);
        rs[p] = merge(rs[lp], rs[rp], mid, rb);
    }
    return p;
}
```

### 李超树

区间修改/区间查询最小值。

向区间加入一个线段`t`时：

若区间已有线段`s[p]`在两个端点都小于`t`，则可直接将`t`丢弃。

若`t`在两个端点都小于`s[p]`，则将`s[p]`直接换成`t`。

否则`s[p]`与`t`一定相交，递归下去后没有交点的那边一定会出现上面两种情况之一。

复杂度$O(\log^2 n)$。

```cpp
struct line {
    ll a, b;
    ll operator()(ll x) { return a * x + b; }
};
line s[M]; ll v[M];
void init(...);

void modify(int l, int r, line t, int p, int lb, int rb) {
    if (l <= lb && rb <= r) {
        ll lp, rp;	//	lp = ...; rp = ...;
        v[p] = min(v[p], min(t(lp), t(rp)));
        if (s[p](lp) <= t(lp) && s[p](rp) <= t(rp)) return;
        if (t(lp) <= s[p](lp) && t(rp) <= s[p](rp)) { s[p] = t; return; }
    }
    int mid = (lb + rb) >> 1;
    if (l < mid) modify(l, r, t, p << 1, lb, mid);
    if (r > mid) modify(l, r, t, p << 1 | 1, mid, rb);
    v[p] = min(v[p], min(v[p << 1], v[p << 1 | 1]));
}

ll query(int l, int r, int p, int lb, int rb) {
    if (l <= lb && rb <= r) return v[p];
    int mid = (lb + rb) >> 1;
    ll lp, rp;	//	lp = ...; rp = ...;
    ll ans = min(s[p](lp), s[p](rp));
    if (l < mid) ans = min(ans, query(l, r, p << 1, lb, mid));
    if (r > mid) ans = min(ans, query(l, r, p << 1 | 1, mid, rb));
    return ans;
}
```



## 树链剖分

### 重链剖分

将树上路径操作转化为$2\log(n)$个区间操作，请使用小常数数据结构（如标记永久化的线段树）来维护区间信息。

| 序时钟 | 深度    | 子树大小 | 父节点  | 重儿子  | 重链最浅点 | 左端点  | 右端点  | 序为i的点 |
| ------ | ------- | -------- | ------- | ------- | ---------- | ------- | ------- | --------- |
| `dc`   | `dd[x]` | `ds[x]`  | `df[x]` | `dh[x]` | `dt[x]`    | `dl[x]` | `dr[x]` | `di[i]`   |

```cpp
vector<int> g[N];
int dd[N], df[N], dh[N], ds[N], dt[N], dl[N], dr[N], di[N], dc;
int dfs_hld1(int u, int f) {
    dd[u] = dd[f] + 1; df[u] = f;
    dh[u] = 0; ds[u] = 1;
    for (int v : g[u]) {
        if (v == f) continue;
        ds[u] += dfs_hld1(v, u);
        if (ds[v] > ds[dh[u]]) dh[u] = v;
    }
    return ds[u];
}

void dfs_hld2(int u, int t) {
    dl[u] = ++dc; di[dc] = u; dt[u] = t;
    if (dh[u]) dfs_hld2(dh[u], t);
    for (int v : g[u])
        if (v != df[u] && v != dh[u])
            dfs_hld2(v, v);
    dr[u] = dc;
}
```

```cpp
//  Example:
dc = 0; dfs_hld1(r, 0); dfs_hld2(r, r);
```

#### 求LCA

```cpp
int lca(int u, int v) {
    for (; dt[u] != dt[v]; u = df[dt[u]])
        if (dd[dt[u]] < dd[dt[v]]) swap(u, v);
    return dd[u] < dd[v] ? u : v;
}
```

#### 链操作

```cpp
void some_operation(int u, int v, ...) {
    for (; dt[u] != dt[v]; u = df[dt[u]]) {
        if (dd[dt[u]] < dd[dt[v]]) swap(u, v);
        //  区间操作[dl[dt[u]], dl[u]]
    }
    if (dd[u] > dd[v]) swap(u, v);
    //  区间操作[dl[u], dl[v]], 若修改边权则将左端点+1
}
```

#### 子树操作

```cpp
void some_operation(int u, ...) {
    //  区间操作 [dl[u], dr[u]]
}
```

## Splay

### 基本操作

```cpp
int ch[3][N], *const ls = ch[0], *const rs = ch[1], *const fa = ch[2];

int id(int x) { return ch[1][fa[x]] == x; }
bool isr(int x) { return !fa[x]; }

void update(int x, ...);
void push_down(int x);
void push_up(int x);

void rot(int x) {
    int y = fa[x], z = fa[y], o = id(x), w = ch[!o][x];
    if (!isr(y)) ch[id(y)][z] = x; fa[x] = z;
    ch[o][y] = w; if (w) fa[w] = y;
    ch[!o][x] = y; fa[y] = x;
    //	push_up(y); push_up(x);
}

void push_tag(int x) {
	static int s[N], t;
    for (s[++t] = x; !isr(x); s[++t] = x) x = fa[x];
    while (t) push_down(s[t--]);
}

void splay(int x) {
    push_tag(x);
    for (int y; !isr(x); rot(x))
        if(!isr(y=fa[x])) rot(id(x)^id(y)?x:y);
}
```

### 序列操作

#### 单点操作

```cpp
//	将第k个点转到根
void find_kth(int& r, int k) {
    int x = r;
    while (1) {
        push_down(x); int cnt = sz[ls[x]];
        if (cnt >= k) x = ls[x];
        else if (cnt == k - 1) break;
        else x = rs[x], k -= cnt + 1;
    }
    splay(r = x);
}
//	在第k个前插入
void insert_kth(int& r, int k, int v) {
    int* p = &r, x;
    while (*p) {
        push_down(x = *p); int cnt = sz[ls[x]];
        if (k <= cnt + 1) p = &ls[x];
        else p = &rs[x], k -= cnt + 1;
    }
    int y = *p = gn(v); fa[y] = x;
    splay(r = y);
}
//	删除根
void erase(int& r) {
    int x = r; push_down(x);
    if (ls[x]) {
        int y = ls[x]; push_down(y);
        while (rs[y]) push_down(y = rs[y]);
        splay(r = y);
    }
    if (rs[x]) fa[rs[x]] = fa[x];
    if (fa[x]) rs[fa[x]] = rs[x], push_up(fa[x]);
    else r = rs[x];
}
```

#### 区间操作

```cpp
//	返回代表区间[lb, rb]的点
int find_range(int& r, int lb, int rb) {
    assert(lb <= rb);
    int n = sz[r], x = r;
    if (lb != 1 && rb != n) {
        find_kth(r, rb + 1); int rp = r;
        find_kth(r, lb - 1); int lp = r;
        if (fa[rp] != lp) rot(rp); x = ls[rs[r]];
    }
    else if (rb != n) find_kth(r, rb + 1), x = ls[r];
    else if (lb != 1) find_kth(r, lb - 1), x = rs[r];
    return x;
}
//	修改区间
void modify_range(int& r, int lb, int rb, ...) {
    int x = find_range(r, lb, rb); update(x, ...);
    while (!isr(x)) push_up(x = fa[x]);
}
//	在第k个元素前插入区间。
void insert_range(int& r, int x, int k) {
    if (!r) { r = x; return; }
    int n = sz[r];
    if (k == 1) find_kth(r, 1), ls[r] = x, push_up(fa[x] = r);
    else if(k == n + 1) find_kth(r, n), rs[r] = x, push_up(fa[x] = r);
    else {
        find_kth(r, k); find_kth(r, k - 1);
        ls[rs[r]] = x; push_up(fa[x] = rs[r]); push_up(r);
    }
}
//	删除区间[lb, rb]
void erase_range(int& r, int lb, int rb) {
    int x = find_range(r, lb, rb);
    if (!isr(x)) {
        ch[id(x)][fa[x]] = 0;
        //  recycle(x)
        while (!isr(x)) push_up(x = fa[x]);
    }
    else r = 0;
}
```

#### 区间翻转

```cpp
int rev[N];
void update(int x, int v) {
    if (v) {
        swap(ls[x], rs[x]);
        rev[x] ^= 1;
    }
}
```

### 全序集操作

```cpp
//	查找从左往右第一个大于等于v的点
bool find_lwr(int& r, int v) {
    int x = r, y = -1;
    while (x) {
        push_down(x);
        if (val[x] >= v) y = x;
        x = ch[val[x] < v][x];
    }
    if (y != -1) splay(r = y);
    return y != -1;
}
//	查找从左往右第一个大于v的点
bool find_upr(int& r, int v) {
    int x = r, y = -1;
    while (x) {
        push_down(x);
        if (val[x] > v) y = x;
        x = ch[val[x] <= v][x];
    }
    if (y != -1) splay(r = y);
    return y != -1;
}
//	按键值插入节点
void insert(int& r, int y) {
    int* p = &r, x;
    while (*p) push_down(x = *p), p = &ch[val[x] < v][x];
    *p = y; fa[y] = x; splay(r = y);
}
//	按键值分裂，原树值域变为(-inf,v), 返回值域为[v,+inf)的splay
int split(int& r, int v) {
    if (!find_lwr(r, v)) return 0;
    int x = ls[r], y = r;
    fa[x] = ls[y] = 0;
    r = x; return y;
}
//	按键值合并, r中最大值小于等于x中最小值
void merge(int& r, int x) {
    if (!r) { r = x; return; }
    int y = r; while (rs[y]) push_down(y), y = rs[y];
    splay(y); r = y;
    rs[r] = x; fa[x] = r;
}
```

## LCT

```cpp
inline bool isr(int x) { return ch[id(x)][fa[x]] != x; }
void access(int x) {
    for (int y = 0; x; x = fa[y = x])
        splay(x), rs[x] = y, push_up(x);
}

int find_root(int x) {
    access(x); splay(x); push_down(x);
    while (ls[x]) push_down(x = ls[x]);
    splay(x); return x;
}

void make_root(int x) { access(x); splay(x); update(x, 1); }
void split(int x, int y) { make_root(x); access(y); splay(y); }

bool link(int x, int y) {
    make_root(x);
    if (find_root(y) == x) return false;
    fa[x] = y; return true;
}

bool cut(int x, int y) {
    make_root(x);
    if (find_root(y) != x || fa[y] != x || ls[y]) return false;
    fa[y] = rs[x] = 0; push_up(x); return true;
}
```

注1：`split`后`y`是链`x-y`的根。

注2：有根LCT在`link/cut`前（`x`是`y`的父亲）只需`access(x); splay(x); splay(y);`

注3：维护子树信息的LCT在`access`循环中需要将`rs[x]`的信息合并至虚子树信息并将`y`的信息从虚子树信息移除。
