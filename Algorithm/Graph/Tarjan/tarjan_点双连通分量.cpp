#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e6 + 5;

int n, m, tot, bcc_cnt;
int to[N], nxt[N], head[N], vis[N];
int dfn[N], low[N];
vector <int> bcc[N];

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

void add_edge (int u, int v) {
  to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}

void Tarjan (int u, vector <int> &stk) {
  stk.emplace_back (u);
  dfn[u] = low[u] = ++tot;
  int chk = 0;
  for (int i = head[u], v; i != -1; i = nxt[i]) {
    if (vis[i >> 1]) continue;
    v = to[i], vis[i >> 1] = 1;
    if (!dfn[v]) {
      Tarjan (v, stk);
      low[u] = min (low[u], low[v]);
      if (low[v] >= dfn[u]) {
        ++bcc_cnt;
        do {
          bcc[bcc_cnt].emplace_back (stk.back ());
          stk.pop_back ();
        } while (bcc[bcc_cnt].back () != v);
        bcc[bcc_cnt].emplace_back (u);
        chk = 1;
      }
    }
    else low[u] = min (low[u], dfn[v]);
  }
  if (!chk && (int) stk.size () == 1) bcc[++bcc_cnt].emplace_back (u);
}

void init () {tot = 0; memset (head, -1, sizeof head);}

void charming () {
  init ();
  n = read (), m = read ();
  for (int i = 0, u, v; i < m; ++i) {
    u = read (), v = read ();
    add_edge (u, v), add_edge (v, u);
  }
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) {
      vector <int> stk;
      Tarjan (i, stk);
    }
  }
  printf ("%d\n", bcc_cnt);
  for (int i = 1, siz; i <= bcc_cnt; ++i) {
    siz = bcc[i].size ();
    printf ("%d ", siz);
    for (int j = 0; j < siz; ++j) {
      printf ("%d%c", bcc[i][j], j == siz - 1 ? '\n' : ' ');
    }
  }
}

signed main () {
  charming ();
  return 0;
}
