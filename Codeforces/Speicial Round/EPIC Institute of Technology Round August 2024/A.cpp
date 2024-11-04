#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, m, k; std::cin >> n >> m >> k;
  std::cout << 1ll * std::min(n, k) * std::min(m, k) << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}