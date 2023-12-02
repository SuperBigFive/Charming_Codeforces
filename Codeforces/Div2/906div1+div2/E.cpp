#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n, m, k;
int pre1[N], pre2[N], cnt1[N], suf[N];
pair <int, int> seq[N];
vector <pair <int, int> > tag[N];
set <int> rain_id;

void init () {
  for (int i = 0; i <= n + 1; ++i) {
    pre1[i] = pre2[i] = cnt1[i] = suf[i] = 0;
    tag[i].clear ();
  }
  rain_id.clear ();
}

int getGain (int l1, int r1, int l2, int r2) {
  if (l1 > l2) swap (l1, l2), swap (r1, r2);
  if (r1 < l2) return pre1[r1] - pre1[l1 - 1] + pre1[r2] - pre1[l2 - 1];
  else if (r2 >= r1) {
    int l3 = l2, r3 = r1;
    r1 = l3 - 1, l2 = r3 + 1;
    int gain = 0;
    if (r1 >= l1) gain += pre1[r1] - pre1[l1 - 1];
    if (r2 >= l2) gain += pre1[r2] - pre1[l2 - 1];
    if (r3 >= l3) gain += pre2[r3] - pre2[l3 - 1];
    return gain;
  }
  else {
    int l3 = r2 + 1, r3 = r1;
    r1 = l2 - 1;
    int gain = 0;
    if (r1 >= l1) gain += pre1[r1] - pre1[l1 - 1];
    if (r2 >= l2) gain += pre2[r2] - pre2[l2 - 1];
    if (r3 >= l3) gain += pre1[r3] - pre1[l3 - 1];
    return gain;
  }
}

void charming () {
  init ();
  cin >> n >> m >> k;
  for (int i = 1, l, r; i <= m; ++i) {
    cin >> l >> r;
    tag[l].emplace_back (i, 1);
    tag[r + 1].emplace_back (i, -1);
    seq[i] = make_pair (l, r);
  }
  int cnt0 = 0, ans = 0;
  vector <pair <int, int> > chk;
  for (int i = 1; i <= n; ++i) {
    for (auto [id, st] : tag[i]) {
      if (st == 1) rain_id.insert (id);
      else rain_id.erase (id);
    }
    int cnt = rain_id.size ();
    if (cnt == 0) ++cnt0;
    else if (cnt == 1) ++pre1[i];
    else if (cnt == 2) {
      ++pre2[i];
      chk.emplace_back (*rain_id.begin (), *rain_id.rbegin ());
    }
  }
  sort (chk.begin (), chk.end ());
  chk.resize (unique (chk.begin (), chk.end ()) - chk.begin ());
  
  for (int i = 1; i <= n; ++i) {
    pre1[i] += pre1[i - 1];
    pre2[i] += pre2[i - 1];
  }
  for (auto [id1, id2] : chk) {
    auto [l1, r1] = seq[id1];
    auto [l2, r2] = seq[id2];
    ans = max (ans, getGain (l1, r1, l2, r2));
  }

  for (int i = 1, l, r; i <= m; ++i) {
    l = seq[i].first, r = seq[i].second;
    cnt1[i] = pre1[r] - pre1[l - 1];
    suf[l] = max (suf[l], cnt1[i]);
  }
  for (int i = n; i >= 1; --i) {
    suf[i] = max (suf[i], suf[i + 1]);
  }
  for (int i = 1, l, r; i <= m; ++i) {
    l = seq[i].first, r = seq[i].second;
    ans = max (ans, cnt1[i] + suf[l + 1]);
  }

  cout << ans + cnt0 << endl;
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}