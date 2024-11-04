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

  std::vector<int> cnt(n);
  for (int i = 0; i < n; ++i) {
    int now_l = i, now_r = i;

    while (true) {
      
      ll val;
      
      while (now_l > 0) {
        val = pre[now_r] - (now_l - 1 >= 0 ? pre[now_l - 1] : 0);
        int old_l = now_l;
        if (now_l > 0) {
          for (int j = N - 1; j >= 0; --j) {
            if (now_l - 1 - (1 << j) + 1 >= 0) {
              if (mx[now_l - (1 << j)][j] <= val) now_l -= (1 << j);
            }
          }
        }
        if (now_l == old_l) break;
      }

      if (!now_l) break;

      val = pre[now_r] - (now_l - 1 >= 0 ? pre[now_l - 1] : 0);
      int old_r = now_r;
      if (now_r < n) {
        for (int j = N - 1; j >= 0; --j) {
          if (now_r + (1 << j) < n) {
            if (mx[now_r + 1][j] <= val && 
            pre[now_r + (1 << j)] - pre[now_l - 1] < a[now_l - 1]) now_r += (1 << j);
          }
        }
      }
      
      val = pre[now_r] - (now_l - 1 >= 0 ? pre[now_l - 1] : 0);
      if (now_r + 1 < n && val >= a[now_r + 1]) ++now_r;

      if (now_r == old_r) break;
    }

    if (!now_l) ++cnt[now_r];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > (i > 0 ? pre[i - 1] : 0)) ans = 0;
    ans += cnt[i];
    
    std::cout << ans << " \n"[i == n - 1];
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}
