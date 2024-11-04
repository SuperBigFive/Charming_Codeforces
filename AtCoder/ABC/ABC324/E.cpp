#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

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

int n, m;
int pre[N], suf[N];
string t, s;

void init () {}

void charming () {
  init ();
  cin >> n >> t, m = t.size ();
  for (int i = 1, p; i <= n; ++i) {
    cin >> s, p = 0;
    for (char ch : s) {
      if (p < m && ch == t[p]) ++p;
    }
    ++pre[p];
    reverse (s.begin (), s.end ());
    p = m - 1;
    for (char ch : s) {
      if (p >= 0 && ch == t[p]) --p;
    }
    ++suf[p + 1];
  }
  for (int i = 1; i <= m + 1; ++i) suf[i] += suf[i - 1];
  ll ans = 0;
  for (int i = 0; i <= m; ++i) {
    ans += 1ll * pre[i] * suf[i];
    // if (i >= (m + 1) / 2) ans -= pre[i];
  }
  cout << ans << endl;
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}