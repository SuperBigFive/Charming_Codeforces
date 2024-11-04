#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int l0, r0, l1, r1;
  std::cin >> l0 >> r0 >> l1 >> r1;
  if (l0 > l1) std::swap(l0, l1), std::swap(r0, r1);
  if (r0 < l1) std::cout << 1 << '\n';
  else {
    if (r1 > r0) {
      std::cout << ((l1 - l0) > 0) + (r0 - l1) + ((r1 - r0) > 0) << '\n';
    }
    else {
      std::cout << ((l1 - l0) > 0) + (r1 - l1) + ((r0 - r1) > 0) << '\n';
    }
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