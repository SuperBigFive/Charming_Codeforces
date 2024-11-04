#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void charming () {
  cin >> n >> k;
  vector <pair <int, int> > item (n);
  for (int i = 0; i < n; ++i) cin >> item[i].first;
  for (int i = 0; i < n; ++i) cin >> item[i].second;
  sort (item.begin (), item.end (), [] (pair <int, int> &x,
  pair <int, int> &y) {return x.second < y.second;});
  vector <ll> suf (n + 1);
  priority_queue <int> pq; pq.push (0);
  ll sum = 0;
  for (int i = n - 1; i >= n - k; --i) {
    pq.push (item[i].first);
    sum += item[i].first;
  }
  suf[n - k] = sum;
  for (int i = n - k - 1, mx; i >= 0; --i) {
    mx = pq.top ();
    if (item[i].first < mx) {
      sum -= mx, pq.pop (), pq.push (item[i].first), sum += item[i].first;
    }
    suf[i] = sum;
  }
  ll ans = 0, pre_sum = 0;
  for (int i = 0; i < n - k; ++i) {
    pre_sum += max (item[i].second - item[i].first, 0);
    ans = max (ans, pre_sum - suf[i + 1]);
  }
  cout << ans << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}