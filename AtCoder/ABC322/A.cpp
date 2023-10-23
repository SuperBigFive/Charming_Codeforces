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
  cin >> n >> s;
  for (int i = 0; i < n - 2; ++i) {
    if (s.substr (i, 3) == "ABC") {
      cout << i + 1 << endl;
      return;
    }
  }
  cout << -1 << endl;
}

signed main () {
  charming ();
  return 0;
}