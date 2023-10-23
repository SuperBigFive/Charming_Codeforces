#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int M = 305;
const int MOD = 1e9 + 7;

int n, q, k, m, rt;
int dp[2][M];
vector <int> G[N];

struct LCA {
  int fa[N], dep[N], siz[N], son[N], top[N];
  
  void init () {DFS1 (0, 1, 1); DFS2 (0, 1, 1);}
  
  void DFS1 (int f, int u, int d) {
    fa[u] = f, dep[u] = d, siz[u] = 1, son[u] = 0;
    for (int v : G[u]) {
      if (v == f) continue;
      else {
        DFS1 (u, v, d + 1);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
      }
    }
  }

  void DFS2 (int f, int u, int t) {
    top[u] = t;
    if (son[u]) {
      DFS2 (u, son[u], t);
      for (int v : G[u]) {
        if (v == f || v == son[u]) continue;
        else DFS2 (u, v, v);
      }
    }
  }

  int getLca (int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) swap (u, v);
      u = fa[top[u]];
    }
    return dep[u] <= dep[v] ? u : v;
  }
} lca;

struct VirtualTree {
  int tot = 0;
  int dfn[N], bot[N], key[N];
  vector <int> nG[N];
  
  VirtualTree () {tot = 0; DFS1 (0, 1);}

  void DFS1 (int f, int u) {
    dfn[u] = ++tot;
    for (int v : G[u]) {
      if (v == f) continue;
      else DFS1 (u, v);
    }
    bot[u] = tot;
  }

  void Build (vector <int> &vec) {
    sort (vec.begin (), vec.end (), [&] (int x, int y) {return dfn[x] < dfn[y];});
    for (int i = 0, siz = vec.size (); i < siz - 1; ++i) {
      vec.emplace_back (lca.getLca (vec[i], vec[i + 1]));
    }
    sort (vec.begin (), vec.end (), [&] (int x, int y) {return dfn[x] < dfn[y];});
    vec.resize (unique (vec.begin (), vec.end ()) - vec.begin ());
    vector <int> stk (1, vec[0]);
    for (int i = 1, siz = vec.size (); i < siz; ++i) {
      int u = vec[i];
      while (bot[stk.back ()] < dfn[u]) stk.pop_back ();
      nG[stk.back ()].emplace_back (u);
      nG[u].emplace_back (stk.back ());
      stk.emplace_back (u);
    }
  }

  void DFS2 (int f, int u, int cnt, int &idx, int &ans) {
    if (key[u]) {
      int sum = 0;
      for (int j = 0; j <= min (m, cnt); ++j) dp[idx][j] = 0;
      for (int j = cnt + 1; j <= m; ++j) {
        dp[idx][j] = (dp[idx ^ 1][j - 1] + 1ll * dp[idx ^ 1][j] 
        * (j - cnt) % MOD) % MOD;
        sum = (sum + dp[idx][j]) % MOD;
      }
      ans = sum;
    } else idx ^= 1;
    for (int v : nG[u]) {
      if (v == f) continue;
      else idx ^= 1, DFS2 (u, v, cnt + key[u], idx, ans);
    } 
  }

  int Solve (vector <int> &vec) {
    for (int x : vec) key[x] = 1;
    vec.emplace_back (rt);
    dp[0][0] = 1;
    int idx = 1, ans = 0;
    Build (vec), DFS2 (0, rt, 0, idx, ans);
    for (int i = 0; i <= m; ++i) dp[0][i] = dp[1][i] = 0;
    for (int x : vec) key[x] = 0, nG[x].clear ();
    return ans;
  }
};

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

void init () {}

void charming () {
  init ();
  n = read (), q = read ();
  for (int i = 1, u, v; i < n; ++i) {
    u = read (), v = read ();
    G[u].emplace_back (v);
    G[v].emplace_back (u);
  }
  lca.init ();
  VirtualTree vtree;
  for (int i = 1; i <= q; ++i) {
    k = read (), m = read (), rt = read ();
    vector <int> vec;
    for (int j = 1; j <= k; ++j) vec.emplace_back (read ());
    printf ("%d\n", vtree.Solve (vec));
  }
}

signed main () {
  charming ();
  return 0;
}