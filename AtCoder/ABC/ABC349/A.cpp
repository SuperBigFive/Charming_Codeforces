#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n;

void charming () {
  cin >> n;
  int ans = 0;
  for (int i = 1, x; i < n; ++i) cin >> x, ans += x;
  cout << -ans << endl;
}

signed main () {
  charming ();
  return 0;
}