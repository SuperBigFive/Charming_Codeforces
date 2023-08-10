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

int t, n, tot;

void init () {tot = 0;}

void charming () {
  init ();
  n = read ();
  vector <int> a (n + 5);
  vector <vector <int> > G (n + 5);
  for (int i = 2, f; i <= n; ++i) {
    f = read ();
    G[f].emplace_back (i);
  }
  vector <int> siz (n + 5), son (n + 5);
  for (int i = 1; i <= n; ++i) son[i] = G[i].size ();
  for (int i = 1; i <= n; ++i) {
    if (son[i] <= 1) continue;
    else sort (G[i].begin (), G[i].end (), [&] 
    (int x, int y) {return siz[x] > siz[y];});
  }

  auto DFS = [&] (auto && me, int u) -> void {
    siz[u] = 1;
    for (int v : G[u]) {
      me (me, v);
      siz[u] += siz[v];
    }
  };

  DFS (DFS, 1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    // cout << i << " " << son[i] << endl;
    if (son[i] <= 1) continue;
    else {
      int mx = 0, sum = siz[i] - 1;
      unordered_set <int> s;
      vector <int> ns;
      s.insert (0);
      for (int v : G[i]) {
        ns.clear ();
        for (int k : s) ns.emplace_back (k + siz[v]);
        for (int k : ns) s.insert (k);
      }
      for (int k : s) mx = max (mx, k * (sum - k));
      // cout << i << " " << sum << endl;
      ans += mx;
    }
  }
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}