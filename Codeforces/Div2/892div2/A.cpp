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

int t, n;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <int> a (n);
  for (int i = 0; i < n; ++i) a[i] = read ();
  sort (a.begin (), a.end ());
  if (a[0] == a[n - 1]) return void (cout << -1 << endl);
  int m = 0;
  while (a[m] == a[0]) ++m;
  cout << m << " " << n - m << endl;
  for (int i = 0; i < m; ++i) cout << a[i] << " \n"[i == m - 1];
  for (int i = m; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}