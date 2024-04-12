#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 41;

int t, n, m;
vector <int> f[N];

void Prepare () {
  f[1].emplace_back (1);
  int cnt = 1;
  for (int i = 2; i < N; ++i) {
    // cout << i << endl;
    for (int j = 1; j <= i; ++j) {
      vector <int> b;
      for (int k = j; k >= 1; --k) {
        b.emplace_back (k);
      }
      for (int k = i; k > j; --k) {
        b.emplace_back (k);
      }
      int dis = -1;
      for (int p = 0; p < i; ++p) {
        for (int q = p + 1; q < i; ++q) {
          dis = max (dis, q - p + abs (b[q] - b[p]));
        }
      }
      if (dis == i) {f[i] = b; ++cnt; break;}
    }
  }
}

void charming () {
  cin >> n >> m;
  if (m >= n) {
    for (int x : f[n]) cout << x << " \n"[x == f[n].back ()];
    cout << 1 << endl;
    for (int i = 1; i <= n; ++i) cout << 1 << " \n"[i == n];
  }
  else {
    int oldn = n;
    int lst = 0, cnt = 0;
    vector <int> bel;
    while (n > m) {
      ++cnt;
      for (int x : f[m]) cout << x + lst << " ";
      n -= m;
      lst += m;
      for (int i = 0; i < m; ++i) bel.emplace_back (cnt);
    }
    if (n) {
      ++cnt;
      for (int x : f[n]) cout << x + lst << " \n"[x == f[n].back ()];
      for (int i = 0; i < n; ++i) bel.emplace_back (cnt);
    }
    else cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < oldn; ++i) cout << bel[i] << " \n"[i == oldn - 1];
  }
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  Prepare ();
  cin >> t;
  while (t--) charming ();
  return 0;
}