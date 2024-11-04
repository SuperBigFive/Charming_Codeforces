#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

string s, t;

void charming () {
  cin >> s >> t;
  if (t.back () == 'X') t = t.substr (0, 2);
  int n = s.size (), m = t.size ();
  for (int i = 0; i < m; ++i) {
    t[i] -= 'A'- 'a';
  }
  int p = 0;
  for (int i = 0; i < n; ++i) {
    if (p < m && s[i] == t[p]) ++p;
  }
  if (p == m) puts ("Yes");
  else puts ("No");
}

signed main () {
  charming ();
  return 0;
}