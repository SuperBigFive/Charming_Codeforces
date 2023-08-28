#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e5 + 5;

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
  set <int> used;
  vector <int> ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j *= 2) {
      if (!used.count (j)) ans.emplace_back (j), used.insert (j);
    }
  }
  for (int i = 1; i <= n; ++i) if (!used.count (i)) ans.emplace_back (i);
  for (int x : ans) printf ("%d ", x);
  printf ("\n");
}

signed main () {
	t = read ();
  while (t--) charming ();
	return 0;
}