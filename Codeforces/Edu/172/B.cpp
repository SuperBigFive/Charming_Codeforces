#include <bits/stdc++.h>

void charming() {
  int n; std::cin >> n;
  std::vector<int> c(n), cnt(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i], --c[i];
    ++cnt[c[i]];
  }
  int c1 = 0, m = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 1) ++c1;
    if (cnt[i] > 0) ++m;
  }
  int ans = (c1 + 1) / 2 * 2 + m - c1;
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
