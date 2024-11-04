#include<bits/stdc++.h>
#define ll long long
const int P1 = 1331, P2 = 2333;
const int MOD1 = 1e9 + 7, MOD2 = 998244353;

void charming() {
  int n;
  std::string s; std::cin >> s; n = s.size();

  std::vector<int> pow1(n), pow2(n), nxta(n, -1);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'a') {
      if (i == n - 1 || s[i + 1] != 'a') nxta[i] = i;
      else nxta[i] = nxta[i + 1];
    }
    else nxta[i] = -1;
  }
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

  auto get_seq_hval = [&](int l, int r) -> std::pair<int, int> {
    int h1 = 0, h2 = 0;
    h1 = pre_hval1[r], h2 = pre_hval2[r];
    if (l) {
      h1 = (h1 - 1ll * pre_hval1[l - 1] * pow1[r - l + 1] % MOD1 + MOD1) % MOD1;
      h2 = (h2 - 1ll * pre_hval2[l - 1] * pow2[r - l + 1] % MOD2 + MOD2) % MOD2;
    }
    return std::make_pair(h1, h2);
  };

  ll ans = 0, st = 0, en = n - 1;
  while (st < n && s[st] == 'a') ++st;
  while (en >= 0 && s[en] == 'a') --en;
  if (st >= n) {
    std::cout << n - 1 << '\n';
    return;
  }
  else {
    for (int l = 1; st + l - 1 < n; ++l) {
      if (l == 1 && s[st + l - 1] == 'a') continue;
      else {
        int now = st, mn = st, nxt;
        bool ok = true;
        std::pair<int, int> chk = get_seq_hval(st, st + l - 1);
        while (now < n) {
          nxt = now + l;
          if (s[nxt] == 'a') {
            if (nxta[nxt] + 1 < n) {
              mn = std::min(mn, nxta[nxt] - nxt + 1);
            }
            nxt = nxta[nxt] + 1;
          }
          else if (nxt < n) {
            mn = 0;
          }
          now = nxt;
          if (now >= n) break;
          else if (now + l - 1 >= n) {
            ok = false;
            break;
          }
          else if (get_seq_hval(now, now + l - 1) != chk) {
            ok = false;
            break;
          }
        }
        if (ok) ans = ans + 1 + mn;
      }
    }
    std::cout << ans << '\n';
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