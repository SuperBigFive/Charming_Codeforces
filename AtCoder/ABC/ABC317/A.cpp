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

int n, h, x;

void init () {}

void charming () {
  init ();
  n = read (), h = read (), x = read ();
  x -= h;
  int ans = 0;
  for (int i = 0, a; i < n; ++i) {
    a = read ();
    if (a >= x && !ans) ans = i + 1;
  }
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
