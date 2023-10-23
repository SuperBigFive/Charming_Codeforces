#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n;
string s;

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
  cin >> s;
  n = s.size ();
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      bool chk = true;
      for (int k1 = i, k2 = j; k1 < k2; ++k1, --k2) {
        if (s[k1] != s[k2]) chk = false;
      }
      if (chk) ans = max (ans, j - i + 1);
    }
  }
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}