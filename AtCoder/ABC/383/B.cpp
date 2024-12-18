#include <bits/stdc++.h>

void charming() {
  int h, w, d; std::cin >> h >> w >> d;
  std::vector<std::string> s(h);
  for (int i = 0; i < h; ++i) std::cin >> s[i];
  std::vector<std::pair<int, int> > floor;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') floor.emplace_back(std::make_pair(i, j));
    }
  }

  auto CalcDis = [&](int x0, int y0, int x1, int y1) -> int {
    return abs(x0 - x1) + abs(y0 - y1);
  };

  int ans = 0;
  for (int i = 0, siz = floor.size(); i < siz; ++i) {
    int x0 = floor[i].first, y0 = floor[i].second;
    for (int j = i + 1; j < siz; ++j) {
      int x1 = floor[j].first, y1 = floor[j].second;
      int nans = 0;
      for (int p = 0; p < h; ++p) {
        for (int q = 0; q < w; ++q) if (s[p][q] == '.') {
          if (CalcDis(p, q, x0, y0) <= d || CalcDis(p, q, x1, y1) <= d) {
            ++nans;
          }
        }
      }
      ans = std::max(ans, nans);
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
