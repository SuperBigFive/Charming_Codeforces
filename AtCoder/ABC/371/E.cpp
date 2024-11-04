#include <bits/stdc++.h>

void charming() {
  int n; std::cin >> n;
  std::vector pos(n, std::vector<int> ());
  for (int i = 0, a; i < n; ++i) {
    std::cin >> a, --a;
    pos[a].emplace_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) if (!pos[i].empty()) {
    pos[i].emplace_back(n);
    int lst = -1;
    long long nans = 1ll * n * (n + 1) / 2;
    for (int x : pos[i]) {
      int l = x - lst - 1;
      nans -= 1ll * l * (l + 1) / 2;
      lst = x;
    }
    ans += nans;
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