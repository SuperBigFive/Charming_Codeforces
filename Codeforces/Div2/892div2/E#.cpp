#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e3 + 5;

char getch () { 
	static char buf[100000], *s1, *s2; 
	return (s1 == s2) && (s2 = (s1 = buf) + 
	fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++; 
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {ch = getch (); if (ch == '-') w = -1;}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

int t, n, k;
int a[N], b[N];
int f[N][N];
int g1[N][N], g2[N][N], g3[N][N], g4[N][N];

void init () {}

void charming () {
  init ();
  n = read (), k = read ();
  for (int i = 0; i < n + 5; ++i) for (int j = 0; j < k + 5; ++j) {
    f[i][j] = g1[i][j] = g2[i][j] = g3[i][j] = g4[i][j] = -INT_MAX * N;
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) a[i] = read ();
  for (int i = 1; i <= n; ++i) b[i] = read ();
  for (int i = 0; i < n; ++i) {
    g1[i][0] = b[1] - a[1], g2[i][0] = b[1] + a[1];
    g3[i][0] = -b[1] - a[1], g4[i][0] = -b[1] + a[1];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min (i, k); ++j) {
      f[i][j] = f[i - 1][j];
      f[i][j] = max (f[i][j], g1[i - 1][j - 1] + b[i] - a[i]);
      f[i][j] = max (f[i][j], g2[i - 1][j - 1] - b[i] - a[i]);
      f[i][j] = max (f[i][j], g3[i - 1][j - 1] + b[i] + a[i]);
      f[i][j] = max (f[i][j], g4[i - 1][j - 1] - b[i] + a[i]);
    }
    if (i >= k) ans = max (ans, f[i][k]);
    g1[i][0] = b[i + 1] - a[i + 1], g2[i][0] = b[i + 1] + a[i + 1];
    g3[i][0] = -b[i + 1] - a[i + 1], g4[i][0] = -b[i + 1] + a[i + 1];
    for (int j = 1; j <= min (i, k); ++j) {
      g1[i][j] = max (g1[i - 1][j - 1], f[i][j] + b[i + 1] - a[i + 1]);
      g2[i][j] = max (g2[i - 1][j - 1], f[i][j] + b[i + 1] + a[i + 1]);
      g3[i][j] = max (g3[i - 1][j - 1], f[i][j] - b[i + 1] - a[i + 1]);
      g4[i][j] = max (g4[i - 1][j - 1], f[i][j] - b[i + 1] + a[i + 1]);
    }
  }
  cout << ans << endl;
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}