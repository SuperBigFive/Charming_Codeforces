#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int sgn(ll x) { return x < 0 ? -1 : x > 0; }
struct vec { ll x, y; };
bool operator<(vec a, vec b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool operator>(vec a, vec b) { return a.x == b.x ? a.y > b.y : a.x > b.x; }
bool operator==(vec a, vec b) { return a.x == b.x && a.y == b.y; }
vec operator+(vec a, vec b) { return { a.x + b.x, a.y + b.y }; }
vec operator-(vec a, vec b) { return { a.x - b.x, a.y - b.y }; }
ll operator*(vec a, vec b) { return a.x * b.x + a.y * b.y; }
ll operator^(vec a, vec b) { return a.x * b.y - a.y * b.x; }
vec operator*(vec a, ll k) { return { a.x * k, a.y * k }; }

ll dot(vec o, vec a, vec b) { return (a - o) * (b - o); }
ll crx(vec o, vec a, vec b) { return (a - o) ^ (b - o); }

//  counter-clockwise
void convex_hull(vec* ps, int n, vec* cs, int& m) {
    m = 0; if (!n) return;
    sort(ps + 1, ps + n + 1, less<vec>());
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && ps[i] == ps[i - 1]) continue;
        while (m > 1 && crx(cs[m - 1], cs[m], ps[i]) <= 0) m--;
        cs[++m] = ps[i];
    }
    const int t = m;
    for (int i = n; i >= 1; --i) {
        if (i < n && ps[i] == ps[i + 1]) continue;
        while (m > t && crx(cs[m - 1], cs[m], ps[i]) <= 0) m--;
        cs[++m] = ps[i];
    }
    m--;
}

void unique(vector<vec>& t) {
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
}

int contains(vec* cs, int m, vec v) {
    if (v < *min_element(cs + 1, cs + m + 1) || v > *max_element(cs+ 1, cs + m + 1))
        return 1;
    if (m == 1) return !(cs[1] == v);
    int res = -1;
    cs[m + 1] = cs[1]; cs[m + 2] = cs[2];
    for (int i = 1; i <= m; ++i)
        res = max(res, sgn(crx(cs[i], v, cs[i + 1])));
    return res;
}

void upd_max(ll& r, vector<vec>& t, vec v, ll x) {
    if (r > x) return;
    else if (r == x) t.push_back(v);
    else t = { v }, r = x;
}

ll crxmax(vec* cv, int m, vec v, vector<vec>& t) {
    ll r = LLONG_MIN;
    for (int i = 1; i <= m; ++i)
        upd_max(r, t, cv[i], v ^ cv[i]);
    return r;
}

ll dotmax(vec* cv, int m, vec v, vector<vec>& t) {
    ll r = LLONG_MIN;
    for (int i = 1; i <= m; ++i)
        upd_max(r, t, cv[i], v * cv[i]);
    return r;
}

void tan(vec* cv, int m, vec v, vector<vec>& lt, vector<vec>& rt) {
    cv[m + 1] = cv[1]; cv[m + 2] = cv[2];
    for (int i = 2; i <= m + 1; ++i) {
        if (crx(v, cv[i], cv[i - 1]) <= 0 && crx(v, cv[i], cv[i + 1]) <= 0)
            lt.push_back(cv[i]);
        if (crx(v, cv[i], cv[i - 1]) >= 0 && crx(v, cv[i], cv[i + 1]) >= 0)
            rt.push_back(cv[i]);
    }
    unique(lt);
    unique(rt);
}

void print(vec* cv, int m) {
    cout << m << endl;
    for (int i = 1; i <= m; ++i)
        cout << cv[i].x << ' ' << cv[i].y << endl;
}

const int N = 100001;
vec ps[N], qs[N], cs[N];

int main(void) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> ps[i].x >> ps[i].y;
    
    int m;
    convex_hull(ps, n, cs, m);
    print(cs, m);
    
    int q; cin >> q;
    while (q--) {
        int t;
        vec v; cin >> t >> v.x >> v.y;
        if (t == 1) {
            ps[++n] = v;
            convex_hull(ps, n, cs, m);
            cout << "insert: " << m << endl;
            copy_n(cs + 1, m, ps + 1);
            n = m;
        }
        if (t == 2) {
            int res = contains(cs, m, v);
            string ans;
            if (res == -1) ans = "in";
            else if (res == 0) ans = "on";
            else if (res == 1) ans = "out";
            else assert(false);
            cout << "relation: " << ans << endl;
        }
        if (t == 3) {
            vector<vec> t;
            ll r = dotmax(cs, m, v, t);
            sort(t.begin(), t.end());
            cout << "dotmax: " << t.size() << ' ' << r << endl;
            for (vec v : t) cout << v.x << ' ' << v.y << endl;
        }
        if (t == 4) {
            vector<vec> t;
            ll r = crxmax(cs, m, v, t);
            sort(t.begin(), t.end());
            cout << "crxmax: " << t.size() << ' ' << r << endl;
            for (vec v : t) cout << v.x << ' ' << v.y << endl;
        }
        if (t == 5) {
            vector<vec> lt, rt;
            tan(cs, m, v, lt, rt);
            cout << "left tangent: " << lt.size() << endl;
            for (vec v : lt) cout << v.x << ' ' << v.y << endl;
            cout << "right tangent: " << rt.size() << endl;
            for (vec v : rt) cout << v.x << ' ' << v.y << endl;
        }
    }

    return 0;
}