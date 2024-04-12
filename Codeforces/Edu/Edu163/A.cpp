#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;

void charming () {
  cin >> n;
  if (n & 1) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 1; i <= n / 2; ++i) {
      if (i & 1) cout << "AA";
      else cout << "BB";
    }
    cout << endl;
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