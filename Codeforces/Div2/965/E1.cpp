#include <bits/stdc++.h>
using ll = long long;
const int N = 20;

void charming() {
  int n, x; std::cin >> n >> x;
  std::vector<int> a(n);
  std::vector<ll> pre(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    pre[i] = (i - 1 >= 0 ? pre[i - 1] : 0) + a[i];
  }

  std::vector<std::array<int, N> > mx(n);
  for (int i = 0; i < n; ++i) mx[i][0] = a[i];
  for (int j = 1; j < N; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i + (1 << j) <= n) {
        mx[i][j] = std::max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int now_l = i, now_r = i;

    while (true) {
      int old_l = now_l, old_r = now_r;
      
      ll val = pre[now_r] - (now_l - 1 >= 0 ? pre[now_l - 1] : 0);
      
      if (now_l > 0) {
        for (int j = N - 1; j >= 0; --j) {
          if (now_l - 1 - (1 << j) + 1 >= 0) {
            if (mx[now_l - (1 << j)][j] <= val) now_l -= (1 << j);
          }
        }
      }

      if (now_r < n) {
        for (int j = N - 1; j >= 0; --j) {
          if (now_r + 1 + (1 << j) - 1 < n) {
            if (mx[now_r + 1][j] <= val) now_r += (1 << j);
          }
        }
      }

      if (now_l == old_l && now_r == old_r) break;
    }

    if (now_l == 0 && now_r == n - 1) ++ans;
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
