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

int n;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <vector <int> > f (n + 1);
  for (int i = 0, fi, si; i < n; ++i) {
    fi = read (), si = read ();
    f[fi].emplace_back (si);
  }
  int ans = 0;
  vector <int> s;
  for (int i = 1; i <= n; ++i) {
    sort (f[i].begin (), f[i].end (), greater <int> ());
    if ((int) f[i].size () > 1) ans = max (ans, f[i][0] + f[i][1] / 2);
    if ((int) f[i].size () > 0) s.emplace_back (f[i][0]);
  }
  sort (s.begin (), s.end (), greater <int> ());
  if ((int) s.size () > 1) ans = max (ans, s[0] + s[1]);
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}