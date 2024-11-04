#include <bits/stdc++.h>
using ll = long long;
const int MOD = 1e9 + 7;

void charming() {
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  int now = 0, ans = 1;
  while (now < n) {
    int nxt = now;
    while (nxt + 1 < n && s[nxt + 1] != s[nxt]) nxt += 1;
    int cnt = nxt - now + 1;
    ans = 1ll * ans * ((cnt + 1) / 2) % MOD;
    now = nxt + 1;
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

