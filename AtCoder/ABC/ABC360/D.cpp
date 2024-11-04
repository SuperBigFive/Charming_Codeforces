#include <bits/stdc++.h>
using ll = long long;
const int N = 2e5 + 5;
const int M = 1e9 + 5;

namespace SegmentTree {
  int sum[N << 5];

  void Modify(int rt, int l, int r, int p) {
    ++sum[rt];
  }

}

void charming() {
  int n, t; std::cin >> n >> t;
  std::string s; std::cin >> s;
  std::vector<std::pair<int, int> > ant(n);
  for (int i = 0; i < n; ++i) ant[i].second = (s[i] - '0');
  for (int i = 0; i < n; ++i) std::cin >> ant[i].first;
  sort(ant.begin(), ant.end());
  std::vector<int> pos;
  
  auto solve = [](std::vector<int> &pos, int lim) -> int {
    if (!pos.size() || pos.back() < lim) return 0;
    int l = 0, r = pos.size() - 1, k = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (pos[mid] >= lim) r = mid - 1, k = mid;
      else l = mid + 1;
    }
    return (int)pos.size() - k;
  };

  ll ans = 0;
  for (int i = 0, p, d; i < n; ++i) {
    p = ant[i].first, d = ant[i].second;
    if (d == 0) ans += solve(pos, std::max(-1ll * M, 1ll * p - 2ll * t));
    else pos.emplace_back(p);
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