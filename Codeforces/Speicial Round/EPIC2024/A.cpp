#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k; std::cin >> n >> k;
  std::cout << (n - 1) * k + 1 << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}