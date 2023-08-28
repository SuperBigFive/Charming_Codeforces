#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e4 + 5;

char getch () {
  static char buf[100000], *s, *s2;
  return (s == s2) && (s2 = (s = buf) +
  fread (buf, 1, 100000, stdin)), s == s2 ? EOF : *s++;
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

int n;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <int> a (n);
  for (int i = 0; i < n; ++i) a[i] = read ();
  sort (a.begin (), a.end ());
  int ans = -1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1] + 1) {ans = a[i - 1] + 1; break;}
  }
  if (ans == -1) {
    if (a[0] == 1) ans = n + 1;
    else ans = 1000 - n;
  }
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
