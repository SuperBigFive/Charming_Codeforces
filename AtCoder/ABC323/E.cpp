#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
const int MOD = 998244353;

int n, invn, x;
int song[N], dp[N];

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

int QSM (int x, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) ans = (1ll * ans * x) % MOD;
    p >>= 1, x = (1ll * x * x) % MOD;
  }
  return ans;
}

int DP (int tim) {
  if (tim == 0) return dp[tim] = 1;
  else if (dp[tim] != -1) return dp[tim];
  dp[tim] = 0;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (tim - song[i] >= 0) {
      ++cnt;
      (dp[tim] += 1ll * DP (tim - song[i]) * invn % MOD) %= MOD;
    }
  }
  return dp[tim];
}

void init () {for (int i = 0; i < N; ++i) dp[i] = -1;}

void charming () {
  init ();
  n = read (), x = read ();
  invn = QSM (n, MOD - 2);
  for (int i = 1; i <= n; ++i) song[i] = read ();
  int ans = 0;
  for (int i = max (0, x - song[1] + 1); i <= x; ++i) {
    (ans += 1ll * DP (i) * invn % MOD) %= MOD;
  }
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
