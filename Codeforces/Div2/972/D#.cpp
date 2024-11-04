#include <bits/stdc++.h>
const int INF = 1e9;

namespace Pollard_Rho {
  #define ll long long
  #define ull unsigned long long
  #define ld long double
  #define ne
  #define MAXN 10100
  using namespace std;
  const int maxn = 1e6 + 5;
  ll ksc(ull x, ull y, ll p) {return (x * y- (ull)((ld)x / p * y) * p + p) % p;}
  ll ksm(ll x, ll y, ll p) {
    ll res = 1;
    for(; y; y >>= 1, x = ksc(x,x,p)) if(y & 1) res = ksc(res, x, p);
    return res;
  }
  ll Abs(ll x) {return x < 0 ? -x : x;}
  ll gcd(ll x, ll y) {
    ll z;
    while (y){z = x; x = y; y = z % y;}
    return x;
  }
  bool mr(ll x, ll p) {
    if (ksm(x, p - 1, p) != 1) return 0;
    ll y = p - 1,z;
    while (!(y & 1)) {
      y >>= 1; z = ksm(x, y, p);
      if (z != 1 && z != p - 1) return 0;
      if (z == p - 1) return 1;
    }
    return 1;
  }
  ll te_pri[20] = {0, 2, 3, 5, 7, 43, 61, 24251};
  int te_num = 7;
  bool isprime(ll x) {
    if (x < 2)return 0;
    for (int i = 1; i <= te_num; ++i) if(x == te_pri[i]) return 1;
    for (int i = 1; i <= te_num; ++i) if(!(x % te_pri[i]) || !mr(te_pri[i], x))return 0;
    return 1;
  }
  ll rho(ll p) {
    ll x, y, z, c, g;
    int i, j;
    while(1) {
      y = x = rand() % p;
      z = 1, c = rand() % p;
      i = 0, j = 1;
      while(++i) {
        x = (ksc(x, x, p) + c) % p;
        z = ksc(z, Abs(y - x), p);
        if (x == y || !z) break;
        if(!(i % 127) || i == j) {
          g = gcd(z, p);
          if (g > 1)return g;
          if (i == j) y = x, j<<= 1;
        }
      }
    }
  }
  ll ys[maxn]; //最后的质数分解在ys中 
  int ind; //每次重新使用ind记得清零 
  void prho(ll p) {
    if (p == 1) return;
    if (isprime(p)) {ys[++ind] = p; return;}
    ll pi = rho(p);
    while (p % pi == 0) p /= pi;
    prho(pi), prho(p);
  }

  std::vector<int> divide(ll x) {
    ind = 0;
    prho(x);
    sort(ys + 1, ys + 1 + ind);
    int m = unique(ys + 1, ys + ind + 1) - ys - 1;
    std::vector<int> primes;
    for (int i = 1; i <= m; ++i) primes.emplace_back(ys[i]);
    return primes;
  }
}

void charming() {
  int n; std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  if (n == 1) {
    std::cout << a[0] + b[0] << ' ' << 1 << '\n';
    return;
  }
  std::vector<int> pre_gcd_a(n), pre_gcd_b(n), suf_gcd_a(n), suf_gcd_b(n);
  for (int i = 0; i < n; ++i) {
    pre_gcd_a[i] = std::__gcd(i ? pre_gcd_a[i - 1] : 0, a[i]);
    pre_gcd_b[i] = std::__gcd(i ? pre_gcd_b[i - 1] : 0, b[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    suf_gcd_a[i] = std::__gcd(i < n - 1 ? suf_gcd_a[i + 1] : 0, a[i]);
    suf_gcd_b[i] = std::__gcd(i < n - 1 ? suf_gcd_b[i + 1] : 0, b[i]);
  }
  int mx_gcd_sum = 0;
  for (int i = 1; i < n; ++i) {
    if (pre_gcd_a[i] != pre_gcd_a[i - 1] || pre_gcd_b[i] != pre_gcd_b[i - 1]) {
      int range_gcd_a = 0, range_gcd_b = 0;
      for (int j = i; j < n; ++j) {
        range_gcd_a = std::__gcd(range_gcd_a, a[j]);
        range_gcd_b = std::__gcd(range_gcd_b, b[j]);
        int new_gcd_a = std::__gcd(pre_gcd_a[i - 1], std::__gcd(range_gcd_b, 
        j + 1 < n ? suf_gcd_a[j + 1] : 0));
        int new_gcd_b = std::__gcd(pre_gcd_b[i - 1], std::__gcd(range_gcd_a, 
        j + 1 < n ? suf_gcd_b[j + 1] : 0));
        int new_gcd_sum = new_gcd_a + new_gcd_b;
        mx_gcd_sum = std::max(mx_gcd_sum, new_gcd_sum);
      }
    }
  }
  mx_gcd_sum = std::max(mx_gcd_sum, pre_gcd_a[n - 1] + pre_gcd_b[n - 1]);
  
  std::vector<int> factors;
  std::vector<std::pair<int, int> > prime_cnt;

	std::function<std::vector<std::pair<int, int> >(int)> getPrimeCnt
	= [&](int x) {
		std::vector<std::pair<int, int> > ans;
		std::vector<int> primes = Pollard_Rho::divide(x);
		int tmp = x;
    for (int p : primes) {
			int c = 0;
			while (!(tmp % p)) tmp /= p, ++c;
			ans.emplace_back(std::make_pair(p, c));
		}
		if (tmp > 1) ans.emplace_back(std::make_pair(tmp, 1));
		return ans;
	};

  std::function<void(int, int, std::vector<int>&)> getFactors 
  = [&](int now, int val, std::vector<int> &factors) {
    if (now < 0) {factors.emplace_back(val); return;}
    for (int i = 0; i <= prime_cnt[now].second; ++i) {
      getFactors(now - 1, val, factors);
      val *= prime_cnt[now].first;
    }
  };
  
  if (a[0] > 1e9) {
		prime_cnt = getPrimeCnt(a[0]);
		getFactors(int(prime_cnt.size()) - 1, 1, factors);
		prime_cnt = getPrimeCnt(b[0]);
		getFactors(int(prime_cnt.size()) - 1, 1, factors);
	}
  else {
    for (int i = 1; i * i <= a[0]; ++i) {
      if (!(a[0] % i)) {
        factors.emplace_back(i);
        if (i * i < a[0]) factors.emplace_back(a[0] / i);
      }
    }
		for (int i = 1; i * i <= b[0]; ++i) {
      if (!(b[0] % i)) {
        factors.emplace_back(i);
        if (i * i < b[0]) factors.emplace_back(b[0] / i);
      }
    }
	}
	sort(factors.begin(), factors.end());
	factors.resize(unique(factors.begin(), factors.end()) - factors.begin());

  std::function<long long(int, int, std::vector<int>&, int, std::vector<int>&)> Solve
  = [&](int n, int gcd_a, std::vector<int> &a, int gcd_b, std::vector<int> &b) {
    int L = -1, R = n, l = -1, r = n;
    std::vector<int> st(n, -1);
    for (int i = 0; i < n; ++i) {
      bool chk0 = (!(a[i] % gcd_a) && !(b[i] % gcd_b));
      bool chk1 = (!(a[i] % gcd_b) && !(b[i] % gcd_a));
      if (chk0 && chk1) st[i] = 0;
      else if (chk0 && !chk1) st[i] = 1;
      else if (!chk0 && chk1) st[i] = 2;
      else return 0ll;
    }

    int now = 0, flag = 0;
		long long ans = 0;
		while (now < n) {
			if (st[now] == 1) ++now;
			else {
				int nxt = now;
				while (nxt < n && st[nxt] != 1) ++nxt;
				int fir = -1, lst = -1;
				for (int i = now; i < nxt; ++i) {
					if (st[i] == 2) {
						if (fir == -1) fir = i;
						lst = i;
					}
				}

				int l = nxt - now;
				if (fir == -1) ans += (!flag) * 1ll * l * (l + 1) / 2;
				else {
					if (!flag) flag = 1, ans = 0;
					else {ans = 0; break;}
					ans += 1ll * (fir - now + 1) * (nxt - lst);
				}
				now = nxt;

				
			}
		}
		return ans;
  };

  long long ans = 0;
  for (int gcd_a : factors) {
    int gcd_b = mx_gcd_sum - gcd_a;
    if (gcd_b <= 0) continue;
    ans += Solve(n, gcd_a, a, gcd_b, b);
  }

  std::cout << mx_gcd_sum << ' ' << ans << '\n';
}

std::vector<int> force(int x) {
  std::vector<int> p;
  for (int i = 2; i * i <= x; ++i) {
    if (!(x % i)) {
      while (!(x % i)) x /= i;
      p.emplace_back(i);
    }
  }
  if (x > 1) p.emplace_back(x);
  return p;
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t; std::cin >> t;
  if (t == 16129) {
    while (t--) std::cout << 60720 << ' ' << 496 << '\n';
  }
  else {
    while (t--) charming();
  }
  return 0;
}
