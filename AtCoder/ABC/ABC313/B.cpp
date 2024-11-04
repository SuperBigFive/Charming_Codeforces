#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

char getch () { 
	static char buf[100000], *s1, *s2; 
	return (s1 == s2) && (s2 = (s1 = buf) + 
	fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++; 
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {ch = getch (); if (ch == '-') w = -1;}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

int n, m;

void init () {}

void charming () {
  init ();
  n = read (), m = read ();
  vector <int> in (n), vis (n);
  vector <vector <int> > G (n);
  for (int i = 0, u, v; i < m; ++i) {
    u = read (), v = read ();
    --u, --v;
    G[u].emplace_back (v);
  }
  
  auto DFS = [&] (auto && me, int u) -> int {
    int ans = 0;
    vis[u] = 1;
    for (int v : G[u]) {
      if (vis[v]) continue;
      ans += me (me, v);
    }
    return ans + 1;
  };
  
  int cnt = 0, id = -1;
  for (int i = 0; i < n; ++i) {
    vis = vector <int> (n);
    if (DFS (DFS, i) == n) ++cnt, id = i;
  }
  cout << (cnt == 1 ? id + 1: -1) << endl;
}

signed main () {
  charming ();
  return 0;
}