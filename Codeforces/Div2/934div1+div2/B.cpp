#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n, k;
int a[N << 1];

void charming () {
  cin >> n >> k;
  for (int i = 1; i <= (n << 1); ++i) cin >> a[i];
  vector <int> vis (n + 1);
  vector <int> twice_lef;
  for (int i = 1; i <= n; ++i) {
    if (vis[a[i]]) twice_lef.emplace_back (a[i]), vis[a[i]] = 2;
    else vis[a[i]] = 1;
  }
  vis = vector <int> (n + 1);
  vector <int> twice_rig;
  for (int i = n + 1; i <= (n << 1); ++i) {
    if (vis[a[i]]) twice_rig.emplace_back (a[i]), vis[a[i]] = 2;
    else vis[a[i]] = 1;
  }
  vector <int> both_have;
  for (int i = 1; i <= n; ++i) if (vis[i] == 1) both_have.emplace_back (i);
  vector <int> l, r;
  for (int i = 0; i < min (2 * k, ((int) both_have.size ()) / 2 * 2); ++i) {
    l.emplace_back (both_have[i]);
    r.emplace_back (both_have[i]);
  }
  int delta = 2 * k - (int) l.size ();
  for (int i = 0; i < delta / 2; ++i) {
    l.emplace_back (twice_lef[i]);
    l.emplace_back (twice_lef[i]);
  }
  for (int i = 0; i < delta / 2; ++i) {
    r.emplace_back (twice_rig[i]);
    r.emplace_back (twice_rig[i]);
  }
  for (int i = 0; i < k * 2; ++i) cout << l[i] << " \n"[i == k * 2 - 1];
  for (int i = 0; i < k * 2; ++i) cout << r[i] << " \n"[i == k * 2 - 1];
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}