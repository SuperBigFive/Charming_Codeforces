#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

int n;
int a[N], b[N], pow2[N], ban[N];

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
  n = read ();
  for (int i = 1; i <= n; ++i) a[i] = read (), b[i] = i;
  sort (b + 1, b + 1 + n, [] (int x, int y) {return a[x] > a[y];});
  pow2[0] = 1;
  for (int i = 1; i <= n; ++i) pow2[i] = (1ll * pow2[i - 1] * 2) % MOD;
  int ans = 0, remain = n;
  for (int i = 1, idx; i <= n; ++i) {
    idx = b[i];
    if (ban[idx]) continue;
    int cnt = 0;
    for (int j = 1; j * j <= idx; ++j) {
      if (idx % j) continue;
      else {
        if (!ban[j]) ++cnt;
        if (j * j != idx && !ban[idx / j]) ++cnt;
      }
    }
    ans = (ans + 1ll * a[idx] * (pow2[remain] - pow2[remain - cnt])) % MOD;
    for (int j = 1; j * j <= idx; ++j) {
      if (idx % j) continue;
      else {
        if (ban[j] == 0) --remain, ban[j] = true;
        if (ban[idx / j] == 0) --remain, ban[idx / j] = true;
      }
    }
  }
  ans = ((ans % MOD) + MOD) % MOD;
  printf ("%d\n", ans);
}

signed main () {
  charming ();
  return 0;
}
