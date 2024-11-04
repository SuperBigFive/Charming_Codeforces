#include<bits/stdc++.h>
#define ll long long

void charming() {
  int n, d; std::cin >> n >> d;
  std::map<int, std::set<std::pair<int, int> > > mp1, mp2;
  std::vector<std::pair<int, int> > point;
  for (int i = 0, x, y; i < n; ++i) {
    std::cin >> x >> y;
    point.emplace_back(std::make_pair(x, y));
    mp1[x - y].insert(std::make_pair(x, i)); // '/'
    mp2[x + y].insert(std::make_pair(x, i)); // '\'
  }

  auto solve = [&] (std::set<std::pair<int, int> > &s, int l, int r) -> std::vector<int> {
    if ((int) s.size() == 0 || (*s.begin()).first > r || (*s.rbegin()).first < l) return std::vector<int>();
    auto it = s.lower_bound(std::make_pair(l, -1));
    std::vector<int> ret;
    while (it != s.end() && (*it).first <= r) {
      ret.emplace_back((*it).second);
      ++it;
    } 
    return ret;
  };

  std::vector<std::pair<int, int> > edge;
  for (int i = 0, x, y; i < n; ++i) {
    x = point[i].first, y = point[i].second;
    std::vector<int> ret;
    auto s1 = mp1[x - y - d];
    ret = solve(s1, x - d, x);
    for (int v : ret) edge.emplace_back(std::make_pair(std::min(i, v), std::max(i, v)));

    auto s2 = mp1[x - y + d];
    ret = solve(s2, x, x + d);
    for (int v : ret) edge.emplace_back(std::make_pair(std::min(i, v), std::max(i, v)));
    
    auto s3 = mp2[x + y - d];
    ret = solve(s3, x - d, x);
    for (int v : ret) edge.emplace_back(std::make_pair(std::min(i, v), std::max(i, v)));

    auto s4 = mp2[x + y + d];
    ret = solve(s4, x, x + d);
    for (int v : ret) edge.emplace_back(std::make_pair(std::min(i, v), std::max(i, v)));
  }
  sort(edge.begin(), edge.end());
  edge.resize(unique(edge.begin(), edge.end()) - edge.begin());
  
  std::vector<int> du(n);
  std::vector<std::vector<int> > G(n);
  for (auto [u, v] : edge) {
    du[u] += 1, du[v] += 1; 
  }
  for (auto [u, v] : edge) {
    if (du[u] < du[v] || (du[u] == du[v] && u > v)) std::swap(u, v);
    G[u].emplace_back(v);
  }

  std::vector<bool> vis(n);
  for (int u = 0; u < n; ++u) {
    for (int v : G[u]) {
      vis[v] = true;
    }
    for (int v : G[u]) {
      for (int vv : G[v]) {
        if (vis[vv]) {
          std::cout << u + 1 << " " << v + 1 << " " << vv + 1 << '\n';
          return;
        }
      }
    }
    for (int v : G[u]) {
      vis[v] = false;
    }
  }
  std::cout << 0 << " " << 0 << " " << 0 << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}