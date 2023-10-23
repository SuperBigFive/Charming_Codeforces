#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, len, tot, now;
int a[N], in[N], out[N], rev[N];
int cnt[N], vis[N], ans[N];
vector <int> G[N];

struct Query {
  int l, r, lca, qid;
  Query () {}
  Query (int l, int r, int lca, int qid) : l (l), r (r), lca (lca), qid (qid) {}
} qry[N];

struct LCA {
  int fa[N], siz[N], dep[N], son[N], top[N];

  void Init () {DFS1 (0, 1, 1), DFS2 (0, 1, 1);}
  
  void DFS1 (int f, int u, int d) {
    fa[u] = f, siz[u] = 1, dep[u] = d;
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
        DFS2 (u, v, v);
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

void DFS (int f, int u) {
  in[u] = ++tot, rev[tot] = u;
  for (int v : G[u]) {
    if (v == f) continue;
    else DFS (u, v);
  }
  out[u] = ++tot, rev[tot] = u;
}

void Add (int x) {
  if (!cnt[x]) ++now;
  ++cnt[x];
}

void Del (int x) {
  --cnt[x];
  if (!cnt[x]) --now;
}

void Move (int p) {
  vis[rev[p]] ? Del (a[rev[p]]) : Add (a[rev[p]]);
  vis[rev[p]] ^= 1;
}

void init () {}

void charming () {
  init ();
  n = read (), m = read ();
  len = sqrt (n) + 1;
  vector <int> b;
  for (int i = 1; i <= n; ++i) a[i] = read (), b.emplace_back (a[i]);
  sort (b.begin (), b.end ());
  b.resize (unique (b.begin (), b.end ()) - b.begin ());
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound (b.begin (), b.end (), a[i]) - b.begin () + 1;
  }
  for (int i = 1, u, v; i < n; ++i) {
    u = read (), v = read ();
    G[u].emplace_back (v);
    G[v].emplace_back (u);
  }
  DFS (0, 1), lca.Init ();
  for (int i = 1, u, v, l; i <= m; ++i) {
    u = read (), v = read ();
    if (in[u] > in[v]) swap (u, v);
    l = out[u] < in[v] ? lca.getLca (u, v) : -1;
    u = out[u] < in[v] ? out[u] : in[u];
    v = in[v]; 
    qry[i] = Query (u, v, l, i);
  }
  sort (qry + 1, qry + 1 + m, [&] (Query &x, Query &y) {
    if (x.l / len != y.l / len) return x.l < y.l;
    else if ((x.l / len) & 1) return x.r < y.r;
    else return x.r > y.r;
  });
  for (int i = 1, l = 1, r = 0, ql, qr, qlca, qid; i <= m; ++i) {
    ql = qry[i].l, qr = qry[i].r, qlca = qry[i].lca, qid = qry[i].qid;
    while (l > ql) Move (--l);
    while (r < qr) Move (++r);
    while (l < ql) Move (l++);
    while (r > qr) Move (r--);
    if (qlca != -1) ans[qid] = now + (cnt[a[qlca]] == 0);
    else ans[qid] = now;
  }
  for (int i = 1; i <= m; ++i) printf ("%d\n", ans[i]);
}

signed main () {
  charming ();
  return 0;
}
