#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

ll n, k;
int siz[N], du[N], p[N];
vector <int> G[N], nG[N];

void charming () {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    G[u].emplace_back (v);
    G[v].emplace_back (u);
  }

  auto DFS1 = [&] (auto && self, int f, int u) -> void {
    siz[u] = 1;
    for (int v : G[u]) {
      if (v == f) continue;
      else self (self, u, v), siz[u] += siz[v];
    }
  };

  DFS1 (DFS1, 0, 1);

  auto DFS2 = [&] (auto && self, int f, int u, int lst) -> void {
    if (k >= siz[u]) {
      k -= siz[u];
      if (lst) nG[lst].emplace_back (u), ++du[u];
      lst = u;
    }
    else {
      if (f) nG[u].emplace_back (f), ++du[f];
    }
    for (int v : G[u]) {
      if (v == f) continue;
      else self (self, u, v, lst);
    }
  };

  if (k < n) return void (cout << "No" << endl);
  DFS2 (DFS2, 0, 1, 0);
  if (k) return void (cout << "No" << endl);

  queue <int> q;
  for (int i = 1; i <= n; ++i) {
    if (!du[i]) q.push (i);
  }
  int cnt = 0, tot = 0;
  while (!q.empty ()) {
    int u = q.front (); q.pop ();
    ++cnt;
    p[u] = ++tot;
    for (int v : nG[u]) {
      --du[v];
      if (!du[v]) q.push (v);
    }
  }
  if (cnt < n) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) cout << p[i] << " \n"[i == n];
  }
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}