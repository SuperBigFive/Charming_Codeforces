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

int t, n;
string s;

void init () {}

void charming () {
  init ();
  cin >> s, n = s.size ();
  string ans1, ans2;
  for (char ch : s) ans1 += '(', ans1 += ')';
  for (char ch : s) ans2 += '(';
  for (char ch : s) ans2 += ')';
  if (s == (string) "()") cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    bool ok = (s == ans1.substr (0, n) || s == ans1.substr (1, n));
    if (ok) cout << ans2 << endl;
    else cout << ans1 << endl;
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