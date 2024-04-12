#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;

void charming () {
  cin >> n;
  int lst = 0, chk = 0;
  for (int i = 1, x; i <= n; ++i) {
    int fi, se;
    cin >> x;
    if (x < lst) chk = 1;
    fi = x / 10, se = x % 10;
    if (fi <= se && lst <= fi) lst = se;
    else lst = x;
  }
  if (chk) cout << "NO" << endl;
  else cout << "YES" << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}