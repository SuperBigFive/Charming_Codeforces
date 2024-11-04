#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 60;
const int M = 10;
const int MOD = 998244353;

ll n;
int a1, a2, a3;

char getch () {
  static char buf[100000], *s, *s2;
  return (s == s2) && (s2 = (s = buf) +
  fread (buf, 1, 100000, stdin)), s == s2 ? EOF : *s++;
}

ll read () {
  ll x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

void init () {}

void charming () {
  init ();
  n = read (), a1 = read (), a2 = read (), a3 = read (), ++n;

  auto getNewVec = [] () -> vector <vector <vector 
  <vector <vector <vector <int> > > > > > {
    return vector <vector <vector <vector <vector <vector <int> > > > > > (2,
    vector <vector <vector <vector <vector <int> > > > > (2,
    vector <vector <vector <vector <int> > > > (2,
    vector <vector <vector <int> > > (M,
    vector <vector <int> > (M,
    vector <int> (M))))));
  };

  int ans = 0;
  auto dp = getNewVec ();
  dp[0][0][0][0][0][0] = 1;
  for (int d = N - 1, chk; d >= 0; --d) {
    chk = (n >> d) & 1;
    auto ndp = getNewVec ();
    for (auto f1 : {0, 1}) for (auto f2 : {0, 1}) for (auto f3 : {0, 1}) {
      for (int r1 = 0; r1 < a1; ++r1) {
        for (int r2 = 0; r2 < a2; ++r2) {
          for (int r3 = 0; r3 < a3; ++r3) {
            for (int x1 = 0; x1 <= (f1 ? 1 : chk); ++x1) {
              for (int x2 = 0; x2 <= (f2 ? 1 : chk); ++x2) {
                for (int x3 = 0; x3 <= (f3 ? 1 : chk); ++x3) {
                  if (x1 ^ x2 ^ x3) continue;
                  else {
                    (ndp[f1 || x1 < chk][f2 || x2 < chk][f3 || x3 < chk]
                    [(r1 * 2 + x1) % a1][(r2 * 2 + x2) % a2][(r3 * 2 + x3) % a3]
                    += dp[f1][f2][f3][r1][r2][r3]) %= MOD;
                  }
                }
              }
            }
          }
        }
      }
    }
    dp = ndp;
  }
  ans = dp[1][1][1][0][0][0];
  --n;
  (ans -= n / (a1 * a2 / __gcd (a1, a2)) % MOD) %= MOD;
  (ans -= n / (a1 * a3 / __gcd (a1, a3)) % MOD) %= MOD;
  (ans -= n / (a2 * a3 / __gcd (a2, a3)) % MOD) %= MOD;
  --ans;
  ans = ((ans % MOD) + MOD) % MOD;
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
