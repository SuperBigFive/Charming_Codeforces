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

int t, n;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <int> a (n + 5);
  map <int, int> cnt;
  for (int i = 1; i <= n; ++i) a[i] = read (), ++cnt[a[i]];
  if (n == 1) return void (cout << "No" << endl);
  ll mx = 0;
  for (auto [it, c] : cnt) mx = max (mx, c);
  if (mx * 2 > n) {
    if (cnt[1] == mx) {
      int sum = 0;
      for (int i = 1; i <= n; ++i) {
        if (a[i] > 1) sum += a[i] - 1;
      }
      if (sum >= mx) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else cout << "Yes" << endl;
  }
  else cout << "Yes" << endl;
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}