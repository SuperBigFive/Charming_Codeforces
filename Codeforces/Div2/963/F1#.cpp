#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, k, w, h; std::cin >> n >> k >> w >> h;
  std::string move; std::cin >> move;
  std::map<std::pair<int, int>, int> cnt;
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (move[i] == 'L') ++x;
    else if (move[i] == 'R') --x;
    else if (move[i] == 'D') --y;
    else ++y;
    x = ((x % (2 * w)) + 2 * w) % (2 * w);
    y = ((y % (2 * h)) + 2 * h) % (2 * h);
    ++cnt[std::make_pair(x, y)];
  }
  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    int tar_x = ((-1ll * i * x % (2 * w)) + (2 * w)) % (2 * w);
    int tar_y = ((-1ll * i * y % (2 * h)) + (2 * h)) % (2 * h);
    ans += cnt[std::make_pair(tar_x, tar_y)];
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