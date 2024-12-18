#include <bits/stdc++.h>
using namespace std;

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
struct dyn_convex_hull_half {
    struct node : vec { node(vec v = vec{}) : vec(v), prv(0), nxt(0) {} int prv, nxt; };
    struct cmp { cmp_t* p; bool operator()(int i, int j) { return (*p)(i, j); } };
    vector<node> w; set<int, cmp> s; cmp_t c;
    
    void clear() { w.clear(); s.clear(); w.push_back(node()); }
    auto lower_bound(vec v) { w[0].x = v.x; w[0].y = v.y; return s.lower_bound(0); }
    dyn_convex_hull_half() : s({ &c }) { clear(); } 

    int get_pos(vec v, int& lp, int& rp) {
        c = [&](int i, int j) { return pr()(w[i], w[j]); };
        auto it = lower_bound(v);
        lp = it != s.begin() ? *prev(it) : 0;
        rp = it != s.end() ? *it : 0;
        if (!lp && !rp) return 1;
        else if (!lp || !rp) return c(lp|rp,0)||c(0,lp|rp);
        else return sgn(crx(w[lp], w[0], w[rp]));
    }
    
    //  1 for outside, 0 for on segment, -1 for inside
    int contains(vec v) { int lp, rp; return get_pos(v, lp, rp); }

    bool insert(vec v) {
        int lp, rp;
        if (get_pos(v, lp, rp) != 1) return false;
        for (int j; lp && (j = w[lp].prv); lp = j)
            if (crx(w[j], w[lp], v) <= 0) s.erase(lp); else break;
        for (int j; rp && (j = w[rp].nxt); rp = j)
            if (crx(w[j], w[rp], v) >= 0) s.erase(rp); else break;
        int p = w.size(); w.push_back(node(v));
        s.insert(w[w[p].prv = lp].nxt = w[w[p].nxt = rp].prv = p);
        return true;
    }

    ll crxmax(vec v) {
        c = [&](int i, int) { return w[i].nxt?(w[0]^(w[w[i].nxt]-w[i]))>0:0; };
        return v ^ w[*lower_bound(v)];
    }
    
    void dotmax(vec v) { return crxmax({ v.y, -v.x }; }

};

struct dyn_convex_hull {
    dyn_convex_hull_half<less<vec>> lwr;
    dyn_convex_hull_half<greater<vec>> upr;

    bool insert(vec v) { bool il = lwr.insert(v), iu = upr.insert(v); return il || iu; }
    ll crxmax(vec v) { return max(lwr.crxmax(v), upr.crxmax(v)); }

};