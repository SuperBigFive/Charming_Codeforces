#include <bits/stdc++.h>
using ll = long long;
const int MOD = 1e9 + 7;

void charming() {
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::vector<int> indexs(n - k);
  iota(indexs.begin(), indexs.end(), k);
  sort(indexs.begin(), indexs.end(), [&](int x, int y) {
    return a[x] > a[y];
  });
  std::vector<std::pair<int, int> > ans;
  for (int idx : indexs) {
    std::vector<int> b(idx - k + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int x, int y) {
      return a[x] < a[y];
    });
    for (int i : b) {
      if (a[i] > a[idx] && idx - i >= k) {
        ans.emplace_back(std::make_pair(i, idx));
        std::swap(a[idx], a[i]);
      }
    }
  }
  int cnt = ans.size();
  std::cout << cnt << '\n';
  for (int i = 0, pl, pr; i < cnt; ++i) {
    pl = ans[i].first, pr = ans[i].second;
    std::cout << pl + 1 << ' ' << pr + 1 << '\n';
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}


// 8 7 6 10 9 3 1 5 2 4
// 7 6 5 10 9 3 1 8 2 4 | + 3
// 6 5 4 9 7 3 1 8 2 10 | + 5
// 3 5 4 9 7 6 1 8 2 10 | + 1
// 2 4 3 5 7 6 1 8 9 10 | + 4
// 1 2 3 5 7 6 4 8 9 10 | + 2
// = 15