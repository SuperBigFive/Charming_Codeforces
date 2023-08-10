#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, q, tot, bcc_cnt;
int dfn[N], low[N], fa[N], val[N], dep[N];
int siz[N], son[N], bot[N], top[N];
int mn[N << 2];
vector <int> G[N], nG[N];
multiset <int> s[N];

void init () {
  for (int i = 0; i < (N << 2); ++i) mn[i] = INT_MAX;
}

void Modify (int rt, int l, int r, int p, int k) {
  if (l == r) {mn[rt] = k; return;}
  int mid = l + r >> 1;
  if (p <= mid) Modify (rt << 1, l, mid, p, k);
  else Modify (rt << 1 | 1, mid + 1, r, p, k);
  mn[rt] = min (mn[rt << 1], mn[rt << 1 | 1]);
}

int Query (int rt, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return mn[rt];
  int mid = l + r >> 1, ans = INT_MAX;
  if (ql <= mid) ans = min (ans, Query (rt << 1, l, mid, ql, qr));
  if (qr > mid) ans = min (ans, Query (rt << 1 | 1, mid + 1, r, ql, qr));
  return ans;
}

void Tarjan (int f, int u, vector <int> &stk) {
  dfn[u] = low[u] = ++tot;
  stk.emplace_back (u);
  for (int v : G[u]) if (v != f) {
    if (!dfn[v]) {
      Tarjan (u, v, stk);
      low[u] = min (low[u], low[v]);
      if (low[v] >= dfn[u]) {
        ++bcc_cnt;
        int p = n + bcc_cnt, q;
        do {
          q = stk.back ();
          stk.pop_back ();
          nG[p].emplace_back (q);
          nG[q].emplace_back (p);
        } while (q != v);
        nG[p].emplace_back (u);
        nG[u].emplace_back (p);
      }
    }
    else if (dfn[v] < dfn[u]) low[u] = min (low[u], dfn[v]);
  }
}

void DFS1 (int f, int u, int d) {
  fa[u] = f, siz[u] = 1, dep[u] = d;
  for (int v : nG[u]) if (v != f) {
    DFS1 (u, v, d + 1);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}

void DFS2 (int f, int u, int t) {
  dfn[u] = ++tot, top[u] = t;
  if (son[u]) DFS2 (u, son[u], t);
  for (int v : nG[u]) {
    if (v == f || v == son[u]) continue;
    DFS2 (u, v, v);
  }
  bot[u] = tot;
}

void Change (int x, int k) {
  if (!fa[x]) return void (val[x] = k);
  s[fa[x]].erase (s[fa[x]].find (val[x]));
  s[fa[x]].insert (val[x] = k);
  Modify (1, 1, N, dfn[fa[x]], *s[fa[x]].begin ());
}

int Find (int u, int v) {
  int ans = INT_MAX, oldu = u, oldv = v;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap (u, v);
    ans = min (ans, Query (1, 1, N, dfn[top[u]], dfn[u]));
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap (u, v);
  if (v > n) ans = min (ans, val[fa[v]]);
  else ans = min (ans, val[v]);
  ans = min (ans, Query (1, 1, N, dfn[v], dfn[u]));
  return ans;
}

void charming () {
  init ();
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) cin >> val[i];
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    G[u].emplace_back (v);
    G[v].emplace_back (u);
  }
  vector <int> stk;
  Tarjan (0, 1, stk);
  tot = 0, DFS1 (0, 1, 1), DFS2 (0, 1 ,1);

  for (int u = n + 1; u <= n + bcc_cnt; ++u) {
    for (int v : nG[u]) {
      if (v != fa[u]) {
        if (((int) s[u].size () && val[v] < *s[u].begin ()) 
        || (int) s[u].size () == 0) Modify (1, 1, N, dfn[u], val[v]);
        s[u].insert (val[v]);
      }
    }
  }

  char opt;
  for (int i = 1, a, w, b; i <= q; ++i) {
    cin >> opt;
    if (opt == 'C') cin >> a >> w, Change (a, w);
    else cin >> a >> b, cout << Find (a, b) << "\n";
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}