#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
int a[N];

void init () {}

void charming () {
  init ();
  cin >> n;
  map <int, int> cnt;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  if (cnt.size () > 2) puts ("NO");
  else if (cnt.size () == 1) puts ("YES");
  else {
    int c = cnt[a[1]];
    if (abs (c - (n - c)) <= 1) puts ("YES");
    else puts ("NO");
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}