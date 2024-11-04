#include<bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

namespace Tree {
  int tot;
  std::vector<int> dfn, fa, dep, siz, son, top;
  std::vector<std::vector<int> > G;

  void Init(int n, std::vector<std::vector<int> > &_G) {
    tot = 0;
    dfn = fa = dep = siz = top = std::vector<int> (n);
    son = std::vector<int> (n, -1);
    G = _G;
  }

  void DFS1(int f, int u, int d) {
    fa[u] = f, dep[u] = d, siz[u] = 1;
    for (int v : G[u]) {
      if (v == f) continue;
      else {
        DFS1 (u, v, d + 1);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
      }
    }
  }

  void DFS2(int f, int u, int t) {
    dfn[u] = ++tot, top[u] = t;
    if (son[u] != -1) DFS2 (u, son[u], t);
    for (int v : G[u]) {
      if (v == f || v == son[u]) continue;
      else {
        DFS2 (u, v, v);
      }
    }
  }

  int getLca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
      u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
  }
}

namespace SegmentTree {
  std::vector<int> sum;

  void Init(int n) {
    sum = std::vector<int>(n << 2);
  }

  void Modify(int rt, int l, int r, int p, int k) {
    sum[rt] += k;
    if (l == r) return;
    int mid = l + r >> 1;
    if (p <= mid) Modify(rt << 1, l, mid, p, k);
    else Modify(rt << 1 | 1, mid + 1, r, p, k);
  }

  int Query(int rt, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return sum[rt];
    int mid = l + r >> 1, ans = 0;
    if (ql <= mid) ans += Query(rt << 1, l, mid, ql, qr);
    if (qr > mid) ans += Query(rt << 1 | 1, mid + 1, r, ql, qr);
    return ans;
  }
}

void charming() {
  int n, q; std::cin >> n >> q;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) std::cin >> c[i];
  std::vector<std::vector<int> > G(n);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v, --u, --v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  
  Tree::Init(n, G), Tree::DFS1(-1, 0, 0), Tree::DFS2(-1, 0, 0);
  SegmentTree::Init(n);
  std::set<int> s;
  std::vector<int> ban(n);
  for (int u = 0; u < n; ++u) {
    if (c[u] == 1) {
      SegmentTree::Modify(1, 0, n, Tree::dfn[u], 1);
      bool chk = true;
      for (int v : G[u]) {
        if (v == Tree::fa[u]) continue;
        else {
          if (c[v] == 1) {chk = false; break;}
        }
      }
      if (chk) s.insert(u);
			if (Tree::fa[u] != -1) ++ban[Tree::fa[u]];
    }
  }

  for (int i = 0, u, f; i < q; ++i) {
    std::cin >> u, --u;
    if (c[u] == 0) {
      SegmentTree::Modify(1, 0, n, Tree::dfn[u], 1);
      if (s.count(Tree::fa[u])) {
        s.erase(Tree::fa[u]);
      }
			if (Tree::fa[u] != -1) {
				++ban[Tree::fa[u]];
			}
      if (!ban[u]) {
        s.insert(u);
      }
    }
    else {
      SegmentTree::Modify(1, 0, n, Tree::dfn[u], -1);
			if (Tree::fa[u] != -1) {
				--ban[Tree::fa[u]];
			}
      if (s.count(u)) {
        s.erase(u);
      }
      if (Tree::fa[u] != -1 && c[Tree::fa[u]] == 1 && !ban[Tree::fa[u]]) {
        s.insert(Tree::fa[u]);
      }
    }

    c[u] ^= 1;
    if ((int)s.size() == 1) std::cout << "YES" << std::endl;
    else if ((int)s.size() == 2) {
      int v1 = *s.begin(), v2 = *s.rbegin();
      int lca = Tree::getLca(v1, v2);
      int cnt = Tree::dep[v1] + Tree::dep[v2] - 2 * Tree::dep[lca] + 2;
			if (cnt - 1 != SegmentTree::sum[1]) {
				std::cout << "NO" << std::endl;
			}
			else {
				for (int v : {v1, v2}) {
					while(Tree::top[v] != Tree::top[lca]) {
						cnt -= SegmentTree::Query(1, 0, n, Tree::dfn[Tree::top[v]], Tree::dfn[v]);
						v = Tree::fa[Tree::top[v]];
					}
					cnt -= SegmentTree::Query(1, 0, n, Tree::dfn[lca], Tree::dfn[v]);
				}
				if (cnt) std::cout << "NO" << std::endl;
				else std::cout << "YES" << std::endl;
			}
    }
    else std::cout << "NO" << std::endl;
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}