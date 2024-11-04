#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, m; std::cin >> n >> m;
  int sum = 0;
  std::vector<std::vector<int> > a(n);
  for (int i = 0, l; i < n; ++i) {
    std::cin >> l, sum += l;
    a[i] = std::vector<int> (l);
    for (int j = 0; j < l; ++j) std::cin >> a[i][j];
  }
  std::vector<std::vector<int> > G(sum + 2), revG(sum + 2);
  std::vector<int> vis(sum + 2), du(sum + 2);
  for (int i = 0, l; i < n; ++i) {
    for (int x : a[i]) if (x < sum + 2) vis[x] = 1;
    int mex0 = 0;
    while (vis[mex0]) ++mex0;
    int mex1 = mex0 + 1;
    while (vis[mex1]) ++mex1;
    G[mex0].emplace_back(mex1);
    revG[mex1].emplace_back(mex0);
    // std::cout << mex1 << " -> " << mex0 << '\n';
    for (int x : a[i]) if (x < sum + 2) vis[x] = 0;
    ++du[mex0];
  }

  std::vector<int> f(sum + 2, -1), q;
  int head = 0, tail = 0;
  for (int i = 0; i < sum + 2; ++i) if (!du[i] && !revG[i].empty()) {
    q.emplace_back(i), ++tail, f[i] = i;
  }
  while (head < tail) {
    int u = q[head++];
    for (int v : revG[u]) {
      --du[v];
      f[v] = std::max(f[v], f[u]);
      if (du[v] == 0) q.emplace_back(v), ++tail;
    }
  }
  int mx = *std::max_element(f.begin(), f.end());
  int other = 0;
  for (int i = 0; i <= sum; ++i) {
    if (f[i] != -1) {
      // std::cout << i << ' ' << f[i] << ' ' << G[i].size() << '\n';
      if ((int)G[i].size() > 1) other = std::max(other, f[i]);
      else if (G[i].size() == 1) other = std::max(other, i);
    }
  }
  ll ans = 0;
  for (int i = 0; i <= std::min(m, sum); ++i) {
    // std::cout << i << ' ' << other << ' ' << f[i] << '\n';
    ans += std::max({other, i, f[i]});
  }
  if (m > sum) ans += 1ll * (m + sum + 1) * (m - sum) / 2;
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