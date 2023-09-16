#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
  init ();
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    int d = -1;
    for (int j = 1; j <= 9; ++j) {
      if (n % j == 0 && i % (n / j) == 0) {d = j; break;} 
    }
    if (d == -1) cout << "-";
    else cout << d;
  }
}

signed main () {
  charming ();
  return 0;
}