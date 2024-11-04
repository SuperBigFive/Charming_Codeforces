#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n;
string s1, s2, s3;

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
  cin >> n >> s1 >> s2 >> s3;
  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        int nans;
        if (s1[i] == s2[j] && s1[i] == s3[k]) {
          if (i == j && i == k) nans = 2 * n + i;
          else if (i == j || i == k || j == k) {
            int mx = max ({i, j, k}), mn = min ({i, j, k});
            int cnt = (i == mx) + (j == mx) + (k == mx);
            if (cnt == 2) nans = n + mx;
            else nans = n + mn;
          }
          else {
            nans = max ({i, j, k});
          }
          ans = min (ans, nans);
        }
      }
    }
  }
  if (ans >= INT_MAX) printf ("-1\n");
  else printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}