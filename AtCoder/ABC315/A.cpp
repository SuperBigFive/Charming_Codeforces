#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

string s;

void init () {}

void charming () {
  init ();
  cin >> s;
  string ans;
  for (char ch : s) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
    else ans += ch;
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