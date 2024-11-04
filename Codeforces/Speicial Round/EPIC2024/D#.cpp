#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0, x; i < n; ++i) std::cin >> x, ++b[x - 1];
  std::vector<int> c;
  for (int i = 0; i < n; ++i) {
    if (b[i] > 0) c.emplace_back(b[i]);
  }
  n = c.size();
  int ans = n;
  std::vector<int> f(n + 1, -1);
  f[0] = 0;
  // f[i]: 删除 i 个数后所用的最小步数和
  for (int i = 0; i < n; ++i) {
    for (int j = n; j >= 1; --j) {
      if (f[j - 1] != -1 && i - (f[j - 1] + j - 1) >= c[i]) {
        f[j] = (f[j] == -1 ? f[j - 1] + c[i] : std::min(f[j - 1] + c[i], f[j]));
      }
    }
  }
  for (int i = n; i >= 1; --i) {
    if (f[i] != -1) {ans = n - i; break;}
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
