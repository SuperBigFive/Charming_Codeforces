#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 20;

int n, m;
int siz[N], dep[N], fa[N], vis[N], col[N];
int dis[N][M];
vector <int> G[N];

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

  int getDis (int u, int v) {
    return dep[u] + dep[v] - 2 * dep[getLca (u, v)];
  }
} lca;

struct Heap {
  priority_queue <int> A, B;

  void Push (int val) {A.push (val);}
  void Erase (int val) {B.push (val);}

  int getSize () {return (int) A.size () - (int) B.size ();}

  int getTop1 () {
    while (!B.empty () && A.top () == B.top ()) A.pop (), B.pop ();
    return A.top ();
  }

  int getTop2 () {
    int tmp1 = getTop1 ();
    Erase (tmp1);
    int tmp2 = getTop1 ();
    Push (tmp1);
    return tmp2;
  }

  int getMx () {return getTop1 () + getTop2 ();}
} me[N], ch[N], ans;

void init () {}

void Get_siz (int f, int u) {
  siz[u] = 1;
  for (int v : G[u]) {
    if (v == f || vis[v]) continue;
    Get_siz (u, v);
    siz[u] += siz[v];
  }
}

void Get_root (int f, int u, int sum, int &mn, int &rt) {
  int now = 0;
  for (int v : G[u]) {
    if (v == f || vis[v]) continue;
    Get_root (u, v, sum, mn, rt);
    now = max (now, siz[v]);
  }
  now = max (now, sum - siz[u]);
  if (now < mn) mn = now, rt = u;
}

void Get_me (int rt, int f, int u, int d) {
  me[rt].Push (d);
  for (int v : G[u]) {
    if (v == f || vis[v]) continue;
    Get_me (rt, u, v, d + 1);
  }
}

void Build (int u) {
  vis[u] = 1;
  int x = u;
  while (x) {
    dis[u][dep[u] - dep[x]] = lca.getDis (u, x);
    x = fa[x];
  }
  for (int v : G[u]) {
    if (vis[v]) continue;
    int mn = n, rt = 1;
    Get_siz (u, v);
    Get_root (u, v, siz[v], mn, rt);
    dep[rt] = dep[u] + 1, fa[rt] = u;
    Get_me (rt, 0, v, 1);
    ch[u].Push (me[rt].getTop1 ());
    Build (rt);
  }
  ch[u].Push (0);
  if (ch[u].getSize () >= 2) {
    ans.Push (ch[u].getMx ());
  }
}

void charming () {
  init ();
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    G[u].emplace_back (v);
    G[v].emplace_back (u);
  }
  lca.init ();
  int mn = n, rt = 1;
  Get_siz (0, 1);
  Get_root (0, 1, n, mn, rt);
  Build (rt);
  cin >> m;
  string opt;
  for (int i = 1, cnt = n, x, y; i <= m; ++i) {
    cin >> opt;
    if (opt[0] == 'G') {
      if (cnt >= 2) cout << ans.getTop1 () << endl;
      else if (cnt == 1) cout << 0 << endl;
      else cout << -1 << endl; 
    }
    else {
      cin >> x;
      if (!col[x]) {
        if (ch[x].getSize () >= 2) ans.Erase (ch[x].getMx ());
        ch[x].Erase (0);
        if (ch[x].getSize () >= 2) ans.Push (ch[x].getMx ());
        y = x;
        while (fa[y]) {
          if (ch[fa[y]].getSize () >= 2) ans.Erase (ch[fa[y]].getMx ());
          if (me[y].getSize ()) ch[fa[y]].Erase (me[y].getTop1 ());
          int val = dis[x][dep[x] - dep[fa[y]]];
          me[y].Erase (val);
          if (me[y].getSize ()) ch[fa[y]].Push (me[y].getTop1 ());
          if (ch[fa[y]].getSize () >= 2) ans.Push (ch[fa[y]].getMx ());
          y = fa[y];
        }
        --cnt;
      }
      else {
        if (ch[x].getSize () >= 2) ans.Erase (ch[x].getMx ());
        ch[x].Push (0);
        if (ch[x].getSize () >= 2) ans.Push (ch[x].getMx ());
        y = x;
        while (fa[y]) {
      
          if (ch[fa[y]].getSize () >= 2) ans.Erase (ch[fa[y]].getMx ());
          if (me[y].getSize ()) ch[fa[y]].Erase (me[y].getTop1 ());
          int val = dis[x][dep[x] - dep[fa[y]]];
          me[y].Push (val);
          ch[fa[y]].Push (me[y].getTop1 ());
          if (ch[fa[y]].getSize () >= 2) ans.Push (ch[fa[y]].getMx ());
          y = fa[y];
        }
        ++cnt;
      }
      col[x] ^= 1;
    }
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}