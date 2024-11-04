#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, ans;
int a[N], cnt[N];
vector <int> pos[N];

void charming () {
  cin >> n;
  vector <int> b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], b.emplace_back (a[i]);
    pos[a[i]].emplace_back (i);
  }
  sort (b.begin (), b.end ());
  b.resize (unique (b.begin (), b.end ()) - b.begin ());
  set <pair <int, int> > s;
  s.insert (make_pair (n, 1));
  for (int x : b) {
    cnt[x] = s.size ();
    for (int p : pos[x]) {
      auto seg = *s.lower_bound (make_pair (p, -1));
      s.erase (seg);
      int l = seg.second, r = seg.first;
      pair <int, int> seg_l = make_pair (p - 1, l);
      pair <int, int> seg_r = make_pair (r, p + 1);
      if (p - 1 >= l) s.insert (seg_l);
      if (r >= p + 1) s.insert (seg_r);
    }
    
  }
  int siz = b.size ();
  for (int i = 1; i <= b.back (); ++i) {
    ll ans = 0;
    int now = 0, hit = 0;
    while (now < siz) {
      int times = (b[now] - hit - 1) / i + 1;
      hit += times * i;
      ans = ans + times * cnt[b[now]];
      if (now == siz - 1 || hit >= b.back ()) break;
      int L = now + 1, R = siz - 1, nxt = R;
      while (L <= R) {
        int MID = L + R >> 1;
        if (b[MID] > hit) R = MID - 1, nxt = MID;
        else L = MID + 1;
      }
      now = nxt;
    }
    cout << ans << " \n"[i == b.back ()];
  }
}

signed main () {
  charming ();
  return 0;
}