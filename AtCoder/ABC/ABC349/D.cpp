#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

ll L, R;

void Solve (ll l, ll r, vector <pair <ll, ll> > &ans) {
  ll len = r - l + 1;
  int cnt = -1;
  while (len) len >>= 1, ++cnt;
  ll tar = 1ll << cnt;
  ll start = (l + tar - 1) / tar * tar;
  ll end = start + tar - 1;
  if (end > r) {
    tar >>= 1;
    start = (l + tar - 1) / tar * tar;
    end = start + tar - 1;
  }
  if (start > l) Solve (l, start - 1, ans);
  ans.emplace_back (make_pair (start, end));
  if (end < r) Solve (end + 1, r, ans);
}

void charming () {
  cin >> L >> R;
  vector <pair <ll, ll> > ans;
  Solve (L, R - 1, ans);
  cout << ans.size () << endl;
  for (auto [l, r] : ans) cout << l << " " << r + 1 << endl;
}

signed main () {
  charming ();
  return 0;
}