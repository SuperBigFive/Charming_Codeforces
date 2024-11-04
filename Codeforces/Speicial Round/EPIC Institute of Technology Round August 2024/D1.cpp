#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, q; std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 2; i <= n; ++i) std::cin >> a[i];
  std::vector<int> p(n + 1), rev(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> p[i], rev[p[i]] = i;

  int cnt = 0;
  std::vector<int> f(n + 1);

  std::vector<int> siz(n + 1);
  auto DFS = [&](auto &&self, int u) -> void {
    if ((u << 1) > n) siz[u] = 1;
    else {
      self(self, u << 1), self(self, u << 1 | 1);
      siz[u] = siz[u << 1] + siz[u << 1 | 1] + 1;
    }
  };
  DFS(DFS, 1);

  auto Update = [&](int idx) -> void {
    while (idx) {
      int old = f[idx];
      if ((idx << 1) > n) f[idx] = 1;
      else {
        if (f[idx << 1] && f[idx << 1 | 1] &&
        rev[idx] + 1 <= n && rev[idx] + siz[idx] / 2 <= n &&
        (p[rev[idx] + 1] == (idx << 1) && p[rev[idx] + siz[idx] / 2 + 1] == (idx << 1 | 1) ||
        p[rev[idx] + 1] == (idx << 1 | 1) && p[rev[idx] + siz[idx] / 2 + 1] == (idx << 1))) f[idx] = 1;
        else f[idx] = 0;
      }

      if (f[idx] == 1 && old == 0) ++cnt;
      else if (f[idx] == 0 && old == 1) --cnt;

      idx >>= 1;
    }
  };

  for (int i = 1; i <= n; ++i) Update(i);

  // std::cout << cnt << '\n';
  for (int i = 0, x, y; i < q; ++i) {
    std::cin >> x >> y;
    std::swap(p[x], p[y]);
    rev[p[x]] = x, rev[p[y]] = y;

    Update(p[x]), Update(p[y]);
    if (cnt == n) std::cout << "YES\n";
    else std::cout << "NO\n";

    // std::cout << cnt << '\n';
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