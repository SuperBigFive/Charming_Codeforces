#include<bits/stdc++.h>
#define ll long long

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int ans = 0, chk = 0, mx = *std::max_element(a.begin(), a.end());
  ll lcm = 1;
  for (int i = 0; i < n; ++i) {
    lcm = 1ll * lcm * a[i] / std::__gcd(lcm, 1ll * a[i]);
    if (lcm > mx) {
      chk = 1;
      break;
    }
  }
  if (chk) {
    std::cout << n << std::endl;
  }
  else {
    std::set<int> s;
    for (int i = 0; i < n; ++i) s.insert(a[i]);
    std::vector<int> vec;
    for (int i = 1; i * i <= mx; ++i) {
      if (mx % i) continue;
      else {
        int val1 = i, val2 = mx / i;
        if (!s.count(val1)) vec.emplace_back(val1);
        if (!s.count(val2)) vec.emplace_back(val2);
      }
    }
    for (int x : vec) {
      int cnt = 0;
      ll lcm = 1;
      for (int i = 0; i < n; ++i) {
        if (x % a[i] == 0) {
          lcm = 1ll * lcm * a[i] / std::__gcd(lcm, 1ll * a[i]);
          ++cnt;
        }
      }
      if (lcm == x) ans = std::max(ans, cnt);
    }
    std::cout << ans << std::endl;
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