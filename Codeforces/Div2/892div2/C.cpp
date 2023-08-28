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
  n = read ();
  ll ans = 0;
  vector <int> p (n);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < i; ++j) p[j] = j + 1;
    for (int j = n - 1; j >= i; --j) p[j] = i + n - j;
    ll sum = 0, mx = 0;
    for (int j = 0; j < n; ++j) {
      sum += 1ll * p[j] * (j + 1);
      mx = max (mx, 1ll * p[j] * (j + 1));
    }
    ans = max (ans, sum - mx);
  }
  cout << ans << endl;
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}
