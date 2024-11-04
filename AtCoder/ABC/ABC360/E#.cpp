#include <bits/stdc++.h>
using ll = long long;
#define int ll
const int MOD = 998244353;

void charming() {
  int n, k; std::cin >> n >> k;

  auto QSM = [&](int x, int p) -> int {
    int ans = 1;
    while (p) {
      if (p & 1) ans = 1ll * ans * x % MOD;
      p >>= 1, x = 1ll * x * x % MOD;
    }
    return ans;
  };

  // g[i][k] : 黑球位于 i, k 次操作后期望位置
  // f[k]: 黑球位于 1, 2 ... n, k 次操作后期望位置的和
  // f[k] = sum(g[i][k]), 1 <= i <= n
  // g[i][k] = (n-1)^2 / (n^2) * i +  1 / (n^2) * (2 * sum(g[i][k - 1]) - g[i][k - 1])
  //         = (n-1)^2 / (n^2) * i + 1/(n^2)*(2*f[k-1] - g[i][k - 1])
  // f[k] = sum(g[i][k]) = (n-1)^2/n*(n+1)/2 + 2/n*f[k-1] - 1/(n^2)*f[k-1]
  //                     = (n-1)^2/n*(n+1)/2 + (2/n - 1/(n^2))*f[k-1]
  // ans = g[1][k]

  std::vector<int> f(k + 1);
  int inv_2 = QSM(2, MOD - 2), inv_n1 = QSM(n, MOD - 2), inv_n2 = QSM(1ll * n * n % MOD, MOD - 2);
  f[0] = 1ll * n * (n + 1) / 2 % MOD;
  for (int i = 1; i <= k; ++i) {
    f[i] = 1ll * (n - 1) * (n - 1) % MOD * inv_n1 % MOD * (n + 1) % MOD * inv_2 % MOD;
    f[i] += (2ll * inv_n1 - inv_n2) % MOD * f[i - 1] % MOD;
    f[i] %= MOD;
  }

  auto Solve = [&](auto &&self, int x) -> int {
    if (x == 0) return 1;
    int ans = 1ll * (n - 1) * (n - 1) % MOD * inv_n2 % MOD + 1ll * inv_n2 * (2ll * f[x - 1] - self(self, x - 1)) % MOD;
    ans %= MOD;
    return ans;
  };

  int ans = Solve(Solve, k);
  ans = ((ans % MOD) + MOD) % MOD;
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}