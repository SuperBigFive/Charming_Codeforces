#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e2 + 5;
const int M = 1e6 + 5;
const double eps = 1e-6;

int n, m;

void init () {}

void charming () {
  init ();
  scanf ("%lld%lld", &n, &m);
  vector <int> c (n), p (n);
  vector <vector <int> > s (n);
  for (int i = 0; i < n; ++i) {
    scanf ("%lld%lld", &c[i], &p[i]);
    s[i].resize (p[i]);
    for (int j = 0; j < p[i]; ++j) scanf ("%lld", &s[i][j]);
  }
  vector <long double> vis (m + 1);

  auto DP = [&] (auto && me, int val) -> long double {
    if (val <= 0) return 0;
    else if (vis[val] > eps) return vis[val];
    long double ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
      long double nans = 0;
      int cnt0 = 0;
      for (int j = 0; j < p[i]; ++j) {
        if (s[i][j] > 0) nans += me (me, val - s[i][j]);
        else ++cnt0; 
      }
      if (cnt0 == p[i]) continue;
      nans = nans / p[i] + c[i];
      nans = nans * p[i] / (p[i] - cnt0);
      ans = min (ans, nans);
    }
    return vis[val] = ans;
  };

  printf ("%.12Lf\n", DP (DP, m));
}

signed main () {
  charming ();
  return 0;
}