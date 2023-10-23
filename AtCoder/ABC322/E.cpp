#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 5;
const int K = 5;
const int M = 1e5 + 5;

int n, k, p;
int c[N], POW10[K], a[N][K];
ll dp[N][M];

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

int getDigit (int x, int p) {
  return (x / POW10[p]) % 10;
}

void init () {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) dp[i][j] = LLONG_MAX;
  }
}

void charming () {
  init ();
  n = read (), k = read (), p = read ();
  POW10[0] = 1;
  for (int i = 1; i < K; ++i) POW10[i] = POW10[i - 1] * 10;
  for (int i = 1; i <= n; ++i) {
    c[i] = read ();
    for (int j = 0; j < k; ++j) a[i][j] = read ();
  }
  int init_st = 0;
  for (int i = 0; i < k; ++i) init_st = init_st * 10 + p;
  dp[0][init_st] = 0;
  for (int i = 0; i < n; ++i) {
    for (int st = 0; st < M; ++st) if (dp[i][st] < LLONG_MAX) {
      int nst = 0;
      for (int d = k - 1, req; d >= 0; --d) {
        req = max (0, getDigit (st, d) - a[i + 1][d]);
        nst = nst * 10 + req;
      }
      // cout << i << " " << st << " " << nst << endl;
      dp[i + 1][st] = min (dp[i + 1][st], dp[i][st]);
      dp[i + 1][nst] = min (dp[i + 1][nst], dp[i][st] + c[i + 1]);
    }
  }
  if (dp[n][0] >= LLONG_MAX) printf ("-1\n");
  else printf ("%lld\n", dp[n][0]);
}

signed main () {
  charming ();
  return 0;
}