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
struct convex_hull_half {
    struct node : vec { node(vec v = vec{}) : vec(v), prv(0), nxt(0) {} int prv, nxt; };
    struct cmp { cmp_t* p; bool operator()(int i, int j) { return (*p)(i, j); } };
    vector<node> w; set<int, cmp> s; cmp_t c;
    
    void clear() { w.clear(); s.clear(); w.push_back(node()); }
    vec min() { return w[w[0].nxt]; }
    vec max() { return w[w[0].prv]; }
    auto lower_bound(vec v) { w[0].x = v.x; w[0].y = v.y; return s.lower_bound(0); }
    convex_hull_half() : s({ &c }) { clear(); } 

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

    void print() {
        cout << s.size() << endl;
        for (int i : s) 
            cout << w[i].x << ' ' << w[i].y << endl;
    }
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

    void print() {
        cout << size() << '\n';
        if (size() > 1) {
            for (int i : lwr.s) if (lwr.w[i].nxt) cout << lwr.w[i].x << ' ' << lwr.w[i].y << '\n';
            for (int i : upr.s) if (upr.w[i].nxt) cout << upr.w[i].x << ' ' << upr.w[i].y << '\n';
        }
        else if (size() == 1) {
            cout << lwr.w[1].x << ' ' << lwr.w[1].y << '\n';
        }
    }
};

void chk() {
    convex_hull_half<less<vec>> cv;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        vec v; cin >> v.x >> v.y;
        cv.insert(v);
    }
    cv.print();
    int q; cin >> q;
    while (q--) {
        vec v; cin >> v.x >> v.y;
        vector<vec> lt, rt;
        cv.tan(v, lt, rt);
        cout << "Left tangent point: " << lt.size() << endl;
        for (vec v : lt) cout << v.x << ' ' << v.y << endl;
        cout << "Right tangent point: " << rt.size() << endl;
        for (vec v : rt) cout << v.x << ' ' << v.y << endl;
        cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    convex_hull cv;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        vec v; cin >> v.x >> v.y;
        cv.insert(v);
    }
    
    cv.print();
    int q; cin >> q;
    for (int i = 1; i <= q; ++i) {
        int t;
        vec v; cin >> t >> v.x >> v.y;        
        if (t == 1) {
            cv.insert(v);
            cout << "insert: " << cv.size() << '\n';
        }
        if (t == 2) {
            int res = cv.contains(v);
            string ans;
            if (res == -1) ans = "in";
            else if (res == 0) ans = "on";
            else if (res == 1) ans = "out";
            else assert(false);
            cout << "relation: " << ans << endl;
        }
        if (t == 3) {
            vector<vec> t; 
            ll r = cv.dotmax(v, t);
            sort(t.begin(), t.end());
            cout << "dotmax: " << t.size() << ' ' << r << endl;
            for (vec v : t) cout << v.x << ' ' << v.y << endl;
        }
        if (t == 4) {
            vector<vec> t;
            ll r = cv.crxmax(v, t);
            sort(t.begin(), t.end());
            cout << "crxmax: " << t.size() << ' ' << r << endl;
            for (vec v : t) cout << v.x << ' ' << v.y << endl;
        }
        if (t == 5) {
            vector<vec> lt, rt;
            cv.tan(v, lt, rt);
            cout << "left tangent: " << lt.size() << endl;
            for (vec v : lt) cout << v.x << ' ' << v.y << endl;
            cout << "right tangent: " << rt.size() << endl;
            for (vec v : rt) cout << v.x << ' ' << v.y << endl;
        }
        cout.flush();
    }
    
    return 0;
}