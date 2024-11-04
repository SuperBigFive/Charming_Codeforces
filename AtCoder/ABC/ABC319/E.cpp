#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 840;

int n, x, y, q;

void init () {}

// 1, 2, 3, 4, 5, 6, 7, 8
// 1, 2, 6, 12, 60, 420, 840

void charming () {
  init ();
  cin >> n >> x >> y, --n;
  vector <pair <int, int> > bus (n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> bus[i].first >> bus[i].second;
    sum += bus[i].second;
  }
  vector <ll> ans (M);
  for (int i = 0; i < M; ++i) {
    ll nans = 0, now = i + x;
    for (int j = 0; j < n; ++j) {
      ll nxt = (now + bus[j].first - 1) / bus[j].first * bus[j].first;
      nans += nxt - now, now = nxt + bus[j].second;
    }
    ans[i] = nans;
  }
  cin >> q;
  for (int i = 0, k; i < q; ++i) {
    cin >> k;
    cout << 1ll * k + ans[k % M] + x + y + sum << endl;
  }
}

signed main () {
  charming ();
  return 0;
}