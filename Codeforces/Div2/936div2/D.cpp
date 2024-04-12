#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int M = 31;

int randint (int l, int r) {
	return l + ((rnd () << 15) + rnd ()) % (r - l + 1);
}

int t, n, x;
int a[N];

int Solve (int tar) {
  int k = 0, xor_sum = 0;
  for (int i = 0; i < n; ++i) {
    xor_sum ^= a[i];
    if ((xor_sum | tar) == tar) ++k, xor_sum = 0;
  }
  if (xor_sum == 0) return k;
  else return -1;
}

void charming () {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = -1;
  for (int i = 0; i < M; ++i) {
    if ((x >> i) & 1) {
      int y = (x ^ (1ll << i));
      if (i) y |= ((1ll << i) - 1);
      ans = max (ans, Solve (y));
    }
  }
  ans = max (ans, Solve (x));
  cout << ans << endl;
}

signed main () {
  cin >> t;
  while (t--) charming ();
  return 0;
}