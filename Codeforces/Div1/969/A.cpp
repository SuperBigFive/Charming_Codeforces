#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<std::vector<int> > G(n);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v, --u, --v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  std::string s; std::cin >> s;

  std::vector<int> leaf;
  auto DFS = [&](auto &&self, int f, int u) -> void {
    int son_cnt = 0;
    for (int v : G[u]) {
      if (v == f) continue;
      else {
        ++son_cnt;
        self(self, u, v);
      }
    }
    if (son_cnt == 0 && u) leaf.emplace_back(u);
  };
  DFS(DFS, -1, 0);

  int cnt0 = 0, cnt1 = 0, cnt2 = 0, other = 0;
  for (int i = 1; i < n; ++i) other += (s[i] == '?');
  for (int v : leaf) {
    if (s[v] == '0') ++cnt0;
    else if (s[v] == '1') ++cnt1;
    else ++cnt2, --other;
  }
  if (s[0] == '?') {
    int ans = std::max(cnt0, cnt1) + cnt2 / 2;
    if (cnt0 == cnt1 && (other & 1) && (cnt2 & 1)) ++ans;
    std::cout << ans << '\n';
  }
  else {
    if (s[0] == '1') {
      cnt0 += (cnt2 + 1) / 2;
      std::cout << cnt0 << '\n';
    } 
    else {
      cnt1 += (cnt2 + 1) / 2;
      std::cout << cnt1 << '\n';
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