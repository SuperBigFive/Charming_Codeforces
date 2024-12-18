#include <bits/stdc++.h>
const int INF = 1e9;

void charming() {
  int h, w, d; std::cin >> h >> w >> d;
  std::vector s(h, std::vector<char> (w));
  for (int i = 0; i < h; ++i) {
    std::string input; std::cin >> input;
    for (int j = 0; j < w; ++j) s[i][j] = input[j];
  }

  std::vector st(h, std::vector<int> (w, -1));
  std::vector<std::pair<int, std::pair<int, int> > > q;
  int head = 0, tail = 0;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (s[i][j] == 'H') {
    q.emplace_back(std::make_pair(d, std::make_pair(i, j))), st[i][j] = d, ++tail;
  }

  auto isValid = [&](int x, int y) -> bool {
    return x >= 0 && x < h && y >= 0 && y < w && s[x][y] != '#';
  };

  int ans = 0;
  std::vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
  std::vector vis(h, std::vector<int> (w));
  while (head < tail) {
    auto [r, p] = q[head++];
    auto [x, y] = p;
    if (r < st[x][y]) continue;

    if (!vis[x][y]) ++ans;
    vis[x][y] = 1;

    if (r) {
      for (int i = 0, nx, ny; i < 4; ++i) {
        nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny) && st[nx][ny] < r - 1) {
          q.emplace_back(std::make_pair(r - 1, std::make_pair(nx, ny)));
          st[nx][ny] = r - 1;
          ++tail;
        }
      }
    }
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
