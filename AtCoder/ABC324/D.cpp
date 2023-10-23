#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

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

int n;
string s;

void init () {}

void charming () {
  init ();
  cin >> n >> s;
  vector <int> cnt (10);
  for (char ch : s) ++cnt[ch - '0'];
  int ans = 0;
  for (int i = 0; ; ++i) {
    ll j = 1ll * i * i, d = 0;
    vector <int> req (10);
    ll tmp = j;
    while (tmp) ++req[tmp % 10], tmp /= 10, ++d;
    if (d > n) break;
    else req[0] += n - d;
    if (req == cnt) ++ans;
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