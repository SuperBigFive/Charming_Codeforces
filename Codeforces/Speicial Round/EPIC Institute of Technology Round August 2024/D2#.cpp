#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, q; std::cin >> n >> q;
  std::vector<int> fa(n, -1);
  std::vector<std::vector<int> > G(n);
  for (int i = 1, f; i < n; ++i) {
    std::cin >> f, --f, fa[i] = f;
    G[f].emplace_back(i);
  }
  std::vector<int> p(n), pos(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i], --p[i];
    pos[p[i]] = i;
  }
  std::vector<int> siz(n);
  
  auto DFS = [&](auto &&self, int u) -> void {
    siz[u] = 1;
    for (int v : G[u]) {
      self(self, v);
      siz[u] += siz[v];
    }
  };
  DFS(DFS, 0);

  int cnt = 0;
  std::vector<std::multiset<int> > s0(n), s1(n);
  std::vector<bool> flag(n, true), isLeaf(n, false);

  auto Check = [&](int u) -> void {
    if (isLeaf[u]) return;
    assert(!s0[u].empty() && !s1[u].empty() && s0[u].size() == s1[u].size());

    bool old = flag[u];
    bool ok = true;
    int mn = *s0[u].begin(), mx = *s1[u].rbegin();
    if (mn < pos[u] || mx > pos[u] + siz[u] - 1) flag[u] = false;
    else flag[u] = true;

    if (old ^ flag[u]) {
      if (old) ++cnt;
      else --cnt;
    }
  };

  for (int u = 0; u < n; ++u) {
    if (G[u].empty()) isLeaf[u] = true;
    else {
      for (int v : G[u]) {
        s0[u].insert(pos[v]);
        s1[u].insert(pos[v] + siz[v] - 1);
      }
      Check(u);
    }
  }


  for (int i = 0, x, y; i < q; ++i) {
    std::cin >> x >> y, --x, --y;
    int v0 = p[x], v1 = p[y];
    if (fa[v0] != -1) {
      assert(s0[fa[v0]].count(pos[v0]));
      assert(s1[fa[v0]].count(pos[v0] + siz[v0] - 1));
      s0[fa[v0]].erase(s0[fa[v0]].find(pos[v0]));
      s1[fa[v0]].erase(s1[fa[v0]].find(pos[v0] + siz[v0] - 1));
    }
    if (fa[v1] != -1) {
      assert(s0[fa[v1]].count(pos[v1]));
      assert(s1[fa[v1]].count(pos[v1] + siz[v1] -1));
      s0[fa[v1]].erase(s0[fa[v1]].find(pos[v1]));
      s1[fa[v1]].erase(s1[fa[v1]].find(pos[v1] + siz[v1] - 1));
    }
    std::swap(p[x], p[y]);
    pos[p[x]] = x, pos[p[y]] = y;
    v0 = p[x], v1 = p[y];
    if (fa[v0] != -1) {
      s0[fa[v0]].insert(pos[v0]);
      s1[fa[v0]].insert(pos[v0] + siz[v0] - 1);
    }
    if (fa[v1] != -1) {
      s0[fa[v1]].insert(pos[v1]);
      s1[fa[v1]].insert(pos[v1] + siz[v1] - 1);
    }

    Check(v0), Check(v1);
    if (fa[v0] != -1) Check(fa[v0]);
    if (fa[v1] != -1) Check(fa[v1]);
    
    if (!cnt) std::cout << "Yes\n";
    else std::cout << "No\n";
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
