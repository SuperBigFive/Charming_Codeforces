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

int n, m;

void init () {}

void charming () {
  init ();
  n = read (), m = read ();
  vector <vector <int> > G (n, vector <int> (n));
  for (int i = 0, u, v, w; i < m; ++i) {
    u = read (), v = read (), w = read ();
    --u, --v;
    G[u][v] = G[v][u] = w;
  }
  vector <int> p (n);
  iota (p.begin (), p.end (), 1);
  int ans = 0;
  do {
    int nans = 0;
    for (int i = 0, u, v; i < n - 1; ++i) {
      u = p[i] - 1, v = p[i + 1] - 1;
      if (G[u][v]) nans += G[u][v];
      else break;
    }
    ans = max (ans, nans);
  } while (next_permutation (p.begin (), p.end ()));
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
