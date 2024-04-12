#include <bits/stdc++.h>
using namespace std;

int t, n;
int pre[200005];

int main () {
  cin >> t;
  while (t--) {
    string s;
    cin >> s, n = s.size ();
    if (n <= 1) {
      cout << 0 << endl;
      continue;
    }
    int mx = n / 2 * 2, ans = -1;
    for (int k = mx; k >= 2 && ans == -1; k -= 2) {
      for (int i = 0; i < n - k / 2; ++i) {
        if (i) pre[i] = pre[i - 1];
        else pre[i] = 0;
        if (s[i] == s[i + k / 2] || s[i] == '?' 
        || s[i + k / 2] == '?') ++pre[i];
      }
      for (int i = k / 2 - 1; i < n - k / 2; ++i) {
        if (pre[i] - (i - k / 2 >= 0 ? pre[i - k / 2] : 0) == k / 2) {
          ans = k;
          break;
        }
      }
    }
    if (ans == -1) cout << 0 << endl;
    else cout << ans << endl;
  }
  return 0;
}