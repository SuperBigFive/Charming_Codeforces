#include<bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

void charming() {
  int n, a, b; std::cin >> n >> a >> b, --a, --b;
  std::vector<int> pre(n), dep(n);
  std::vector<std::vector<int>> G(n);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v, --u, --v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  std::vector<int> f(n), g(n);

  auto DFS1 = [&](auto &&self, int fa, int u) -> void {
    pre[u] = fa;
    for (auto v : G[u]) {
      if (v == fa) continue;
      else {
        dep[v] = dep[u] + 1;
        self(self, u, v);
        f[u] = std::max(f[u], f[v] + 1);
      }
    }
  };

  auto DFS2 = [&](auto &&self, int fa, int u) -> void {
    std::multiset<int> s;
    s.insert(-1);
    for (auto v : G[u]) {
      s.insert(f[v]);
    }
    g[u] = (*s.rbegin()) + 1;

    for (auto v : G[u]) {
      if (v == fa) continue;
      int tmp1 = f[u], tmp2 = f[v];
      s.erase(s.find(tmp2));
      f[u] = (*s.rbegin()) + 1;
      self(self, u, v);
      f[u] = tmp1;
      s.insert(tmp2);
    }
  };

  DFS1(DFS1, -1, a), DFS2(DFS2, -1, a);
  
  int ans = N;
  std::vector<int> stk;
  bool chk = false;

  auto DFS3 = [&](auto &&self, int f, int u) -> void {
    stk.emplace_back(u);
    if (u == b) {
      int siz = stk.size();
      for (int i = 0; i < (siz + 1) / 2; ++i) {
        ans = std::min(ans, siz - i - 1 - g[stk[i]]);
      }
      chk = true;
      return;
    }
    for (auto v : G[u]) {
      if (v == f) continue;
      else {
        self(self, u, v);
        if (chk) return;
      }
    }
    stk.pop_back();
  };

  DFS3(DFS3, -1, a);
  std::cout << (n - 1) * 2 + ans << std::endl;
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}