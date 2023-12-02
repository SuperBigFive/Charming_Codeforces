#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
string s;
vector <int> ans;

void init () {ans.clear ();}

void Insert (int p) {
  ans.emplace_back (p + 1);
  string ns;
  for (int i = 0; i <= p; ++i) ns += s[i];
  ns += '0', ns += '1';
  for (int i = p + 1; i < s.size (); ++i) ns += s[i];
  s = ns;
}

void Solve (int l, int r) {
  // cout << s << " " << l << " " << r << endl;
  if ((int) ans.size () > 300) return;
  else if (l >= r) return;
  if (s[l] != s[r]) Solve (l + 1, r - 1);
  else if (s[l] == '0') {
    Insert (r);
    Solve (l + 1, r + 1);
  }
  else {
    Insert (l - 1);
    Solve (l + 1, r + 1);
  }
}

void charming () {
  init ();
  cin >> n >> s;
  if (n & 1) return cout << -1 << endl, void ();
  Solve (0, n - 1);
  if ((int) ans.size () > 300) cout << -1 << endl;
  else {
    cout << (int) ans.size () << endl;
    for (int i = 0, siz = ans.size (); i < siz; ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
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