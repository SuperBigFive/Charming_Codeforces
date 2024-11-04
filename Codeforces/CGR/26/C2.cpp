#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;
const int MOD = 998244353;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n), pow2(n + 1); pow2[0] = 1;
  for (int i = 0; i < n; ++i) std::cin >> a[i], pow2[i + 1] = 2ll * pow2[i] % MOD;
  int now = 0; ll c = 0, mn = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    c += a[i];
    mn = std::min(mn, c);
  }
  if (mn >= 0) {
    std::cout << pow2[n] << '\n';
    return;
  }
  int ans = 0, cnt = 0;
  c = 0;
  for (int i = 0; i < n; ++i) {
    c += a[i];
    if (c == mn) {
      // std::cout << i << " " << mn << " " << cnt << " " << pow2[cnt] << " " << pow2[n - i - 1] << '\n';
      ans = (ans + 1ll * pow2[cnt] * pow2[n - i - 1] % MOD) % MOD;
    }
    if (c >= 0) ++cnt;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}