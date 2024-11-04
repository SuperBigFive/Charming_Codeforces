namespace LCA {
  using namespace std;

  struct tree {
    int v, next;
  } tr[N * 4];
  int tot, head[N];
  int idc, dfn[N], seq[N], dep[N], f[N];
  int lg[N], st[N][M];

  void init() {
    idc = 0;
    for (int i = 0; i <= tot; ++i) {
      head[i] = dfn[i] = seq[i] = dep[i] = f[i] = 0;
      for (int j = 0; j < M; ++j) st[i][j] = 0;
    }
    tot = 0;
  }

  void add(int x,int y) {
    tot++;
    tr[tot].v = y;
    tr[tot].next = head[x];
    head[x] = tot;
  }

  void dfs(int x,int fa) {
    dep[x] = dep[fa] + 1;
    dfn[x] = ++idc;
    seq[idc] = x;
    f[x] = fa;
    for (int t = head[x]; t; t = tr[t].next) {
      int y = tr[t].v;
      if (y == fa) continue;
      dfs(y, x);
    }
  }

  void ready() {
    lg[0] = -1;
    for(int i = 1; i < N; ++i) {
      st[i][0] = f[seq[i]];
      lg[i] = lg[i >> 1] + 1;
    }
    for(int j = 1; j <= M; ++j) {
      for(int i = 1; i + (1 << j) - 1 < N; ++i) {
        int ret = (dep[st[i][j - 1]] < dep[st[i + (1 << (j - 1))][j - 1]])
        ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
        st[i][j] = ret;
      }
    }
  }

  int lca (int x,int y) {
    if (x == y) return x;
    x = dfn[x]; y = dfn[y];
    if (x > y) swap (x, y);
    int p = lg[y - x];
    int ret = (dep[st[x + 1][p]] < dep[st[y - (1 << p) + 1][p]]) ? st[x + 1][p]
    : st[y - (1 << p) + 1][p];
    return ret;
  }
}