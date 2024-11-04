#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int> > nxt(n), revG(n);
  for (int i = 0; i < n - 1; ++i) {
    nxt[i].emplace_back(i + 1);
    revG[i + 1].emplace_back(i);
  }
  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v, --u, --v;
    nxt[u].emplace_back(v);
    revG[v].emplace_back(u);
  }

  std::vector<int> dis(n, INT_MAX), tag(n + 1);
  for (int i = 0; i < n; ++i) {
    if (!i) dis[i] = 0;
    else {
      for (int v : revG[i]) dis[i] = std::min(dis[i], dis[v] + 1);
    }
    int far = -1;
    for (int v : nxt[i]) far = std::max(far, v);
    if (far > -1) {
      int l = i + 1, r = far - (dis[i] + 1) - 1;
      if (l <= r) ++tag[l], --tag[r + 1];
    }
  }
  int sum = 0;
  std::string ans;
  for (int i = 0; i < n - 1; ++i) {
    sum += tag[i];
    ans += '0' + (sum == 0);
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
