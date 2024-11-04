#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

void init () {}

void charming () {
  init ();
  string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
  int n;
  cin >> n;
  for (int i = 0; i <= n + 1; ++i) cout << s[i];
}

signed main () {
  charming ();
  return 0;
}