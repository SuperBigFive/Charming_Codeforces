#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  
  auto DFS = [&](auto &&self, int idx, int mid, std::vector<int> &dp) -> int {
    if (idx >= n) return 0;
    else if ((idx % k) >= ((n - 1) % k + 1)) return 0;
    else if (dp[idx] != -1) return dp[idx];
    else {
      dp[idx] = std::max(self(self, idx + k, mid, dp),
      ((idx + 1) % k ? self(self, idx + 1, mid, dp) : 0) + (a[idx] >= mid));
      return dp[idx];
    }
  };

  auto Check = [&](int mid) -> bool {
    std::vector<int> dp(n, -1);
    DFS(DFS, 0, mid, dp);
    return dp[0] >= ((n + k - 1) % k + 1) / 2 + 1;
  };

  int l = 1, r = 1e9, ans = 1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (Check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
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
