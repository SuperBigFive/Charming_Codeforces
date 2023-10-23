#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, cir_cnt;
int a[N], in[N], bel[N], vis[N], col[N];
vector <int> cir[N], G[N];

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

void DFS (int u, vector <int> &stk) {
  stk.emplace_back (u), vis[u] = 2;
  for (int v : G[u]) {
    if (vis[v] == 2) {
      ++cir_cnt;
      int p = stk.size () - 1;
      do {
        cir[cir_cnt].emplace_back (stk[p]);
        bel[stk[p]] = cir_cnt;
      } while (stk[p--] != v);
    } else if (!vis[v]) DFS (v, stk);
  }
  stk.pop_back (), vis[u] = 1;
}

void init () {}

void charming () {
  init ();
  n = read ();
  for (int i = 1; i <= n; ++i) {
    a[i] = read (), ++in[a[i]];
    G[i].emplace_back (a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {vector <int> stk; DFS (i, stk);}
  }
  queue <int> q;
  for (int i = 1; i <= n; ++i) {
    vis[i] = 0;
    if (!in[i]) q.push (i), vis[i] = 1;
  } 
  while (!q.empty ()) {
    int u = q.front (); q.pop ();
    for (int v : G[u]) {
      if (vis[v]) continue;
      else {
        if (col[u] == 0) col[v] = 1;
        --in[v];
        if (in[v] == 0 || (col[u] == 0 && bel[v] != 0)) {
          vis[v] = 1, q.push (v);
        }
      }
    }
  }
  for (int i = 1, cir_siz; i <= cir_cnt; ++i) {
    cir_siz = cir[i].size ();
    if (vis[cir[i][0]]) continue;
    else if (cir_siz & 1) {
      return printf ("-1"), void ();
    }
    else {
      for (int j = 0; j < cir_siz; ++j) {
        col[cir[i][j]] = j & 1;
      }
    }
  }
  vector <int> ans;
  for (int i = 1; i <= n; ++i) {
    if (col[i]) continue;
    else ans.emplace_back (a[i]);
  }
  printf ("%d\n", (int) ans.size ());
  for (int i = 0, siz = ans.size (); i < siz; ++i) {
    printf ("%d%c", ans[i], i == siz - 1 ? '\n' : ' ');
  }
}

signed main () {
  charming ();
  return 0;
}
