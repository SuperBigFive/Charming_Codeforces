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

int t, n;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <int> a (n);
  int ans = 0, mn1 = n + 1, mn2 = n + 1;
  for (int i = 0; i < n; ++i) {
    a[i] = read (), mn1 = min (mn1, a[i]);
    if (a[i] <= mn1) continue;
    else if (a[i] > mn2) continue;
    else mn2 = a[i], ++ans;
  }
  cout << ans << endl;
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  t = read ();
  while (t--) charming ();
  return 0;
}