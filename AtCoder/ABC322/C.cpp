#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, m;
int a[N], b[N];

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
  n = read (), m = read ();
  for (int i = 1; i <= m; ++i) {
    a[read ()] = 1;
  }
  for (int i = n; i >= 1; --i) {
    if (a[i]) b[i] = i;
    else b[i] = b[i + 1]; 
  }
  for (int i = 1; i <= n; ++i) printf ("%d\n", b[i] - i);
}

signed main () {
  charming ();
  return 0;
}