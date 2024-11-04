#include<bits/stdc++.h>
#define ll long long
const int P1 = 1331, P2 = 2333;
const int MOD1 = 1e9 + 7, MOD2 = 998244353;

void charming() {
  int n, k; std::cin >> n >> k;
  std::string s; std::cin >> s;
  std::string tar1, tar2;

  auto cal_hashval = [&](std::string s) -> std::pair<int, int> {
    int h1 = 0, h2 = 0;
    for (int i = n - 1, ch2num; i >= 0; --i) {
      ch2num = s[i] - 'a';
      h1 = (1ll * h1 * P1 + ch2num) % MOD1;
      h2 = (1ll * h2 * P2 + ch2num) % MOD2;
    }
    return std::make_pair(h1, h2);
  };

  for (int i = 0; i < n; ++i) {
    if ((i / k) & 1) tar1 += '1', tar2 += '0';
    else tar1 += '0', tar2 += '1';
  }

  std::pair<int, int> chk1 = cal_hashval(tar1), chk2 = cal_hashval(tar2);

  std::vector<int> pow1(n), pow2(n);
  pow1[0] = pow2[0] = 1;
  for (int i = 1; i < n; ++i) {
    pow1[i] = 1ll * pow1[i - 1] * P1 % MOD1;
    pow2[i] = 1ll * pow2[i - 1] * P2 % MOD2;
  }
  std::vector<int> pre_hval1(n), pre_hval2(n);
  for (int i = 0, ch2num; i < n; ++i) {
    if (i) {
      pre_hval1[i] = 1ll * pre_hval1[i - 1] * P1 % MOD1;
      pre_hval2[i] = 1ll * pre_hval2[i - 1] * P2 % MOD2;
    }
    ch2num = s[i] - 'a';
    pre_hval1[i] = (pre_hval1[i] + ch2num) % MOD1;
    pre_hval2[i] = (pre_hval2[i] + ch2num) % MOD2;
  }

  std::vector<int> suf_hval1(n), suf_hval2(n);
  for (int i = n - 1, ch2num; i >= 0; --i) {
    if (i < n - 1) {
      suf_hval1[i] = 1ll * suf_hval1[i + 1] * P1 % MOD1;
      suf_hval2[i] = 1ll * suf_hval2[i + 1] * P2 % MOD2;
    }
    ch2num = s[i] - 'a';
    suf_hval1[i] = (suf_hval1[i] + ch2num) % MOD1;
    suf_hval2[i] = (suf_hval2[i] + ch2num) % MOD2;
  }

  auto transform = [&](int p) -> std::pair<int, int> {
    int h1 = 0, h2 = 0;
    if (p < n - 1) {
      h1 = (suf_hval1[p + 1] + 1ll * pre_hval1[p] * pow1[n - p - 1] % MOD1) % MOD1;
      h2 = (suf_hval2[p + 1] + 1ll * pre_hval2[p] * pow2[n - p - 1] % MOD2) % MOD2;
    }
    else {
      h1 = pre_hval1[p], h2 = pre_hval2[p];
    }
    return std::make_pair(h1, h2);
  };

  for (int i = 0; i < n; ++i) {
    std::pair<int, int> ret = transform(i);
    if (ret == chk1 || ret == chk2) {
      std::cout << i + 1 << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while(t--) charming();
  return 0;
}