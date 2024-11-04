#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, t, a; std::cin >> n >> t >> a;
  if (std::max(t, a) >= (n + 1) / 2) std::cout << "Yes\n";
  else std::cout << "No\n";
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}