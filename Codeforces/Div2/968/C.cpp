#include <bits/stdc++.h>
using ll = long long;
const int N = 26;

void charming() {
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  std::vector<int> cnt(N);
  for (int i = 0, ch2num; i < n; ++i) {
    ch2num = s[i] - 'a';
    ++cnt[ch2num];
  }
  for (int i = 0, lst = -1; i < n; ++i) {
    int mx_cnt = -1, mx_ch = -1;
    for (int j = 0; j < N; ++j) {
      if (j == lst) continue;
      else if (cnt[j] && cnt[j] > mx_cnt) {
        mx_cnt = cnt[j];
        mx_ch = j;
      }
    }
    if (mx_ch == -1) mx_ch = lst;
    lst = mx_ch;
    --cnt[mx_ch];
    std::cout << (char)('a' + mx_ch);
  }
  std::cout << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  while (t--) charming();
  return 0;
}