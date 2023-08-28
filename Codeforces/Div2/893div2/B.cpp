#include <bits/stdc++.h>
#define ll long long
#define int ll
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

int t, n, m, d;

void init () {}

void charming () {
	init ();
	n = read (), m = read (), d = read ();
  vector <int> s (m + 2);
  for (int i = 1; i <= m; ++i) s[i] = read ();
  int ans = 1;
  for (int i = (s[1] == 1) + 1, last = 1, delta; i <= m; ++i) {
    delta = s[i] - last - 1;
    ans += delta / d + 1;
    last = s[i];
    if (i == m) ans += (n - s[i]) / d;
  }
  int mn = 0, cnt = 0;
  if (s[1] == 1) cnt = 1;
  s[0] = 1, s[m + 1] = n + 1;
  // cout << ans << endl;
  for (int i = (s[1] == 1) + 1; i <= m; ++i) {
    int bef = (s[i] - s[i - 1] - 1) / d + (s[i + 1] - s[i] - 1) / d + 1;
    int aft = (s[i + 1] - s[i - 1] - 1) / d;
    // cout << i << " " << bef << " " << aft << endl;
    if (aft - bef < mn) mn = aft - bef, cnt = 1;
    else if (aft - bef == mn) ++cnt;
  }
  printf ("%lld %lld\n", ans + mn, cnt);
}

signed main () {
	t = read ();
  while (t--) charming ();
	return 0;
}