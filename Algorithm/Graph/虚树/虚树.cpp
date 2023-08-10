#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 20;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

int n, q, tot;
int dfn[N], rev[N], bot[N], dep[N];
int ans[N], siz[N], sum_siz[N], dp[N];
int fa[N][M];
vector <int> G[N], nG[N], node[N];
vector <pair <int, int> > qry[N];
set <int> s;

void init () {tot = 0;}

int getVal (int id, int k) {return siz[id] - 1 - k;}

int getLca (int u, int v) {
  if (dep[u] < dep[v]) swap (u, v);
  if (dep[u] > dep[v]) {
    for (int i = M - 1; i >= 0; --i) {
      if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    }
  }
  if (u == v) return u;
  for (int i = M - 1; i >= 0; --i) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  return fa[u][0];
}

ll calcSum (int u, int v, int k) {
  return (sum_siz[v] - sum_siz[u]) - 1ll * (k + 1) * (dep[v] - dep[u]);
}

void DFS1 (int f, int u, int d) {
  dfn[u] = ++tot, rev[tot] = u;
  fa[u][0] = f, dep[u] = d;
  for (int i = 1; i < M; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : G[u]) {
    if (v == f) continue;
    DFS1 (u, v, d + 1);
    ++siz[u];
  }
  bot[u] = tot;
}

void DFS2 (int f, int u) {
  sum_siz[u] += siz[u];
  for (int v : G[u]) {
    if (v == f) continue;
    sum_siz[v] += sum_siz[u];
    DFS2 (u, v);
  }
}

bool Build (int k) {
  if (!node[k].size ()) return false;
  sort (node[k].begin (), node[k].end (), [&] (int &x, int &y) {return dfn[x] < dfn[y];});
  for (int i = 1, siz = node[k].size (), lca; i < siz; ++i) {
    lca = getLca (node[k][i - 1], node[k][i]);
    node[k].emplace_back (lca);
  }
  sort (node[k].begin (), node[k].end (), [&] (int &x, int &y) {return dfn[x] < dfn[y];});
  node[k].resize (unique (node[k].begin (), node[k].end ()) - node[k].begin ());
  vector <int> stk (1, node[k][0]);
  s.insert (dfn[node[k][0]]);
  for (int i = 1, u, v, siz = node[k].size (); i < siz; ++i) {
    v = node[k][i];
    while (!stk.empty () && bot[stk.back ()] < dfn[v]) stk.pop_back ();
    if (!stk.empty ()) {
      u = stk.back ();
      nG[u].emplace_back (v);
    }
    stk.emplace_back (v);
    s.insert (dfn[v]);
  }
  return true;
}

void DP (int u, int k) {
  dp[u] = getVal (u, k);
  for (int v : nG[u]) {
    DP (v, k);
    dp[u] += max (0ll, dp[v] + calcSum (u, v, k) - getVal (v, k));
  }
}

void Solve (int k, vector <int> &node) {
  DP (node[0], k);
  for (auto [u, id] : qry[k]) {
    auto it = s.lower_bound (dfn[u]);
    if (it == s.end () || *it > bot[u]) continue;
    else {
      int v = rev[*it];
      ans[id] = max (ans[id], siz[u] + dp[v] + 
      calcSum (fa[u][0], fa[v][0], k) - getVal (u, k));
    }
  }
  for (int u : node) nG[u].clear ();
  s.clear ();
}

void charming () {
  init ();
  n = read ();
  for (int i = 1, u, v; i < n; ++i) {
    u = read (), v = read ();
    G[u].emplace_back (v);
    G[v].emplace_back (u);
  }
  DFS1 (0, 1, 1), DFS2 (0, 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= siz[i] - 1; ++j) {
      node[j].emplace_back (i);
    }
  }
  q = read ();
  for (int i = 1, v, k; i <= q; ++i) {
    v = read (), k = read ();
    ans[i] = siz[v];
    qry[k].emplace_back (make_pair (v, i));
  }
  for (int i = 0; i < N; ++i) {
    if (Build (i)) Solve (i, node[i]);
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
}

signed main () {
  charming ();
  return 0;
}