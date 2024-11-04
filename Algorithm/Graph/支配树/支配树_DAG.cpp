// DAG 有一个很好的性质：根据拓扑序求解,先求得的解不会对后续的解产生影响.
// 引理 6：在有向图上,v dom u 当且仅当对于任意一个 w 属于 pre(u), 均有 v dom  w.
// 证明：首先来证明充分性.考虑任意一条从 s 到 u 的路径都一定经过一个结点 w 属于 pre(u),而 v 支配这个结点,
// 因此任意一条从 s 到 u 的路径都一定经过 v,因此我们得到 v dom u.
// 然后是必要性.如果存在 w 属于 pre(u),v 不支配 w,则一定有一条从 s 到 u 的不经过 v 的路径,因此 v 不支配 u.
// 我们发现,u 的支配点一定是其所有前驱结点在支配树上的公共祖先,
// 那么显然 u 的直接支配点是所有前驱结点在支配树上的 LCA.考虑倍增求解 LCA 可以支持每次添加一个结点.

std::stack<int> sta;
vector<int> e[N], g[N], tree[N];  // g 是原图的反图, tree 是支配树
int in[N], tpn[N], dep[N], idom[N];
int fth[N][17];

void topo() {
  for (int i = 1; i <= n; ++i) {
    if (!in[i]) {
      sta.push(i);
    }
  }
  while (!sta.empty()) {
    int u = sta.top();
    sta.pop();
    tpn[++tot] = u;
    for (int v : e[u]) {
      --in[v];
      if (!in[v]) {
        s.push(v);
      }
    }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) {
    std::swap(u, v);
  }
  for (int i = 15; i >= 0; --i) {
    if (dep[fth[u][i]] >= dep[v]) {
      u = fth[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = 15; i >= 0; --i) {
    if (fth[u][i] != fth[v][i]) {
      u = fth[u][i];
      v = fth[v][i];
    }
  }
  return fth[u][0];
}

void build() {
  topo();
  for (int i = 1; i <= n; ++i) {
    int u = tpn[i], v = g[x][0];
    for (int j = 1, q = g[x].size(); j < q; ++j) {
      v = lca(v, g[x][j]);
    }
    idom[u] = v;
    tree[v].push_back(u);
    fth[u][0] = v;
    dep[u] = dep[v] + 1;
    for (int i = 1; i <= 15; ++i) {
      fth[u][i] = fth[fth[u][i - 1]][i - 1];
    }
  }
}
