#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
  init ();
  cin >> n >> m;
  vector <int> word (n);
  for (int i = 0; i < n; ++i) cin >> word[i];

  auto Check = [&] (ll mid) -> bool {
    int lines = 1;
    ll cur = word[0];
    for (int i = 1; i < n && lines <= m; ++i) {
      if (1ll * word[i] + 1ll + cur > mid) {
        cur = word[i];
        ++lines;
      }
      else cur += word[i] + 1;
    }
    return lines <= m;
  };

  ll l = *max_element (word.begin (), word.end ()), r = 1e15, ans = l;
  while (l <= r) {
    ll mid = l + r >> 1;
    if (Check (mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  } 
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}