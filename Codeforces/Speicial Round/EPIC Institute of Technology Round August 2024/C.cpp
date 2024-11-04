#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n; std::cin >> n;
  std::vector<std::pair<int, int> > point;
  for (int i = 0, x, y; i < n; ++i) {
    std::cin >> x >> y;
    point.emplace_back(std::make_pair(x, y));
  }
  int xs, ys, xt, yt;
  std::cin >> xs >> ys >> xt >> yt;
  
  auto getDis = [](int x0, int y0, int x1, int y1) -> ll {
    ll dis = 1ll * (x0 - x1) * (x0 - x1) + 1ll * (y0 - y1) * (y0 - y1);
    return dis;
  };

  bool ok = true;
  ll dis = getDis(xs, ys, xt, yt);
  for (auto [x, y] : point) {
    if (dis >= getDis(x, y, xt, yt)) {ok = false; break;}
  }
  
  if (ok) std::puts("YES");
  else std::puts("NO");
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}