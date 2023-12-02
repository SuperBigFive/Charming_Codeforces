#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, c;
int a[N];

void init () {}

void charming () {
  init ();
  cin >> n >> c;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int sum = a[1], p = 1;
  for (int i = 2; i <= n; ++i) {
    if (sum + a[i] >= i * c) {
      while (p < i) sum += a[++p];
    }
  }
  if (p >= n) puts ("YES");
  else puts ("NO");
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}