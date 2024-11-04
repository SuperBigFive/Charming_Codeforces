#include <bits/stdc++.h>
using ll = long long;
const int N = 1e6 + 5;

void charming() {
  int q; std::cin >> q;
  int ans = 0;
  std::vector<int> cnt(N);
  for (int i = 0, opt, x; i < q; ++i) {
    std::cin >> opt;
    if (opt == 1) {
      std::cin >> x;
      ++cnt[x];
      if (cnt[x] == 1) ++ans;
    }
    else if (opt == 2) {
      std::cin >> x;
      --cnt[x];
      if (cnt[x] == 0) --ans;
    }
    else std::cout << ans << '\n';
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}