#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;

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

int n;

void init () {}

void DFS (int u, vector <bool> &flag, vector <vector <int> > &revG) {
  for (int v : revG[u]) {
    if (flag[v]) continue;
    else flag[v] = true, DFS (v, flag, revG);
  }
}

void charming () {
  init ();
  n = read ();
  vector <int> in (n);
  vector <vector <int> > G (n), revG (n);
  for (int i = 0, c; i < n; ++i) {
    c = read ();
    for (int j = 0, p; j < c; ++j) {
      p = read (), --p;
      G[p].emplace_back (i);
      revG[i].emplace_back (p);
    }
  }
  vector <bool> flag (n);
  DFS (0, flag, revG);
  queue <int> q;
  for (int i = 1; i < n; ++i) if (flag[i]) {
    for (int v : G[i]) if (flag[v]) ++in[v];
  }
  for (int i = 1; i < n; ++i) if (flag[i] && !in[i]) q.push (i);
  vector <int> ans;
  while (!q.empty ()) {
    int u = q.front ();
    q.pop ();
    if (u == 0) break;
    ans.emplace_back (u);
    for (int v : G[u]) if (flag[v]) {
      --in[v];
      if (!in[v]) q.push (v);
    }
  }
  for (int x : ans) cout << x + 1 << " \n"[x == ans.back ()];
}

signed main () {
  charming ();
  return 0;
}