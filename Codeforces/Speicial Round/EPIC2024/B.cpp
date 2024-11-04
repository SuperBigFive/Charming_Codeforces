#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  int mx = -1;
  std::vector<int> b;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (i) {
      if (a[i] < mx) b.emplace_back(mx - a[i]);
    }
    mx = std::max(mx, a[i]);
  }
  sort(b.begin(), b.end());
  int siz = b.size();
  ll ans = 0;
  for (int i = 0, lst = 0; i < siz; ++i) {
    ans += 1ll * (b[i] - lst) * (siz - i + 1);
    lst = b[i];
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