#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

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

int n;

ll Floor_Sum (int a, int b, int c, int n) {
  ll ans = 0;
  if (a >= c) {
    ans = (ans + n * (n + 1) / 2 * (a / c)) % MOD;
    a %= c;
  }
  if (b >= c) {
    ans = (ans + (n + 1) * (b / c)) % MOD;
    b %= c;
  }
  ll m = (a * n + b) / c;
  if (m) ans = (ans + m * n - Floor_Sum (c, c - b - 1, a, m - 1)) % MOD;
  return ans;
}

void init () {}

void charming () {
  init ();
  n = read ();
  vector <int> a (n);
  for (int i = 0; i < n; ++i) a[i] = read ();
  sort (a.begin (), a.end ());
  ll ans = a[n - 1] + 1, sum = a[0] * n;
  for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
  // cout << ans << endl;
  for (int i = 1; i < n; ++i) {
    ans = (ans + Floor_Sum (n - i, sum, n, a[i])) % MOD;
    ans = (ans - Floor_Sum (n - i, sum, n, 0)) % MOD;
    // cout << ans << endl;
    // cout << "a = " << n - i << " b = " << sum << " c = " << n << " n = " << a[i] << endl;
    sum += a[i] * (n - i);
  }
  ans = ((ans % MOD) + MOD) % MOD;
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}