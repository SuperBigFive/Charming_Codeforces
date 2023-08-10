#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

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

int n;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <int> a (n);
  for (int i = 0; i < n; ++i) a[i] = read ();
  if (n == 1) return void (cout << 0 << endl);
  int mx = *max_element (a.begin () + 1, a.end ());
  cout << max (0ll, mx - a[0] + 1) << endl;
}

signed main () {
  charming ();
  return 0;
}