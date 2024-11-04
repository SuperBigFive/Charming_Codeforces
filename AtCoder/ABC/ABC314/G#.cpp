#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

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

int t, n, m, h;

void init () {}

void charming () {
  init ();
  n = read (), m = read (), h = read ();
  vector <int> sum (m + 1), ans (m + 1);
  multiset <int> remain, del;
  for (int i = 0; i < n; ++i) remain.insert (0);
  for (int i = 0, cnt = 0, ma, mb; i < n; ++i) {
    ma = read (), mb = read ();
    if (del.count (sum[mb])) {
      del.erase (del.find (sum[mb]));
      sum[mb] += ma;
      del.insert (sum[mb]);
    }
    else {
      remain.erase (remain.find (sum[mb]));
      sum[mb] += ma;
      remain.insert (sum[mb]);
      while (!del.empty () && !remain.empty () && 
      *del.begin () < *remain.rbegin ()) {
        int tmp = *del.begin ();
        h += *remain.rbegin () - tmp;
        del.erase (del.begin ());
        del.insert (*remain.rbegin ());
        remain.erase (remain.find (*remain.rbegin ()));
        remain.insert (tmp);
      }
      h -= ma;
      while (h <= 0) {
        h += *remain.rbegin ();
        del.insert (*remain.rbegin ());
        remain.erase (remain.find (*remain.rbegin ()));
        ++cnt;
      }
    }
    ans[cnt] = i + 1;
  }
  for (int i = 1; i <= m; ++i) ans[i] = max (ans[i - 1], ans[i]);
  for (int i = 0; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}

signed main () {
  charming ();
  return 0;
}