#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n, m;
string s1, s2;

void init () {}

void charming () {
  init ();
  cin >> n >> m >> s1 >> s2;
  bool chk1 = true;
  for (int i = 0; i < n - 1; ++i) {
    if (s1[i] == s1[i + 1]) chk1  = false;
  }
  bool chk2 = (s2[0] == s2[m - 1]);
  for (int i = 0; i < m - 1; ++i) {
    if (s2[i] == s2[i + 1]) chk2 = false;
  }
  if (chk1) puts ("YES");
  else {
    if (!chk2) puts ("NO");
    else {
      bool ok = true;
      for (int i = 0; i < n - 1; ++i) {
        if (s1[i] == s1[i + 1]) {
          if (s1[i] == s2[0]) {ok = false; break;}
        }
      }
      if (ok) puts ("YES");
      else puts ("NO");
    }
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}