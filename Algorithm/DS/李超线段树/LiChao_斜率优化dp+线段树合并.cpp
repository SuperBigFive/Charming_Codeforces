#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 1e10 + 5;

int t, n, q, L, rt;

struct Seg {
  int k, b;
  Seg (int k = 0, int b = 0) : k (k), b (b) {}
  ll Calc (ll x) {return k * x + b;}
}seg[N];


struct LiChao_SegmentTree {
  int n, tot;
  vector <int> root, dp, node, ls, rs;
  
  LiChao_SegmentTree (int n) {
    this -> n = n, this -> tot = 0;
    this -> root = this -> dp = vector <int> (n + 5);
    this -> node = this -> ls = this -> rs = vector <int> (n << 5);
  }
  
  void Merge (int &rt1, int rt2, int l, int r) {
    if (!rt1) {rt1 = rt2; return;}
    else if (!rt2) return;
    int mid = l + r >> 1;
    Insert (rt1, l, r, node[rt2]);
    Merge (ls[rt1], ls[rt2], l, mid);
    Merge (rs[rt1], rs[rt2], mid + 1, r);
  }
  
  void DFS (int f, int u, ll s, vector <vector <pair <int, int> > > &G) {
    for (auto [v, w] : G[u]) if (v != f) {
      DFS (u, v, s + w, G);
      Merge (root[u], root[v], -M, M);
    }
    if (f && (int) G[u].size () == 1) dp[u] = 0;
    else dp[u] = Query (root[u], -M, M, s) + s * s + L * L;
    seg[u] = {-2 * s + 2 * L, s * s - 2 * s * L + dp[u]};
    Insert (root[u], -M, M, u);
  }
  
  void Insert (int &rt, int l, int r, int id) {
    if (!rt) {
      rt = ++tot;
      node[rt] = id;
      return;
    }
    int mid = l + r >> 1;
    if (seg[node[rt]].Calc (mid) > seg[id].Calc (mid)) swap (node[rt], id);
    int chk_l = (seg[id].Calc (l) < seg[node[rt]].Calc (l));
    int chk_r = (seg[id].Calc (r) < seg[node[rt]].Calc (r));
    if (chk_l) Insert (ls[rt], l, mid, id);
    if (chk_r) Insert (rs[rt], mid + 1, r, id);
  };
  
  ll Query (int rt, int l, int r, int p) {
    if (!rt) return LLONG_MAX;
    ll ans = seg[node[rt]].Calc (p);
    if (l == r) return ans;
    int mid = l + r >> 1;
    if (p <= mid) ans = min (ans, Query (ls[rt], l, mid, p));
    else ans = min (ans, Query (rs[rt], mid + 1, r, p));
    return ans;
  }
};

void init () {}

void charming () {
  init ();
  cin >> n >> L;
  vector <vector <pair <int, int> > > G (n + 5);
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    G[u].emplace_back (make_pair (v, w));
    G[v].emplace_back (make_pair (u, w));
  }
  cin >> q;
  bool flag = true;
  while (q--) {
    for (int i = 1; i <= n; ++i) seg[i] = {0, 0};
    LiChao_SegmentTree LiChao (n);
    cin >> rt;
    LiChao.DFS (0, rt, 0, G);
    cout << LiChao.dp[rt] << endl;
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}