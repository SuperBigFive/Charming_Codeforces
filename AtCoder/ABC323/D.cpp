#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

void init () {}

void charming () {
  init ();
  n = read ();
  set <ll> siz;
  map <ll, int> cnt;
  for (int i = 0, s, c; i < n; ++i) {
    s = read (), c = read ();
    siz.insert (s), cnt[s] = c;
  }
  int ans = 0;
  while (!siz.empty ()) {
    ll s = (*siz.begin ()), c = cnt[s];
    siz.erase (siz.begin ());
    if (c > 1) cnt[s * 2] += c / 2, siz.insert (s * 2);
    ans += c % 2;
  }
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
