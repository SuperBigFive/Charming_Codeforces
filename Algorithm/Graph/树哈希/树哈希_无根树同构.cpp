#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N = 2e5 + 5;
const ull msk = std :: chrono :: steady_clock :: 
now ().time_since_epoch ().count ();

int n, m;
int siz[N], centroid[2];
vector <int> G[N];
map <pair <int, int>, int> vis[N];

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

void getCentroid (int f, int u) {
  siz[u] = 1;
  int mx = 0;
  for (int v : G[u]) {
    if (v == f) continue;
    getCentroid (u, v);
    siz[u] += siz[v];
    mx = max (mx, siz[v]);
  }
  mx = max (mx, n - siz[u]);
  if (mx <= n / 2) {
    int idx = (centroid[0] > 0);
    centroid[idx] = u;
  }
}

/*
ll h (ll x) {
  return x * x * x * 1237123 + 19260817;
}
ll f (ll x) {
  ll cur = h (x & ((1 << 31) - 1)) + h (x >> 31);
  return cur;
}
*/

ull Shift (ull x) {
  x ^= msk, x ^= x << 13, x ^= x >> 7, x ^= x << 17, x ^= msk;
  return x;
}

ull getHash (int f, int u) {
  ull hval = 1;
  for (int v : G[u]) {
    if (v == f) continue;
    hval += Shift (getHash (u, v));
  }
  return hval;
}

void init () {}

void charming () {
  init ();
  m = read ();
  for (int i = 1; i <= m; ++i) {
    n = read ();
    centroid[0] = centroid[1] = 0;
    for (int j = 1; j <= n; ++j) G[j].clear ();
    for (int u = 1, v; u <= n; ++u) {
      v = read ();
      if (!v) continue;
      else {
        G[u].emplace_back (v);
        G[v].emplace_back (u);
      }
    }
    pair <int, int> hval = make_pair (-1, -1);
    getCentroid (0, 1);
    hval.first = getHash (0, centroid[0]);
    if (centroid[1]) hval.second = getHash (0, centroid[1]);
    if (hval.first > hval.second) swap (hval.first, hval.second);
    if (vis[n].count (hval)) printf ("%d\n", vis[n][hval]);
    else printf ("%d\n", vis[n][hval] = i);
  }
}

signed main () {
  charming ();
  return 0;
}
