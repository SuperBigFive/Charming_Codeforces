#include <bits/stdc++.h>
using ll = long long;
const int N = 4e6 + 5;

void charming() {
  #define tree FinwickTree

  int n, d; std::cin >> n >> d;
  std::vector<std::vector<int> > point_row(N), point_col(N);
  for (int i = 0, x, y; i < n; ++i) {
    std::cin >> x >> y, x += 2e6 + 1, y += 2e6 + 1;
    point_row[x].emplace_back(y);
    point_col[y].emplace_back(x);
  }
  int bot = 0, above = n;
  ll dis = 0;
  for (int i = 1; i < N; ++i) dis += (int)point_row[i].size() * i;
  std::vector<ll> all_dis;
  for (int i = 1; i < N; ++i) {
    dis += bot - above;
    bot += (int)point_row[i].size();
    above -= (int)point_row[i].size();
    if (dis <= d) all_dis.emplace_back(dis);
  }
  if (all_dis.empty()) {
    std::cout << 0 << '\n';
    return;
  }
  sort(all_dis.begin(), all_dis.end());
  
  ll ans = 0;
  int lef = 0, rig = n;
  dis = 0;
  for (int j = 1; j < N; ++j) dis += (int)point_col[j].size() * j;
  for (int j = 1; j < N; ++j) {
    dis += lef - rig;
    lef += (int)point_col[j].size();
    rig -= (int)point_col[j].size();
    
    if (all_dis[0] + dis > d) continue;

    int l = 0, r = (int)all_dis.size() - 1, k = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (all_dis[mid] + dis <= d) l = mid + 1, k = mid;
      else r = mid - 1;
    }

    ans += k + 1;
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