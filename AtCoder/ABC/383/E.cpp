#include <bits/stdc++.h>

void charming() {
  int n, m, k; std::cin >> n >> m >> k;
  std::vector<int> cnt(n), pre(n), het(n, 1);
  std::iota(pre.begin(), pre.end(), 0);
  std::vector<std::array<int, 3> > edge;
  for (int i = 0, u, v, w; i < m; ++i) {
    std::cin >> u >> v >> w;
    --u, --v;
    edge.emplace_back((std::array<int, 3>) {u, v, w});
  }
  sort(edge.begin(), edge.end(), [](std::array<int, 3> a,
  std::array<int, 3> b) {return a[2] < b[2];});
  for (int i = 0, a; i < k; ++i) std::cin >> a, --a, ++cnt[a];
  for (int i = 0, b; i < k; ++i) std::cin >> b, --b, --cnt[b];
  
  auto find = [&](auto &&self, int u) -> int {
    if (u != pre[u]) return self(self, pre[u]);
    else return u;
  };

  long long ans = 0;
  for (auto [u, v, w] : edge) {
    int fu = find(find, u), fv = find(find, v);
    if (fu == fv) continue;
    else {
      if (1ll * cnt[fu] * cnt[fv] < 0) ans += 1ll * w * std::min(abs(cnt[fu]), abs(cnt[fv]));
      if (het[fu] < het[fv]) std::swap(fu, fv);
      pre[fv] = fu;
      cnt[fu] += cnt[fv];
      if (het[fu] == het[fv]) ++het[fu];
    }
  }

  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}
