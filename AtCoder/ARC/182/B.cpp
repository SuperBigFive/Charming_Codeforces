#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k; std::cin >> n >> k;

  std::vector<int> ans;
  ans.emplace_back(1);
  for (int len = 2; len <= k; ++len) {
    int now = (1 << (len - 1)) + 1, lim = 1 << len;
    while (now < lim && (int)ans.size() < n) {
      ans.emplace_back(now), now += 2;
    }
    if ((int)ans.size() >= n) break;
  }
  for (int &x : ans) while ((x << 1) < (1 << k)) x <<= 1;
  while ((int)ans.size() < n) ans.emplace_back(1);
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