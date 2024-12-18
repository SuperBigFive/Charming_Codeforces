## 凸包

### 二维动态

```cpp
typedef double dbl;
typedef long long ll;
int sgn(ll x) { return x < 0 ? -1 : x > 0; }

struct vec { ll x, y; };
bool operator<(vec a, vec b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool operator>(vec a, vec b) { return a.x == b.x ? a.y > b.y : a.x > b.x; }
bool operator!=(vec a, vec b) { return a.x != b.x || a.y != b.y; }
bool operator==(vec a, vec b) { return a.x == b.x && a.y == b.y; }
vec operator+(vec a, vec b) { return { a.x + b.x, a.y + b.y }; }
vec operator-(vec a, vec b) { return { a.x - b.x, a.y - b.y }; }
ll operator*(vec a, vec b) { return a.x * b.x + a.y * b.y; }
ll operator^(vec a, vec b) { return a.x * b.y - a.y * b.x; }
vec operator*(vec a, ll k) { return { a.x * k, a.y * k }; }

ll dot(vec o, vec a, vec b) { return (a - o) * (b - o); }
ll crx(vec o, vec a, vec b) { return (a - o) ^ (b - o); }

typedef function<bool(int, int)> cmp_t;

template<class pr>
struct convex_hull_half {
    struct node : vec { node(vec v = vec{}) : vec(v), prv(0), nxt(0) {} int prv, nxt; };
    struct cmp { cmp_t* p; bool operator()(int i, int j) { return (*p)(i, j); } };
    vector<node> w; set<int, cmp> s; cmp_t c;
    dbl C; ll S;
    
    void clear() { w.clear(); s.clear(); w.push_back(node()); }
    vec min() { return w[w[0].nxt]; }
    vec max() { return w[w[0].prv]; }
    auto lower_bound(vec v) { w[0].x = v.x; w[0].y = v.y; return s.lower_bound(0); }
    convex_hull_half() : s({ &c }), C(0), S(0) { clear(); } 

    int get_pos(vec v, int& lp, int& rp) {
        c = [&](int i, int j) { return pr()(w[i], w[j]); };
        auto it = lower_bound(v);
        lp = it != s.begin() ? *prev(it) : 0;
        rp = it != s.end() ? *it : 0;
        if (!lp && !rp) return 1;
        else if (!lp || !rp) return c(lp|rp,0)||c(0,lp|rp);
        else return sgn(crx(w[lp], w[0], w[rp]));
    }

    int contains(vec v) { int lp, rp; return get_pos(v, lp, rp); }

    bool insert(vec v) {
        int lp, rp;
        if (get_pos(v, lp, rp) != 1) return false;
        for (int j; lp && (j = w[lp].prv); lp = j)
            if (crx(w[j], w[lp], v) <= 0) s.erase(lp); else break;
        for (int j; rp && (j = w[rp].nxt); rp = j)
            if (crx(w[j], w[rp], v) >= 0) s.erase(rp); else break;
        int p = w.size(); w.push_back(node(v));
        for (int i = lp; i != rp; i = w[i].nxt) {
            C -= dis(w[i], w[w[i].nxt]);
            S -= w[i] ^ w[w[i].nxt];
        }
        C += dis(w[lp], w[p]) + dis(w[p], w[rp]);
        S += (w[lp] ^ w[p]) + (w[p] ^ w[rp]);
        s.insert(w[w[p].prv = lp].nxt = w[w[p].nxt = rp].prv = p);
        return true;
    }

    void upd_max(ll& r, vector<vec>& t, vec v, ll x) {
        if (r > x) return;
        else if (r == x) t.push_back(v);
        else t = { v }, r = x;
    }

    void crxmax(vec v, ll& r, vector<vec>& t) {
        c = [&](int i, int) { return w[i].nxt?(w[0]^(w[w[i].nxt]-w[i]))>0:0; };
        int p = *lower_bound(v);
        upd_max(r, t, w[p], v ^ w[p]);
        if (w[p].nxt && (v ^ w[w[p].nxt]) == (v ^ w[p]))
            upd_max(r, t, w[w[p].nxt], v ^ w[w[p].nxt]);
    }
    
    void dotmax(vec v, ll& r, vector<vec>& t) { return crxmax({ v.y, -v.x }, r, t); }

    void upd_ltan(vec v, vec tp, vector<vec>& t) {
        if (t.empty() || crx(v, tp, t.front()) < 0)
            t.assign(1, tp);
        else if(crx(v, tp, t.front()) == 0)
            t.push_back(tp);
    }

    void upd_rtan(vec v, vec tp, vector<vec>& t) {
        if (t.empty() || crx(v, tp, t.front()) > 0)
            t.assign(1, tp);
        else if (crx(v, tp, t.front()) == 0)
            t.push_back(tp);
    }

    void ltan(vec v, vec rb, vector<vec>& t) {
        c = [&](int i, int) { return w[i].nxt?pr()(w[i], rb)&&crx(w[0], w[i], w[w[i].nxt])>0:0; };
        auto it = lower_bound(v); assert(it != s.end());
        int p = *it; upd_ltan(v, w[p], t);
        if (w[p].nxt) upd_ltan(v, w[w[p].nxt], t);
    }

    void rtan(vec v, vec lb, vector<vec>& t) {
        c = [&](int i, int) { return w[i].nxt?pr()(w[i], lb)||crx(w[0], w[i], w[w[i].nxt])<0:0; };
        auto it = lower_bound(v); assert(it != s.end());
        int p = *it; upd_rtan(v, w[p], t);
        if (w[p].nxt) upd_rtan(v, w[w[p].nxt], t);
    }

    void tan(vec v, vector<vec>& lt, vector<vec>& rt) {
        if (pr()(v, min())) { rtan(v, min(), rt); return; }
        if (pr()(max(), v)) { ltan(v, max(), lt); return; }
        int lp, rp, res = get_pos(v, lp, rp);
        if (res == -1) return;
        if (res == 0) {
            if (v == w[rp]) {
                rp = w[rp].nxt;
                upd_ltan(v, w[lp], lt);
                upd_ltan(v, v, lt);
                upd_rtan(v, w[rp], rt);
                upd_rtan(v, v, rt);
            }
            else {
                upd_ltan(v, w[lp], lt);
                upd_rtan(v, w[rp], rt);
            }
        }
        else if (res == 1) {
            ltan(v, w[rp], lt);
            rtan(v, w[lp], rt);
        }
    }

    size_t size() { return s.size(); }
};

void unique(vector<vec>& t) {
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
}
struct convex_hull {
    convex_hull_half<less<vec>> lwr;
    convex_hull_half<greater<vec>> upr;

    bool insert(vec v) { bool il = lwr.insert(v), iu = upr.insert(v); return il || iu; }
    int contains(vec v) { return max(lwr.contains(v), upr.contains(v)); }
    ll dotmax(vec v, vector<vec>& t) {
        ll res = LLONG_MIN;
        lwr.dotmax(v, res, t);
        upr.dotmax(v, res, t);
        unique(t);
        return res;
    }

    ll crxmax(vec v, vector<vec>& t) {
        ll res = LLONG_MIN;
        lwr.crxmax(v, res, t);
        upr.crxmax(v, res, t);
        unique(t);
        return res;
    }

    void tan(vec v, vector<vec>& lt, vector<vec>& rt) {
        lwr.tan(v, lt, rt);
        upr.tan(v, lt, rt);
        unique(lt);
        unique(rt);
    }

    size_t size() { 
        size_t ls = lwr.size(), us = upr.size();
        if (!ls && !us) return 0;
        else if (ls == 1 && us == 1) return 1;
        else return ls + us - 2;
    }

};
```

### 三维

```cpp
namespace CH3D {

vec p[N]; int n, l[N][N];

typedef pair<int, int> pii;

pii get_first_edge() {
    int u = 0;
    for (int i = 1; i < n; ++i)
        if (tie(p[i].x,p[i].y,p[i].z)<tie(p[u].x,p[u].y,p[u].z)) u = i;
    int v = u ? 0 : 1;
    for (int i = 0; i < n; ++i) {
        if (u == i || v == i) continue;
        vec v1 = p[v] - p[u], v2 = p[i] - p[u], v3 = v2 ^ v1;
        if (v3.z>0||(v3.z==0&&(v3.y<0||(v3.y==0&&(v3.x>0||v2*v2>v1*v1))))) v = i;
    }
    return { u, v };
}

pii get_next_edge(int u, int v) {
    int w = -1;
    for (int i = 0; i < n; ++i) {
        if (u == i || v == i) continue;
        vec v1 = p[u] - p[v], v2 = p[w] - p[v], v3 = p[i] - p[v];
        ll d1 = (v3 ^ v1) * v2, d2 = (v3 ^ v2) * (v2 ^ v1); 
        if (w==-1||d1<0||(d1==0&&(d2>0||(d2==0&&v3*v3>v2*v2)))) w = i;
    }
    l[u][v] = w;
    return { v, w };
}

void build() {
    for (int i = 0; i < n; ++i) fill_n(l[i], n, -1);
    queue<pii> q; q.push(get_first_edge()); 
    while (!q.empty()) {
        int u, v; tie(u, v) = q.front(); q.pop();
        if (l[u][v] == -1) q.push(get_next_edge(u, v));
        if (l[v][u] == -1) q.push(get_next_edge(v, u));
    }
}

bool f[N][N];
void process() {
    for (int i = 0; i < n; ++i) fill_n(f[i], n, 0);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || f[i][j] || l[i][j] == -1) continue;
            int u = i, v = j;
            while (!f[u][v]) {
                f[u][v] = 1;  //  Triangle iuv
                vec t = (p[u] - p[i]) ^ (p[v] - p[i]);

                int w = l[u][v];
                u = v; v = w;
            }
        }
    }
}

}
```

## 半平面交