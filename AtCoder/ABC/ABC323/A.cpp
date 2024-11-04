#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

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
  cin >> s, s = '#' + s;
  bool chk = true;
  for (int i = 2; i <= 16; i += 2) if (s[i] != '0') chk = false;
  puts (chk ? "Yes" : "No");
}

signed main () {
  charming ();
  return 0;
}
