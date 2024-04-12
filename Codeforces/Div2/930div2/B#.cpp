#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
string a[2];

// bool lt (string s1, string s2) {
//   for (int i = 0; i < n; ++i) {
//     if (s1[i] == '1' && s2[i] == '0') return false;
//     if (s1[i] == '0' && s2[i] == '1') return true;
//   }
//   return true;
// }

void charming () {
  cin >> n;
  cin >> a[0] >> a[1];
  string ans; ans += a[0][0];
  int idl = -1, idr = -1;
  for (int i = 1; i < n; ++i) {
    if (a[0][i] == '1' && a[1][i - 1] =='0') {
      ans += a[1].substr (i - 1);
      idl = idr = i - 1;
      break;
    }
    else ans += a[0][i];
  }
  if (ans.size () <= n) ans += a[1][n - 1], idl = idr = n - 1;
  int l = 0, r = idl;
  while (l <= r) {
    int mid = (l + r) / 2;
    string ns = a[0].substr (0, mid + 1) + a[1].substr (mid);
    // cout << mid << " " << ns << " " << ans << " " << lt (ns, ans) << endl;
    if (ns == ans) {
      r = mid - 1;
      idl = mid;
    }
    else l = mid + 1;
  }
  l = idr, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    string ns = a[0].substr (0, mid + 1) + a[1].substr (mid);
    // cout << mid << " " << ns << endl;
    if (ns == ans) {
      l = mid + 1;
      idr = mid;
    }
    else r = mid - 1;
  }
  cout << ans << endl;
  cout << idr - idl + 1 << endl;
  // cout << idr << " " << idl << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}