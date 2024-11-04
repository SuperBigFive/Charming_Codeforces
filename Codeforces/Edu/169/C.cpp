#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  sort(a.begin(), a.end(), [](int x, int y) {return x > y;});
  ll ans = 0;
  for (int i = 0; i < n; i += 2) {
    ans += a[i];
    if (i + 1 < n) ans -= a[i + 1];
  }
  ans = std::max(std::max(1ll * a[n - 1] * (n & 1), ans - k), 0ll);
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