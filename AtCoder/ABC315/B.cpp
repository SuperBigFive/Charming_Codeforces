#include <bits/stdc++.h>
#define ll long long
#define int ll
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

int m;

void init () {}

void charming () {
  init ();
  m = read ();
  int sum = 0;
  vector <int> d (m);
  for (int i = 0; i < m; ++i) d[i] = read (), sum += d[i];
  int mid = sum / 2 + 1;
  for (int i = 0; i < m; ++i) {
    if (mid > d[i]) mid -= d[i];
    else {
      cout << i + 1 << " " << mid << endl;
      return;
    }
  }
}

signed main () {
  charming ();
  return 0;
}