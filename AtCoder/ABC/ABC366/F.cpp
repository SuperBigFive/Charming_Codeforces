#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k; std::cin >> n >> k;
  std::vector<std::pair<int, int> > line(n);
  for (int i = 0, a, b; i < n; ++i) {
    std::cin >> a >> b;
    line[i] = std::make_pair(a, b);
  }
  sort(line.begin(), line.end(), [](std::pair<int, int> &x,
  std::pair<int, int> &y) {
    return (x.first - 1) * y.second < (y.first - 1) * x.second;
  });
  
  std::vector<std::vector<ll> > dp(n, std::vector<ll> (k + 1));
  dp[0][1] = line[0].first + line[0].second;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1];
    dp[i][1] = std::max(dp[i][1], 1ll * line[i].first + line[i].second);
    for (int j = 2; j <= k; ++j) {
      dp[i][j] = std::max(dp[i][j], 1ll * line[i].first * dp[i - 1][j - 1] + line[i].second);
    }
  }
  
  std::cout << dp[n - 1][k] << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}