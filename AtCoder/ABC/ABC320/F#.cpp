#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int H = 305;

int n, h;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

void init () {}

void charming () {
  init ();
  n = read (), h = read ();
  vector <int> x (n + 1), price (n + 1), fuel (n + 1);
  vector <array <int, 2> > sta (n + 1);
  for (int i = 1; i <= n; ++i) x[i] = read ();
  for (int i = 1; i < n; ++i) price[i] = read (), fuel[i] = read ();
  
  auto Check = [&] (int x, int y) -> bool {
    return x >= 0 && x <= h && y >= 0 && y <= h;
  };

  vector <vector <vector <int> > > dp (n + 1, 
  vector <vector <int> > (H + 1, vector <int> (H, INT_MAX)));
  dp[0][h][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= h; ++j) {
      for (int k = 0; k <= h; ++k) {
        if (dp[i][j][k] >= INT_MAX) continue;
        int nj, nk, dist = x[i + 1] - x[i];
        if (j - dist < 0 || k + dist > h) continue;
        nj = j - dist, nk = k + dist;
        if (Check (nj, nk)) {
          dp[i + 1][nj][nk] = min (dp[i + 1][nj][nk], dp[i][j][k]);
        }
        nj = min (j - dist + fuel[i + 1], h), nk = k + dist;
        if (Check (nj, nk)) {
          dp[i + 1][nj][nk] = min (dp[i + 1][nj][nk], dp[i][j][k] + price[i + 1]);
        } 
        nj = j - dist, nk = max (0, k + dist - fuel[i + 1]);
        if (Check (nj, nk)) {
          dp[i + 1][nj][nk] = min (dp[i + 1][nj][nk], dp[i][j][k] + price[i + 1]);
        }
      }
    }
  }
  
  int ans = INT_MAX;
  for (int j = 0; j <= h; ++j) {
    for (int k = 0; k <= j; ++k) ans = min (ans, dp[n][j][k]);
  }
  if (ans >= INT_MAX) printf ("-1\n");
  else printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}