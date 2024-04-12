#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void charming () {
  cin >> n >> k;
  if (k >= n - 1) cout << 1 << endl;
  else {
    cout << n << endl;
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