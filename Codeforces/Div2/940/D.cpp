#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int M = 30;

int t, n;
int a[N], ban[N];

ll Solve (vector <int> &pos) {
  ll ans = 0;
  int siz = pos.size ();
  vector <int> pre2 (siz + 1), suf2 (siz + 1);
  int lst = 0;
  for (int i = 0, l; i < siz; ++i) {
    l = pos[i] - lst;
    if (i <= 1) pre2[i] = l;
    else pre2[i] = pre2[i - 2] + l;
    lst = pos[i];
  }
  lst = n + 1;
  for (int i = siz - 1, l; i >= 0; --i) {
    l = lst - pos[i];
    if (i >= siz - 2) suf2[i] = l;
    else suf2[i] = suf2[i + 2] + l;
    lst = pos[i];
  }
  for (int i = 0; i < siz; ++i) {
    if (i - 1 >= 0) {
      ans += 1ll * pre2[i - 1] * suf2[i] * (ban[pos[i]] ^ 1);
    }
    if (i + 1 < siz) {
      ans += 1ll * pre2[i] * suf2[i + 1] * (ban[pos[i]] ^ 1);
    }
  }
  for (int i = 0; i < siz; ++i) ban[pos[i]] = 1;
  return ans;
}

void charming () {
  cin >> n;
  vector <vector <int> > pos (M, vector <int> ());
  for (int i = 1, d; i <= n; ++i) {
    ban[i] = 0;
    cin >> a[i], d = 0;
    while (a[i]) {
      if (a[i] & 1) pos[d].emplace_back (i);
      d += 1, a[i] >>= 1;
    }
  }
  ll ans = 0;
  for (int i = M - 1; i >= 0; --i) {
    if ((int) pos[i].size ()) ans += Solve (pos[i]);
  }
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