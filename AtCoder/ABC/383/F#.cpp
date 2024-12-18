#include <bits/stdc++.h>

void charming() {
  int n, x, k; std::cin >> n >> x >> k;
  std::vector<std::vector<std::pair<int, int> > > product(n);
  for (int i = 0, p, u, c; i < n; ++i) {
    std::cin >> p >> u >> c, --c;
    product[c].emplace_back(std::make_pair(p, u));
  }

  std::vector<long long> f(x + 1);

  for (int i = 0; i < n; ++i) {
    std::vector<long long> nf = f;
    for (auto [p, u] : product[i]) {
      for (int j = x; j >= p; --j) {
        nf[j] = std::max({nf[j], nf[j - p] + u, f[j - p] + u + k});
      }
    }
    f = nf;
  }
  
  long long ans = *std::max_element(f.begin(), f.end());
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}
