#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int h, w, m;

void charming () {
  cin >> h >> w >> m;
  vector <int> vis_row (h + 1),  vis_col (w + 1);
  vector <array <int, 3> > opt;
  for (int i = 1, t, a, x; i <= m; ++i) {
    cin >> t >> a >> x;
    opt.emplace_back ((array <int, 3>) {t, a, x});
  }
  reverse (opt.begin (), opt.end ());
  int cnt_row = 0, cnt_col = 0;
  map <int, ll> cnt;
  for (auto [t, a, x] : opt) {
    if (t == 1) {
      if (vis_row[a]) continue;
      if (w - cnt_col) cnt[x] += w - cnt_col;
      vis_row[a] = 1;
      ++cnt_row;
    }
    else {
      if (vis_col[a]) continue;
      if (h - cnt_row) cnt[x] += h - cnt_row;
      vis_col[a] = 1;
      ++cnt_col;
    }
  }

  ll sum = 0;
  for (auto [k, v] : cnt) sum += v;
  if (1ll * h * w - sum > 0) cnt[0] += 1ll * h * w - sum;
  cout << (int) cnt.size () << endl;
  for (auto [k, v] : cnt) {
    cout << k << " " << v << endl;
  }
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}