#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

int t, m, k, a1, ak;

void init () {}

void charming () {
  init ();
  m = read (), k = read (), a1 = read (), ak = read ();
  if (1ll * ak * k >= m) {
    m %= k;
    cout << max (0, m - a1) << endl;
  }
  else {
    m -= ak * k;
    if (m <= a1) cout << 0 << endl;
    else {
      m -= a1;
      int d1 = m / k, cost = d1 + (m - d1 * k);
      if (a1 >= k - (m % k)) cost = min (cost, m / k + 1);
      cout << cost << endl;
    }
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  t = read ();
  while (t--) charming ();
  return 0;
}