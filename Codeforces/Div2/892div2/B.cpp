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
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {ch = getch (); if (ch == '-') w = -1;}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

int t, n, m;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <vector <int> > a (n);
  for (int i = 0; i < n; ++i) {
    m = read ();
    a[i].resize (m);
    for (int j = 0; j < m; ++j) a[i][j] = read ();
    sort (a[i].begin (), a[i].end ());
  }
  ll ans = 0;
  int delta = INT_MAX, mn = INT_MAX;
  for (int i = 0; i < n; ++i) {
    ans += a[i][1];
    delta = min (delta, a[i][1]);
    mn = min (mn, a[i][0]);
  }
  cout << ans - (delta - mn) << endl;
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}