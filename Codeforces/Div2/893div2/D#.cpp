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

int t, n, k;
string s;

void init () {}

void charming () {
	init ();
	cin >> n >> k >> s, s = '#' + s;
  vector <int> pre0 (n + 2), pre1 (n + 2), suf1 (n + 2);
  vector <vector <int> > pref (n + 2, vector <int> (k + 2, -1));
  vector <vector <int> > suff (n + 2, vector <int> (k + 2, -1));
  for (int i = 1; i <= n; ++i) pre0[i] = pre0[i - 1] + (s[i] == '0');
  for (int i = 1; i <= n; ++i) pre1[i] = pre1[i - 1] + (s[i] == '1');
  for (int i = n; i >= 1; --i) suf1[i] = suf1[i + 1] + (s[i] == '1');
  for (int i = 0; i <= k; ++i) pref[0][i] = suff[n + 1][i] = 0;

  for (int i = 1, sum = 0, rem = 0; i <= n; ++i) {
    if (s[i] == '1') ++sum;
    else sum = 0;
    rem = max (rem, sum);
    pref[i][0] = rem;
    for (int j = 1; j <= k; ++j) {
      pref[i][j] = max (pref[i - 1][j], pref[i][j - 1]);
      while (pref[i][j] + 1 <= i && 
      (j >= (pref[i][j] + 1 - (pre1[i] - pre1[i - pref[i][j] - 1])))) {
        ++pref[i][j];
      }
    }
  }

  for (int i = n, sum = 0, rem = 0; i >= 1; --i) {
    if (s[i] == '1') ++sum;
    else sum = 0;
    rem = max (rem, sum);
    suff[i][0] = rem;
    for (int j = 1; j <= k; ++j) {
      suff[i][j] = max (suff[i + 1][j], suff[i][j - 1]);
      while (suff[i][j] + 1 <= n - i + 1 &&
      (j >= (suff[i][j] + 1 - (suf1[i] - suf1[i + suff[i][j] + 1])))) {
        ++suff[i][j];
      }
    }
  }

  vector <int> mx1 (n + 1, -1), ans (n + 1);
  mx1[0] = max (pref[n][k], suff[1][k]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j + i - 1 <= n; ++j) {
      int delta = i - pre0[j + i - 1] + pre0[j - 1];
      if (delta <= k) {
        delta = k - delta;
        mx1[i] = max ({mx1[i], pref[j - 1][delta], suff[j + i][delta]});
      }
    }
  }

  for (int i = 0; i <= n; ++i) if (mx1[i] > -1) {
    for (int j = 1; j <= n; ++j) {
      ans[j] = max (ans[j], j * i + mx1[i]);
    }
  }
  
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
	cin >> t;
  while (t--) charming ();
	return 0;
}