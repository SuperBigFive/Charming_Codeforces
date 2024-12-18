#include <bits/stdc++.h>

void charming() {
  int n; std::cin >> n;
  int remain = 0, lst = 0;
  for (int i = 0, t, v; i < n; ++i) {
    std::cin >> t >> v;
    remain -= t - lst;
    remain = std::max(0, remain) + v;
    lst = t;
  }
  std::cout << remain << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}
