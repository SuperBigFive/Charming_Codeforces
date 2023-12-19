#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, q;
int ans[N];
pair <int, int> qry_seg[N], qry_pos[N], mov_pos[N];
vector <int> qry_l[N], qry_r[N];
map <pair <int, int>, vector <int> > mp;
string mov;

void charming () {
    cin >> n >> q >> mov;
    mov = '#' + mov;
    int cx = 0, cy = 0;
    set <pair <int, int> > vis;
    for (int i = 1, x, y, l, r; i <= q; ++i) {
        cin >> x >> y >> l >> r;
        qry_seg[i] = make_pair (l, r);
        qry_pos[i] = make_pair (x, y);
        qry_l[l - 1].emplace_back (i);
        qry_r[r].emplace_back (i);
    }
    vis.insert (make_pair (0, 0));
    for (int i = 1; i <= n; ++i) {
        char d = mov[i];
        if (d == 'U') ++cy;
        else if (d == 'D') --cy;
        else if (d == 'L') --cx;
        else ++cx;
        vis.insert (make_pair (cx, cy));
        for (int qid : qry_l[i]) {
            int qx = qry_pos[qid].first, qy = qry_pos[qid].second;
            if (vis.count (make_pair (qx, qy))) ans[qid] = 1;
        }
        mov_pos[i] = make_pair (cx, cy);
    }
    vis.clear ();
    vis.insert (make_pair (cx, cy));
    for (int i = n; i >= 1; --i) {
        char d = mov[i];
        if (d == 'U') --cy;
        else if (d == 'D') ++cy;
        else if (d == 'L') ++cx;
        else --cx;
        for (int qid : qry_r[i]) {
            int qx = qry_pos[qid].first, qy = qry_pos[qid].second;
            if (vis.count (make_pair (qx, qy))) ans[qid] = 1;
        }
        vis.insert (make_pair (cx, cy));
    }

    cx = cy = 0;
    for (int i = 1; i <= n; ++i) {
        char d = mov[i];
        if (d == 'U') ++cy;
        else if (d == 'D') --cy;
        else if (d == 'L') --cx;
        else ++cx;
        mp[make_pair (cx, cy)].emplace_back (i);
    }
    for (auto &[p, vec] : mp) {
        sort (vec.begin (), vec.end ());
    }
    for (int i = 1; i <= q; ++i) if (!ans[i]) {
        int ql = qry_seg[i].first, qr = qry_seg[i].second;
        int qx = qry_pos[i].first, qy = qry_pos[i].second;
        int sx = mov_pos[ql - 1].first, sy = mov_pos[ql - 1].second;
        int ex = mov_pos[qr].first, ey = mov_pos[qr].second;
        int tx = sx + ex - qx, ty = sy + ey - qy;
        if (!mp.count (make_pair (tx, ty))) continue;
        else {
            auto &vec = mp[make_pair (tx, ty)];
            if (vec[0] > qr || vec.back () < ql) continue;
            else {
                int siz = vec.size (), l = 0, r = siz - 1, k = r;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (vec[mid] < ql) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                        k = mid;
                    }
                }
                if (vec[k] <= qr) ans[i] = 1;
            }
        }
    }

    for (int i = 1; i <= q; ++i) {
        if (ans[i]) puts ("Yes");
        else puts ("No");
    }
}

signed main () {
    charming ();
    return 0;
}