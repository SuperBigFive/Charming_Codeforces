#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int a, b;

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
  a = read (), b = read ();
  int ans = 0, ab = 1, ba = 1;
  for (int i = 0; i < b; ++i) {
    ab *= a;
  }
  for (int i = 0; i < a; ++i) {
    ba *= b;
  }
  ans = ab + ba;
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}