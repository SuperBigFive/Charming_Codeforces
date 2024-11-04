#include <bits/stdc++.h>

void charming() {
  int n, m; std::cin >> n >> m;
  std::map<int, int> vis;
  for (int i = 0; i < m; ++i) {
    int x; std::cin >> x;
    char ch; std::cin >> ch;
    if (ch == 'F') std::cout << "No\n";
    else if (!vis.count(x)) std::cout << "Yes\n", vis[x] = 1;
    else std::cout << "No\n";
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}