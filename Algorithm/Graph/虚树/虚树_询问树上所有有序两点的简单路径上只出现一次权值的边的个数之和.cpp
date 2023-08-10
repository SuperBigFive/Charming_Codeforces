#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 5e5 + 5;
const int M = 30;

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

int n, tot;
ll ans;
int dfn[N], bot[N], siz[N], dep[N];
int dp[N][2], fa[N][M];
vector <int> col[N];
vector <pair <int, int> > G[N], nG[N];
map <pair <int, int>, int> chk;

void init () {ans = tot = 0;}

void DP (int f, int u) {
  dp[u][1] = 0, dp[u][0] = siz[u] - 1;
  for (auto [v, w] : nG[u]) {
    if (v == f) continue;
    else dp[u][0] -= siz[v];
  }
  for (auto [v, w] : nG[u]) {
    if (v == f) continue;
    DP (u, v);
    if (w == 1) {
      ans += 1ll * (dp[v][0] + 1) * dp[u][0];
      dp[u][1] += dp[v][0] + 1;
    }
    else {
      ans += 1ll * dp[u][0] * dp[v][1];
      ans += 1ll * dp[u][1] * (dp[v][0] + 1);
      dp[u][0] += dp[v][0] + 1;
      dp[u][1] += dp[v][1];
    }
  }
  ans += dp[u][1];
}

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

void DFS (int f, int u, int d) {
  dfn[u] = ++tot, fa[u][0] = f, dep[u] = d, siz[u] = 1;
  for (int i = 1; i < M; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (auto [v, w] : G[u]) {
    if (v == f) continue;
    DFS (u, v, d + 1);
    siz[u] += siz[v];
  }
  bot[u] = tot;
}

void charming () {
  init ();
  n = read ();
  for (int i = 1, u, v, w; i < n; ++i) {
    u = read (), v = read (), w = read ();
    G[u].emplace_back (make_pair (v, w));
    G[v].emplace_back (make_pair (u, w));
    col[w].emplace_back (u);
    col[w].emplace_back (v);
    chk[make_pair (u, v)] = w;
    chk[make_pair (v, u)] = w;
  }
  DFS (0, 1, 1);
  for (int i = 1; i <= n; ++i) if (col[i].size ()) {
    col[i].emplace_back (1);
    vector <int> node;
    for (int v : col[i]) {
      node.emplace_back (v);
    }
    sort (node.begin (), node.end (), [&] (int &x, int &y) {return dfn[x] < dfn[y];});
    for (int j = 1, lca, siz = node.size (); j < siz; ++j) {
      lca = getLca (node[j - 1], node[j]);
      node.emplace_back (lca);
    }
    sort (node.begin (), node.end (), [&] (int &x, int &y) {return dfn[x] < dfn[y];});
    node.resize (unique (node.begin (), node.end ()) - node.begin ());
    vector <int> stk (1, node[0]);
    for (int j = 1, u, v, siz = node.size (); j < siz; ++j) {
      v = node[j];
      while (!stk.empty () && bot[stk.back ()] < dfn[v]) stk.pop_back ();
      if ((int) stk.size ()) {
        u = stk.back ();
        nG[u].emplace_back (make_pair (v, chk.count (make_pair (u, v)) 
        && chk[make_pair (u, v)] == i));
      }
      stk.emplace_back (v);
    }
    
    DP (0, node[0]);
    for (int v : node) {
      nG[v].clear ();
      dp[v][0] = dp[v][1] = 0;
    }
  }
  printf ("%lld\n", ans);
}

signed main () {
  charming ();
  return 0;
}