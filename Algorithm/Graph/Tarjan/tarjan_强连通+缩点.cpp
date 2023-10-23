#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, tot, scc_cnt;
int val[N], mxval[N], mnval[N];
int dfn[N], low[N], bel[N], reach[N], in[N];
vector <int> G[N], nG[N], revG[N];

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

void Tarjan (int u, vector <int> &stk) {
  stk.emplace_back (u);
  dfn[u] = low[u] = ++tot;
  for (int v : G[u]) {
    if (!dfn[v]) {
      Tarjan (v, stk);
      low[u] = min (low[u], low[v]);
    }
    else if (!bel[v]) low[u] = min (low[u], dfn[v]);
  }
  if (low[u] >= dfn[u]) {
    ++scc_cnt;
    int v;
    do {
      v = stk.back (), stk.pop_back ();
      bel[v] = scc_cnt;
    } while (v != u);
  }
}

void init () {}

void charming () {
  init ();
  n = read (), m = read ();
  for (int i = 1; i <= n; ++i) val[i] = read ();
  for (int i = 1; i <= n; ++i) mxval[i] = -1, mnval[i] = 101;
  for (int i = 1, u, v, z; i <= m; ++i) {
    u = read (), v = read (), z = read ();
    G[u].emplace_back (v);
    if (z == 2) G[v].emplace_back (u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) {
      vector <int> stk;
      Tarjan (i, stk);
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (int v : G[u]) {
      if (bel[u] != bel[v]) {
        nG[bel[u]].emplace_back (bel[v]);
        revG[bel[v]].emplace_back (bel[u]);
      }
    }
    mnval[bel[u]] = min (mnval[bel[u]], val[u]);
    mxval[bel[u]] = max (mxval[bel[u]], val[u]);
  }
  int ans = 0;
  queue <int> q;
  q.push (bel[n]), reach[bel[n]] = 1;
  while (!q.empty ()) {
    int u = q.front (); q.pop ();
    for (int v : revG[u]) {
      if (reach[v]) continue;
      else reach[v] = 1, q.push (v);
    }
  }
  if (!reach[bel[1]]) return printf ("0\n"), void ();
  for (int u = 1; u <= n; ++u) if (reach[u]) {
    for (int v : nG[u]) ++in[v]; 
  }
  q.push (bel[1]);
  while (!q.empty ()) {
    int u = q.front (); q.pop ();
    ans = max (ans, mxval[u] - mnval[u]);
    for (int v : nG[u]) if (reach[v]) {
      mnval[v] = min (mnval[v], mnval[u]);
      --in[v];
      if (in[v] == 0) q.push (v);
    }
  }
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
