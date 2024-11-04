#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<int> p(n), rev(n), q;
  for (int i = 0; i < n; ++i) std::cin >> p[i], rev[p[i] - 1] = i;
  for (int i = 2; i <= n; ++i) q.emplace_back(i);
  q.emplace_back(1);

  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) ans[rev[i]] = q[i];

  for (int i = 0; i < n; ++i) std::cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}