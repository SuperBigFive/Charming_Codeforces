#include <bits/stdc++.h>

void charming() {
  int n; std::cin >> n;
  std::vector<int> p(n), a(n), rev(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i], --p[i];
  for (int i = 0; i < n; ++i) std::cin >> a[i], --a[i], rev[a[i]] = i;
  std::vector<int> vis(n, -1);
  std::vector circles(0, std::vector<std::pair<int, int> > ());
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (vis[i] == -1) {
      int now = i; vis[i] = cnt;
      std::vector<std::pair<int, int> > new_circle;
      new_circle.emplace_back(std::make_pair(i, a[i]));
      while (vis[p[now]] == -1) {
        now = p[now], vis[now] = cnt;
        new_circle.emplace_back(std::make_pair(now, a[now]));
      }
      ++cnt;
      circles.emplace_back(new_circle);
    }
  }
  std::vector<int> used(n), cd(n + 1, -1);
  for (int i = 0; i < n; ++i) if (!used[i]) {
    auto circle = circles[vis[i]];
    for (auto [x, _] : circle) used[x] = 1;
    int l = circle.size();
    int idx0 = -1, idx1 = -1, mn_pos = INT_MAX;
    for (int j = 0, x, y; j < l; ++j) {
      x = circle[j].first, y = circle[j].second;
      if (y < mn_pos) mn_pos = y, idx1 = j;
      if (x == i) idx0 = j;
    }
    int d = (idx0 - idx1 + l) % l;
    if (cd[l] != -1) d = cd[l];
    else cd[l] = d;
    std::vector<int> new_val(l);
    for (int j = 0, y; j < l; ++j) {
      y = circle[j].second;
      new_val[j] = circle[(j - d + l) % l].second;
    }
    for (int j = 0, x; j < l; ++j) {
      x = circle[j].first;
      a[x] = new_val[j];
    }
    cd[l] = d;
  }
  for (int i = 0; i < n; ++i) std::cout << a[i] + 1 << " \n"[i == n - 1];
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}