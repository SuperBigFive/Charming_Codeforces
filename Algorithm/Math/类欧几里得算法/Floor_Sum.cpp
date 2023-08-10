#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

ll Floor_Sum (int a, int b, int c, int n) {
  ll ans = 0;
  if (a >= c) {
    ans = (ans + n * (n + 1) / 2 * (a / c)) % MOD;
    a %= c;
  }
  if (b >= c) {
    ans = (ans + (n + 1) * (b / c)) % MOD;
    b %= c;
  }
  ll m = (a * n + b) / c;
  if (m) ans = (ans + m * n - Floor_Sum (c, c - b - 1, a, m - 1)) % MOD;
  return ans;
}

void init () {}

signed main () {
  return 0;
}