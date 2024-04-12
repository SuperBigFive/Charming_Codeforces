#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
int a[N], vis[N];

void charming () {
  cin >> n;
  vis[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    vis[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    vis[a[i]] = 1;
  }
  bool ok = true;
  int mex = 0;
  while (vis[mex]) ++mex;
  vector <pair <int, int> > ans;
  int p = 1, q = p, cnt = mex;
  for (int i = 0; i < mex; ++i) vis[i] = 0;
  while (cnt && q <= n) {
    if (!vis[a[q]] && a[q] < mex) --cnt;
    vis[a[q]] = 1;
    ++q;
  }
  if (cnt) ok = false;
  else {
    q = max (p + 1, q);
    ans.emplace_back (make_pair (p, q - 1));
    p = q;
    for (int i = 0; i < mex; ++i) vis[i] = 0;
    for (int q = p; q <= n; ++q) {
      vis[a[q]] = 1;
    }
    for (int i = 0; i < mex; ++i) if (!vis[i]) ok = false;
    ans.emplace_back (make_pair (p, n));
  }
  if (!ok) {
    cout << -1 << endl;
  }
  else {
    cout << 2 << endl;
    for (auto [l, r] : ans) cout << l << " " << r << endl;
  }
}

signed main () {
  cin >> t;
  while (t--) charming ();
  return 0;
}