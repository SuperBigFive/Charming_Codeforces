#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
string s;

void charming () {
  cin >> n >> s;
  string rs = s;
  reverse (rs.begin (), rs.end ());
  if (s <= rs) cout << s << endl;
  else {
    string ns = s;
    reverse (s.begin (), s.end ());
    s += ns;
    cout << s << endl;
  }
}

signed main () {
  cin >> t;
  while (t--) charming ();
  return 0;
}