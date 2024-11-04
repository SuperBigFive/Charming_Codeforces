#include <bits/stdc++.h>

void charming() {
  int n; std::cin >> n;
  int mh; std::cin >> mh;
  std::vector vis_h(n, std::vector<int> (n));
  std::vector<std::pair<int, int> > edge_h;
  for (int i = 0, a, b; i < mh; ++i) {
    std::cin >> a >> b, --a, --b;
    vis_h[a][b] = vis_h[b][a] = 1;
    edge_h.emplace_back(std::make_pair(a, b));
  }
  std::vector vis_g(n, std::vector<int> (n));
  int mg; std::cin >> mg;
  std::vector<std::pair<int, int> > edge_g;
  for (int i = 0, u, v; i < mg; ++i) {
    std::cin >> u >> v, --u, --v;
    vis_g[u][v] = vis_g[v][u] = 1;
    edge_g.emplace_back(std::make_pair(u, v));
  }
  std::vector cost(n, std::vector<int> (n));
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) std::cin >> cost[i][j];
  int ans = INT_MAX;
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 1);
  do {
    int nans = 0;
    for (auto [u, v] : edge_g) {
    	if (u > v) std::swap(u, v);
      int nu = p[u] - 1, nv = p[v] - 1;
      if (nu > nv) std::swap(nu, nv);
      if (!vis_h[nu][nv]) nans += cost[u][v];
    }
    for (int u = 0; u < n; ++u) {
      for (int v = u + 1; v < n; ++v) if(!vis_g[u][v]) {
        int nu = p[u] - 1, nv = p[v] - 1;
        if (vis_h[nu][nv]) nans += cost[u][v];
      }
    }
    ans = std::min(ans, nans);
  } while (std::next_permutation(p.begin(), p.end()));

  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}