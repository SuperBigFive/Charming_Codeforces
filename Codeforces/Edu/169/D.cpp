#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, q; std::cin >> n >> q;
  std::vector<std::pair<char, char> > col(n);
  std::map<std::pair<char, char>, std::set<int> > pos;
  for (int i = 0; i < n; ++i) {
    std::string s; std::cin >> s;
    col[i].first = s[0], col[i].second = s[1];
    if (col[i].first > col[i].second) std::swap(col[i].first, col[i].second);
    pos[col[i]].insert(i);
  }

  auto Valid = [&](std::pair<char, char> x, std::pair<char, char> y) -> bool {
    if (y.first == x.first || y.first == x.second || 
    y.second == x.first || y.second == x.second) return true;
    else return false;
  };

  auto Solve = [&](int l, int r, std::pair<char, char> mid_col, int type) -> int {
    // type == 0 : find the max idx in [l, r] with color mid_col;
    // type == 1 : find the min idx in [l, r] with color mid_col;
    // std::cout << l << ' ' << r << ' ' << mid_col.first << mid_col.second << ' ' << type << '\n';

    if (pos[mid_col].empty()) return -1;
    if (l > r) return -1;

    int idx;
    if (type == 0) {
      auto it = pos[mid_col].lower_bound(r + 1);
      if (it == pos[mid_col].begin()) return -1;
      --it;
      idx = *it;
    } 
    else {
      auto it = pos[mid_col].lower_bound(l);
      if (it == pos[mid_col].end()) return -1;
      idx = *it;
    }

    if (idx < l || idx > r) return -1;
    else return idx;
  };


  std::vector<char> c = {'B', 'G', 'R', 'Y'};

  for (int i = 0, x, y; i < q; ++i) {
    std::cin >> x >> y, --x, --y;
    if (x > y) std::swap(x, y);
    
    if (Valid(col[x], col[y])) std::cout << y - x << '\n';
    else {
      int dis = INT_MAX;
      
      for (char c0 : c) {
        for (char c1 : c) if (c0 != c1) {
          std::pair<char, char> mid_col = {c0, c1};
          if (mid_col.first > mid_col.second) {
            std::swap(mid_col.first, mid_col.second);
          }

          if (Valid(col[x], mid_col) && Valid(mid_col, col[y])) {
            int idx = Solve(0, x - 1, mid_col, 0);
            if (idx != -1) dis = std::min(dis, y - idx + x - idx);
            idx = Solve(x + 1, y - 1, mid_col, 0);
            if (idx != -1) {dis = std::min(dis, y - x); break;}
            idx = Solve(y + 1, n - 1, mid_col, 1);
            if (idx != -1) dis = std::min(dis, idx - y + idx - x);
          }
        }
        if (dis <= y - x) break;
      }

      if (dis >= INT_MAX) std::cout << -1 << '\n';
      else std::cout << dis << '\n';
    }
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
