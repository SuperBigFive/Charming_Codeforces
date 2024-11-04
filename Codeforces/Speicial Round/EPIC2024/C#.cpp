#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<int> h(n);
  for (int i = 0; i < n; ++i) std::cin >> h[i];
  int ans = h[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    ans = std::max(ans + 1, h[i]);
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
