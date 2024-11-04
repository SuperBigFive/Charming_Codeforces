#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

void charming() {
  int n; std::cin >> n;
  std::vector<std::vector<int> > G(n);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v, --u, --v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int ans = 0;
  std::vector<std::array<int, 2> > dp(n);

  auto DFS1 = [&](auto &&self, int f, int u) -> void {
    dp[u][1] = 1;
    for (int v : G[u]) {
      if (v == f) continue;
      else {
        self(self, u, v);
        dp[u][0] += std::max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
      }
    }
  };
  DFS1(DFS1, -1, 0);

  auto DFS2 = [&](auto &&self, int f, int u) -> void {
    std::array<int, 2> dp_u_bak = dp[u];
    dp[u][0] = 0, dp[u][1] = 1;
    for (int v : G[u]) {
      dp[u][0] += std::max(dp[v][0], dp[v][1]);
      dp[u][1] += dp[v][0];
    }
    ans = std::max({ans, dp[u][1], dp[u][0] + (G[u].size() == 1)});

    for (int v : G[u]) {
      if (v == f) continue;
      else {
        dp[u][0] -= std::max(dp[v][0], dp[v][1]);
        dp[u][1] -= dp[v][0];
        self(self, u, v);
        dp[u][0] += std::max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
      }
    }

    dp[u] = dp_u_bak;
  };
  DFS2(DFS2, -1, 0);

  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}