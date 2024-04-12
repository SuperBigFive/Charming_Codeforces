#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int M = 26;

int t, n, q;
string s;
int ra[N << 1];
int pre_odd[N][M], pre_even[N][M];

void Manacher () {
  string ns = "#";
  for (int i = 0; i < n; ++i) ns += '#', ns += s[i]; ns += '#';
  int m = n << 1 | 1;
  for (int i = 0; i <= m; ++i) ra[i] = 0;
  for (int i = 1, l = 0, r = 0; i <= m; ++i) {
    if (i <= r) ra[i] = min (r - i + 1, ra[l + r - i]);
    while (i + ra[i] <= m && i - ra[i] >= 1 &&
    ns[i + ra[i]] == ns[i - ra[i]]) ++ra[i];
    if (r < i + ra[i] - 1) r = i + ra[i] - 1, l = i - ra[i] + 1;
  }
  // for (int i = 1; i <= m; ++i) cout << ra[i] << " \n"[i == m];
}

bool is_palindrome (int l, int r) {
  int len = r - l + 1, mid = l + r >> 1;
  if (len & 1) {
    return ra[mid << 1] - 1 >= len;
  }
  else {
    return ra[(mid << 1) + 1] - 1 >= len;
  }
}

void charming () {
  cin >> n >> q >> s;
  Manacher ();
  for (int i = 1, ch2num; i <= n; i += 2) {
    ch2num = s[i - 1] - 'a';
    for (int j = 0; j < M; ++j) {
      if (i > 1) pre_odd[i][j] = pre_odd[i - 2][j];
      else pre_odd[i][j] = 0;
    }
    ++pre_odd[i][ch2num];
  }
  for (int i = 2, ch2num; i <= n; i += 2) {
    ch2num = s[i - 1] - 'a';
    for (int j = 0; j < M; ++j) {
      if (i > 2) pre_even[i][j] = pre_even[i - 2][j];
      else pre_even[i][j] = 0;
    }
    ++pre_even[i][ch2num];
  }
  for (int i = 1, l, r; i <= q; ++i) {
    cin >> l >> r;
    ll ans = 0;
    bool chk_odd_same = false, chk_even_same = false;
    
    int l_odd = (l & 1 ? l : l + 1);
    int r_odd = (r & 1 ? r : r - 1);
    int mx_odd = -1, mx_odd_ch = -1;
    for (int j = 0; j < M; ++j) {
      int cnt = pre_odd[r_odd][j] - (l_odd - 2 >= 1 ? pre_odd[l_odd - 2][j] : 0);
      if (cnt > mx_odd) mx_odd = cnt, mx_odd_ch = j;
    }
    if (mx_odd == (r_odd - l_odd) / 2 + 1) chk_odd_same = true;

    int l_even = (l & 1 ? l + 1 : l);
    int r_even = (r & 1 ? r - 1 : r);
    int mx_even = -1, mx_even_ch = -1;
    for (int j = 0; j < M; ++j) {
      int cnt = pre_even[r_even][j] - (l_even - 2 >= 2 ? pre_even[l_even - 2][j] : 0);
      if (cnt > mx_even) mx_even = cnt, mx_even_ch = j;
    }
    if (mx_even == (r_even - l_even) / 2 + 1) chk_even_same = true;

    int len = r - l + 1;
    if (chk_odd_same && chk_even_same) {
      if (mx_odd_ch == mx_even_ch) ans = 0;
      else {
        int k = len / 2 * 2;
        ans = 1ll * (k / 2) * (k / 2 + 1);
        if (is_palindrome (l, r) && k == len) ans -= k;
      }
    }
    else {
      ans = 1ll * len * (len + 1) / 2 - 1;
      if (is_palindrome (l, r)) ans -= len;
    }
    cout << ans << endl;
  }
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}