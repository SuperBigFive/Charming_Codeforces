#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;

void charming () {
  string s;
  cin >> s, n = s.size ();
  int p = 0;
  vector <pair <int, int> > seq;
  while (p < n) {
    if (s[p] == '0') {++p; continue;}
    int q = p;
    while (q < n && s[q] == '1') ++q;
    seq.emplace_back (make_pair (p, q - 1));
    p = q;
  }
  if ((int) seq.size () == 0) {
    cout << 0 << endl;
    return;
  }
  int ans = 0, cnt = 0, siz = (int) seq.size ();
  cnt += seq[0].second - seq[0].first + 1;
  for (int i = 1, delta; i < siz; ++i) {
    delta = seq[i].first - seq[i - 1].second - 1;
    ans += (cnt + 1) * delta;
    cnt += seq[i].second - seq[i].first + 1;
  }
  ans += (cnt + 1) * (n - 1 - seq.back ().second);
  cout << ans << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}