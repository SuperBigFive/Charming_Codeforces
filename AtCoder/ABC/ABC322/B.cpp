#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, m;
string s, t;

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

void init () {}

void charming () {
  init ();
  cin >> n >> m >> s >> t;
  bool pre = (t.substr (0, n) == s);
  bool suf = (t.substr (m - n, n) == s);
  if (pre && suf) puts ("0");
  else if (pre) puts ("1");
  else if (suf) puts ("2");
  else puts ("3");
}

signed main () {
  charming ();
  return 0;
}