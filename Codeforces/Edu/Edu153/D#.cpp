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
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

int n;
string s;

void init () {}

void charming () {
  init ();
  cin >> s, n = s.size (), s = '#' + s;
  vector <vector <int> > f (n + 1, vector <int> (n * n, N));
  f[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    vector <vector <int> > nf (n + 1, vector <int> (n * n, N));
    for (int j = 0; j <= i; ++j) {
      for (int k = 0, nk; k < n * n; ++k) if (f[j][k] < N) {
        if (s[i + 1] == '0') {
          nk = k + (i - j);
          nf[j + 1][nk] = min (nf[j + 1][nk], f[j][k]);
          nf[j][k] = min (nf[j][k], f[j][k] + 1);
        }
        else {
          nk = k + (i - j);
          nf[j + 1][nk] = min (nf[j + 1][nk], f[j][k] + 1);
          nf[j][k] = min (nf[j][k], f[j][k]);
        }
      }
    }
    f = nf;
  }
  int tar = n * (n - 1), cnt0 = 0, cnt1 = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') ++cnt0;
    else ++cnt1;
  }
  tar -= cnt0 * (cnt0 - 1) + cnt1 * (cnt1 - 1);
  tar >>= 2;
  cout << f[cnt0][tar] / 2 << endl;
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}