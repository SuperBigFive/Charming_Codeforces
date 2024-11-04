#include <bits/stdc++.h>
#define ll long long

void charming() {
  int n, m; std::cin >> n >> m;
  std::vector<std::string> a(n);
  std::vector<ll> coef(n);
  std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < n; ++i) {
    coef[i] = ((1ll * (rnd() << 15) | rnd()) << 31) | ((rnd() << 15) | rnd());
    std::cin >> a[i];
  }
  std::map<ll, int> cnt;
  for (int j = 0; j < m; ++j) {
    ll h = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == '1') h ^= coef[i];
    }
    for (int i = 0; i < n; ++i) {
      ++cnt[h ^ coef[i]];
    }
  }
  ll mx = -1, tar_h = 0;
  for (auto [k, v] : cnt) {
    if (v > mx) mx = v, tar_h = k;
  }
  std::string opt;
  bool chk = 0;
  for (int j = 0; j < m; ++j) {
    ll h = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] == '1') h ^= coef[i];
      opt += a[i][j];
    }
    for (int i = 0; i < n; ++i) {
      if ((h ^ coef[i]) == tar_h) {
        if (a[i][j] == '1') {
          opt[i] = '0';
        }
        else {
          opt[i] = '1';
        }
        chk = 1;
      }
    }
    if (chk) break;
    else opt.clear();
  }
  std::cout << mx << '\n' << opt << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}