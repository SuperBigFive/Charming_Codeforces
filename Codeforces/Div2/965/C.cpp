#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];

  std::vector<int> c = a;
  std::vector<int> idx(n);
  std::iota(idx.begin(), idx.end(), 0);
  sort(c.begin(), c.end());
  sort(idx.begin(), idx.end(), [&](int x, int y) {return a[x] < a[y];});
  ll med = c[(n - 1) / 2];
  ll ans = 0;

  for (int i = 0; i < n; ++i) {
    int new_val = a[i] + k * b[i];
    if (n & 1) {
      if (a[i] >= med) ans = std::max(ans, 1ll * new_val + c[n / 2 - 1]);
      else ans = std::max(ans, 1ll * new_val + med);
    }
    else {
      if (a[i] <= med) ans = std::max(ans, 1ll * new_val + c[n / 2]);
      else ans = std::max(ans, 1ll * new_val + med);
    }
  }

  auto Check = [&](ll mid) -> bool {
    int cnt = 0;
    std::vector<int> vec;
    for (int i = n - 1; i >= 0; --i) {
      if (a[idx[i]] < mid) {
        ++cnt;
        if (b[idx[i]]) vec.emplace_back(mid - a[idx[i]]);
      }
    }
    int req = n / 2 - 1;
    if (cnt <= req) return true;
    else {
      int d = cnt - req, siz = vec.size();
      if (siz < d) return false;
      else {
        ll cost = 0;
        for (int i = 0; i < d; ++i) cost += vec[i];
        if (cost > k) return false;
        else return true;
      }
    }
  };

  med = c[n / 2 - 1];
  ll l = med, r = 2e9;
  while (l <= r) {
    ll mid = l + r >> 1;
    if (Check(mid)) l = mid + 1, ans = std::max(ans, c[n - 1] + mid);
    else r = mid - 1;
  }

  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
