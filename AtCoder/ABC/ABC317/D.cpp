#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;

char getch () {
  static char buf[100000], *s, *s2;
  return (s == s2) && (s2 = (s = buf) +
  fread (buf, 1, 100000, stdin)), s == s2 ? EOF : *s++;
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

int n;

void init () {}

void charming () {
  init ();
  n = read ();
  vector <pair <int, int> > a;
  int sum_z = 0, now_z = 0;
  for (int i = 0, x, y, z; i < n; ++i) {
    x = read (), y = read (), z = read ();
    if (x > y) now_z += z;
    else a.emplace_back (make_pair ((y - x + 1) / 2, z << 1));
    sum_z += z;
  }
  int delta = sum_z - now_z - now_z;
  if (delta < 0) puts ("0");
  else {
    ll ans = LLONG_MAX;
    vector <ll> f (N, LLONG_MAX);
    int siz = a.size ();
    f[0] = 0;
    // cout << siz << " " << a[0].second << " " << delta << endl;
    for (int i = 0; i < siz; ++i) {
      for (int j = N - 1, from; j >= a[i].second; --j) {
        from = j - a[i].second;
        if (f[from] < LLONG_MAX) f[j] = min (f[j], f[from] + a[i].first);
        if (f[j] != -1 && j > delta) ans = min (ans, f[j]);
      }
    }
    printf ("%lld\n", ans);
  }
}

signed main () {
  charming ();
  return 0;
}
