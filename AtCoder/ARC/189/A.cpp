#include <bits/stdc++.h>
const int MOD = 998244353;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n), b;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int now = 0;
  bool ok = true;
  while (now < n) {
    int nxt = now;
    while (nxt + 1 < n && a[nxt + 1] == a[nxt]) ++nxt;
    int len = nxt - now + 1;
    if (len & 1 ^ 1) {ok = false; break;}
    b.emplace_back(len >> 1);
    now = nxt + 1;
  }

  if (!ok || !a[0]) {std::cout << 0 << '\n'; return;}

  std::vector<int> f(n + 1);
  f[0] = 0, f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = 1ll * f[i - 1] * ((i << 1) - 1) % MOD;
  }
  
  auto QSM = [&](int x, int p) -> int {
    int ans = 1;
    while (p) {
      if (p & 1) ans = 1ll * ans * x % MOD;
      p >>= 1, x = 1ll * x * x % MOD;
    }
    return ans;
  };

  std::vector<int> fac(n + 1), ifac(n + 1);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
  ifac[n] = QSM(fac[n], MOD - 2);
  for (int i = n - 1; i > 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;

  auto C = [&](int n, int m) -> int {
    if (n < m) return  0;
    else return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD; 
  };


  auto Merge = [&](int x, int y) -> int {
    return C(x + y, x);
  };

  int ans = 1, sum = 0;
  for (int l : b) if (l) {
    ans = 1ll * ans * f[l] % MOD;
    ans = 1ll * ans * Merge(sum, l) % MOD;
    sum += l;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}
