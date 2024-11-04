#include<bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int ans = std::min(a[0], a[1]);
  for (int i = 1; i < n - 1; ++i) {
    std::vector<int> tmp;
    tmp.emplace_back(a[i - 1]);
    tmp.emplace_back(a[i]);
    tmp.emplace_back(a[i + 1]);
    sort(tmp.begin(), tmp.end());
    ans = std::max(ans, tmp[1]);
  }
  std::cout << ans << std::endl;
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}