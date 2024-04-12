#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
int a[N], cnt[N];

void charming () {
  cin >> n;
  for (int i = 0; i <= n; ++i) cnt[i] = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
  int fir_zero = 0;
  while (cnt[fir_zero]) ++fir_zero;
  int fir_one = 0, sec_one;
  while (cnt[fir_one] != 1 && fir_one <= n) ++fir_one;
  if (fir_one > n) {
    cout << fir_zero << endl;
  }
  else {
    sec_one = fir_one + 1;
    while (cnt[sec_one] != 1 && sec_one <= n) ++sec_one;
    if (sec_one > n) {
      cout << fir_zero << endl;
    }
    else cout << min (sec_one, fir_zero) << endl;
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