#include <bits/stdc++.h>
#define int ll
using ll = long long;

void charming() {
  int n; ll w; std::cin >> n >> w;
  std::vector<int> p(n);
  std::vector<std::vector<int> > G(n);
  for (int i = 1; i < n; ++i) {
    std::cin >> p[i], --p[i];
    G[p[i]].emplace_back(i);
  }
  std::vector<int> dep(n);
  
  auto DFS = [&](auto &&self, int u) -> void {
    for (int v : G[u]) {
      dep[v] = dep[u] + 1;
      self(self, v);
    }
  };
  DFS(DFS, 0);

  std::vector<int> cnt(n);
  std::vector<ll> dist(n);
  std::vector<std::vector<int> > vec(n);
  ll ans = w * n;
  for (int i = 0, j; i < n; ++i) {
    j = (i + 1) % n;
    int u = i, v = j, c = 0;
    while (dep[u] != dep[v]) {
      if (dep[u] < dep[v]) std::swap(u, v);
      vec[u].emplace_back(i);
      u = p[u], ++c;
    }
    while (u != v) {
      vec[u].emplace_back(i);
      vec[v].emplace_back(i);
      u = p[u], v = p[v];
      c += 2;
    }
    cnt[i] = c;
  }
  int finish = 0;
  ll sum = 0;
  for (int i = 1, x, y; i < n; ++i) {
    std::cin >> x >> y, --x;
    ans -= 1ll * (n - (int)vec[x].size() - finish) * y;
    for (int v : vec[x]) {
      --cnt[v];
			dist[v] += y;
      if (!cnt[v]) ++finish, ans = ans - (w - (sum - (dist[v] - y))) + dist[v];
    }
    sum += y;
    std::cout << ans << " \n"[i == n - 1];
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
