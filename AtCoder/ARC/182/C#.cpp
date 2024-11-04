#include <bits/stdc++.h>
using ll = long long;
const int MOD = 998244353;

struct Matrix {
  int n;
  std::vector<std::vector<int> > mat;

  Matrix() = default;
  Matrix(int _n) {
    n = _n;
    mat = std::vector<std::vector<int> > (n, std::vector<int> (n));
  }
};

std::vector<std::vector<int> > mul(std::vector<std::vector<int> > &mat1, 
std::vector<std::vector<int> > &mat2) {
  assert(mat1.size() == mat2.size());
  int n = mat1.size();
  std::vector<std::vector<int> > ans(n, std::vector<int> (n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        // std::cout << i << ' ' << j << ' ' << k << std::endl;
        ans[i][j] = (ans[i][j] + 1ll * mat1[i][k] * mat2[k][j] % MOD) % MOD;
      }
    }
  }

  return ans;
}

void charming() {
  ll n, m; std::cin >> n >> m;

  int cnt = 0;
  std::vector<int> prime = {2, 3, 5, 7, 11, 13};
  for (int p : prime) if (m >= p) ++cnt;

  Matrix a(1 << cnt);
  for (int i = 0; i < cnt; ++i) a.mat[i][i] = 1;
  for (int i = 1; i < (1 << cnt); ++i) {
    for (int j = 1; j <= m; ++j) {
      int c = 0;
      std::vector<std::pair<int, int> > add;
      for (int k = 0; k < (int)prime.size(); ++k) {
        if (i >> k & 1 ^ 1) continue;

        if ((j % prime[k]) == 0) {
          int tmp = j, cnt = 0;
          while ((tmp % prime[k]) == 0) tmp /= prime[k], ++cnt;
          add.emplace_back(std::make_pair(k, cnt));
          ++c;
        }
      }

      if (c == 0) a.mat[i][i] += 1;
      else if (c == 1) {
        a.mat[i][i - (1 << add[0].first)] += add[0].second;
      }
      else if (c == 2) {
        int k0 = add[0].first, k1 = add[1].first;
        a.mat[i][i - (1 << k0)] += add[0].second;
        a.mat[i][i - (1 << k1)] += add[1].second;
        a.mat[i][i - (1 << k1) - (1 << k0)] += add[0].second * add[1].second;
      }
    }
  }

  Matrix ans(1 << cnt);
  for (int i = 0; i < (1 << cnt); ++i) ans.mat[i][i] = 1;
  while (n) {
    if (n & 1) ans.mat = mul(ans.mat, a.mat);
    n >>= 1, a.mat = mul(a.mat, a.mat);
  }

  int sum = 0;
  for (int i = 0; i < (1 << cnt); ++i) {
    sum = (sum + a.mat[(1 << cnt) - 1][i]) % MOD;
  }
  
  std::cout << sum << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  charming();
  return 0;
}
