#include <bits/stdc++.h>
const int N = 2e6 + 5;

void charming() {
  long long n; std::cin >> n;
  std::vector<int> prime, vis(N);
  for (int i = 2; i < N; ++i) {
    if (!vis[i]) prime.emplace_back(i);
    for (int p : prime) {
      if (i * p < N) {
        vis[i * p] = true;
        if (!(i % p)) break;
      } else break;
    }
  }

  int ans = 0;
  for (int p : prime) {
    bool ok = true;
    long long x = 1;
    for (int i = 0; i < 8; ++i) {
      x *= p;
      if (x > n) {ok = false; break;}
    }
    if (ok) ++ans;
  }
  for (int i = 0, j = -1, siz = prime.size(); i < siz; ++i) {
    ++j;
    j = std::min(i - 1, j);
    while (j >= 0 && __int128(prime[i]) * prime[j] * prime[i] * prime[j] > n) --j;
    ans += j + 1;
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
