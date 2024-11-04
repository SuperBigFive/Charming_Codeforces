#include <bits/stdc++.h>
#define ll long long
const int N = 18;

void charming() {
  int n; std::cin >> n;
  std::vector<int>dp(1 << n, -1);
  std::vector<std::pair<int, int>> card(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> card[i].first >> card[i].second;
  }

  auto DFS = [&](auto &&self, int st) -> bool {
    if (dp[st] != -1) return dp[st];
    std::vector<int> remain;
    for (int i = 0; i < n; ++i) {
      if (st & (1 << i)) remain.emplace_back(i);
    }
    int siz = remain.size();
    for (int i = 0, pi; i < siz; ++i) {
      pi = remain[i];
      for (int j = 0, pj; j < siz; ++j) {
        pj = remain[j];
        if (i == j) continue;
        else if (card[pi].first == card[pj].first ||
        card[pi].second == card[pj].second) {
          int nst = st - (1 << pi) - (1 << pj);
          if (!self(self, nst)) return dp[st] = 1;
        }
      }
    }
    return dp[st] = 0;
  };

  if (DFS(DFS, (1 << n) - 1)) std::cout << "Takahashi";
  else std::cout << "Aoki";
}

signed main() {
  charming();
  return 0;
}
