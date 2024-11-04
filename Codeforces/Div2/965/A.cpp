#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int x, y, k; std::cin >> x >> y >> k;
  if (k & 1) {
    std::cout << x << ' ' << y << '\n';
    --k;
  }
  for (int i = 1; i <= k; ++i) {
    if (i & 1) std::cout << x + (i + 1) / 2 << ' ' << y + (i + 1) / 2 << '\n';
    else std::cout << x - i / 2 << ' ' << y - i / 2 << '\n';
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}