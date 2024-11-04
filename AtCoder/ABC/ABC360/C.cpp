#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::vector<int> > w(n);
  for (int i = 0, x; i < n; ++i) {
    std::cin >> a[i], --a[i];
  }
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    w[a[i]].emplace_back(x);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    if (w[i].size() > 0) {
      for (int x : w[i]) sum += x;
      ans += sum - (*max_element(w[i].begin(), w[i].end()));
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