#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e6 + 5;
const int M = 20;

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

int t, n, tot;
int siz[N], son[N];
vector <int> G[N];

void init () {}

void DFS (int u) {
  siz[u] = 1;
  for (int v : G[u]) {
    DFS (v);
    ++son[u];
    siz[u] += siz[v];
  }
}

template <int len = 1>
ll Solve (int sum, vector <int> &b) {
  if (sum >= len) return Solve <min (len * 2, N)> (sum, b);
  bitset <len> bst;
  // cout << len << endl;
  bst.set (0);
  int cnt = 0;
  for (int v: b) {
    ++cnt;
    bst |= bst << v;
  }
  
  int mx1 = N, mx2 = N, mid = sum / 2;
  for (int i = 1; i <= sum; ++i) if (bst.test (i)) {
    if (i <= mid) mx1 = i;
    else {mx2 = i; break;}
  }
  // return 0;
  return max ({0ll, 1ll * mx1 * (sum - mx1), 1ll * mx2 * (sum - mx2)});
}

void charming () {
  init ();
  n = read ();
  for (int i = 2, f; i <= n; ++i) {
    f = read ();
    G[f].emplace_back (i);
  }
  DFS (1);
  ll ans = 0;
  for (int u = 1, sum, mid, mx; u <= n; ++u) if (son[u] > 1) {
    sum = siz[u] - 1, mid = sum / 2, mx = 0;
    vector <int> b;
    map <int, int> cnt;
    for (int v : G[u]) ++cnt[siz[v]], mx = max (mx, siz[v]);
    if (mx >= mid) ans += 1ll * mx * (sum - mx);
    else {
      for (auto [val, c] : cnt) {
        int j = 1;
        while (c > j) {
          b.emplace_back (val * j);
          c -= j, j <<= 1;
        }
        b.emplace_back (val * c);
      }
      ans += Solve (sum, b);
    }
  }
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}