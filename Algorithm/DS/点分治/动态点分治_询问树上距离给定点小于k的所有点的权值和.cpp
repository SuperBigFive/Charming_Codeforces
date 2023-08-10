#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e5 + 5;
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

int n, m, ans;
int siz[N], fa[N], vis[N], val[N], dep[N];
int dis[N][M];
vector <int> G[N];

struct SegmentTree {
  int n, tot;
  int root[N];
  int sum[N << 6], ls[N << 6], rs[N << 6];

  void Modify (int &rt, int l, int r, int p, int k) {
    if (!rt) rt = ++tot;
    sum[rt] += k;
    if (l == r) return;
    int mid = l + r >> 1;
    if (p <= mid) Modify (ls[rt], l, mid, p, k);
    else Modify (rs[rt], mid + 1, r, p, k);
  }

  int Query (int rt, int l, int r, int p) {
    if (!rt || l == r) return sum[rt];
    int mid = l + r >> 1, ans = Query (ls[rt], l, mid, p);
    if (p > mid) ans += Query (rs[rt], mid + 1, r, p);
    return ans;
  }
} Tree1, Tree2;

struct LCA {
  int dep[N], fa[N][M];
  
  void init () {DFS (0, 1, 1);}

  void DFS (int f, int u, int d) {
    dep[u] = d, fa[u][0] = f;
    for (int i = 1; i < M; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : G[u]) {
      if (v == f) continue;
      DFS (u, v, d + 1);
    }
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

  int getDis (int u, int v) {return dep[u] + dep[v] - 2 * dep[getLca (u, v)];}
} lca;

void init () {}

void Get_root (int f, int u, int sum, int &mn, int &rt) {
  siz[u] = 1;
  int chk = 0;
  for (int v : G[u]) {
    if (v == f || vis[v]) continue;
		Get_root (u, v, sum, mn, rt);
    siz[u] += siz[v];
    chk = max (chk, siz[v]);
  }
  chk = max (chk, sum - siz[u]);
  if (chk < mn) mn = chk, rt = u;
}

void DFS1 (int rt, int f, int u, int d) {
  siz[u] = 1;
  int &trt = Tree1.root[rt];
  Tree1.Modify (trt, 0, N, d, val[u]);
  for (int v : G[u]) {
    if (v == f || vis[v]) continue;
    DFS1 (rt, u, v, d + 1);
    siz[u] += siz[v];
  }
}

void DFS2 (int rt, int f, int u, int d) {
  int &trt = Tree2.root[rt];
  Tree2.Modify (trt, 0, N, d, val[u]);
  for (int v : G[u]) {
    if (v == f || vis[v]) continue;
    DFS2 (rt, u, v, d + 1);
  }
}

void Divide (int u) {
  vis[u] = 1;
  DFS1 (u, 0, u, 0);
  for (int v : G[u]) {
    if (vis[v]) continue;
    int mn = n, rt = v;
    Get_root (u, v, siz[v], mn, rt);
    DFS2 (rt, 0, v, 1);
    dep[rt] = dep[u] + 1, fa[rt] = u;
    Divide (rt);
  }
  int x = u;
  while (x) {
    dis[u][dep[u] - dep[x]] = lca.getDis (u, x);
    x = fa[x];
  }
}

void charming () {
  init ();
  n = read (), m = read ();
  for (int i = 1; i <= n; ++i) val[i] = read ();
  for (int i = 1, u, v; i < n; ++i) {
    u = read (), v = read ();
    G[u].emplace_back (v);
    G[v].emplace_back (u);
  }
  lca.init ();
  int mn = n, rt = 1;
  Get_root (0, 1, n, mn, rt);
  Divide (rt);
  for (int i = 1, lst = 0, opt, x, y, z, k, delta; i <= m; ++i) {
    opt = read (), x = read () ^ lst;
    if (opt == 0) {
      k = read () ^ lst;
      lst = z = 0, y = x;
      while (y) {
        int &trt1 = Tree1.root[y], &trt2 = Tree2.root[z]; 
				int remain = k - lca.getDis (x, y);
				if (remain >= 0) {
     	   	lst += Tree1.Query (trt1, 0, N, remain);
					lst -= Tree2.Query (trt2, 0, N, remain);
				}
        z = y, y = fa[y];
      }
      printf ("%d\n", lst);
    }
    else {
      y = read () ^ lst;
      z = x, delta = y - val[x];
      while (z) {
        int &trt1 = Tree1.root[z], &trt2 = Tree2.root[z];
        Tree1.Modify (trt1, 0, N, dis[x][dep[x] - dep[z]], delta);
        if (fa[z]) Tree2.Modify (trt2, 0, N, dis[x][dep[x] - dep[fa[z]]], delta);
        z = fa[z];
      }
      val[x] = y;
    }
  }
}

signed main () {
  charming ();
  return 0;
}