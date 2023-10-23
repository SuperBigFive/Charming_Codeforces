#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

void init () {}

void charming () {
  init ();
  n = read ();
  int ans = 0;
  for (int i = 1; i < n; ++i) ans += read ();
  printf ("%d\n", -ans);
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}
