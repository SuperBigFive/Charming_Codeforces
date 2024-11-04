#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;

void charming () {
  cin >> n;
  vector <int> p (n);
  for (int i = 0; i < n; ++i) cin >> p[i], --p[i];
  int ans = 3;
  for (int i = 0; i < n; ++i) {
    if (i == p[p[i]]) ans = 2;
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