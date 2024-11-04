#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;

int t, n;

void charming () {
  cin >> n;
  vector <pair <int, int> > opt;
  int c = n, r = n;
  for (int i = 1; i <= 2 * n; ++i) {
    if (i & 1) {
      opt.emplace_back (make_pair (1, r--));
    }
    else {
      opt.emplace_back (make_pair (2, c--));
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += i * (2 * i - 1);
  cout << ans << " " << 2 * n << endl;
  for (auto [c, i] : opt) {
    cout << c << " " << i << " ";
    for (int i = 1; i <= n; ++i) cout << i << " \n"[i == n];
  }
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}