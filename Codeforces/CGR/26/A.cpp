#include <bits/stdc++.h>
#define ll long long
const int N = 2e5 + 5;

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int mx = *std::max_element(a.begin(), a.end());
  int mn = *std::min_element(a.begin(), a.end());
  if (mx == mn) {
    std::cout << "NO" << '\n';
    return;
  }
  else {
    std::cout << "YES" << '\n';
    int mn_cnt = std::count(a.begin(), a.end(), mn);
    if (mn_cnt == 1) {
      int flag = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == mx) {
          if (!flag) std::cout << "R", flag = 1;
          else std::cout << "B";
        }
        else std::cout << "B";
      }
      std::cout << '\n';
    }
    else {
      int flag = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == mn) {
          if (!flag) std::cout << "R", flag = 1;
          else std::cout << "B";
        }
        else std::cout << "B";
      }
      std::cout << '\n';
    }
  }
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}