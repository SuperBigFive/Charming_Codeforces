#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1001;
const ll inf = LLONG_MAX;

namespace matching {

int lnk[N], pre[N];
bool vis[N];

ll a[N], b[N], w[N][N], sl[N];

vector<pair<pii, ll>> match(int nl, int nr, const vector<pair<pii, ll>>& es) {
    nr = max(nl, nr);
    fill_n(lnk + 1, nr, 0);
    for (int i = 1; i <= nl; ++i)
        fill_n(w[i], nr, 0);
    for (pair<pii, ll> e : es)
        w[e.first.first][e.first.second] = e.second;
    for (int i = 1; i <= nl; ++i)
        a[i] = *max_element(w[i] + 1, w[i] + nr + 1);
    fill_n(b + 1, nr, 0);
    for (int i = 1, j, u, vt; i <= nl; ++i) {
        fill_n(vis + 1, nr, 0);
        fill_n(sl, nr + 1, inf);
        lnk[0] = i;
        for (j = 0; u = lnk[j]; j = vt) {
            ll d = inf; vis[j] = 1;
            for (int v = 1; v <= nr; ++v) {
                ll t = a[u] + b[v] - w[u][v];
                if (vis[v]) continue;
                if (sl[v] > t)
                    sl[v] = t, pre[v] = j;
                if (sl[v] < d)
                    d = sl[v], vt = v;
            }
            for (int v = 0; v <= nr; ++v) {
                if (vis[v]) a[lnk[v]] -= d, b[v] += d;
                else sl[v] -= d;
            }
        }
        for (; j; j = pre[j]) lnk[j] = lnk[pre[j]];
    }
    vector<pair<pii, ll>> res;
    for (int i = 1; i <= nr; ++i)
        res.emplace_back(pii(lnk[i], i), a[lnk[i]] + b[i]);
    return res;
}

}