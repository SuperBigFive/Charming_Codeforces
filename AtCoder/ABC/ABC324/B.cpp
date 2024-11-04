#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

ll read () {
  ll x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

ll n;

void init () {}

void charming () {
  init ();
  n = read ();
  while (n % 2 == 0) n /= 2;
  while (n % 3 == 0) n /= 3;
  puts (n == 1 ? "Yes" : "No");
}

signed main () {
  charming ();
  return 0;
}