#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 40;

int n, q;
string s;

void init () {}

void charming () {
  init ();
  cin >> n >> s >> q;
  int last = 0, opt, x, y;
  char c;
  vector <array <int, 3> > qry;
  for (int i = 0; i < q; ++i) {
    cin >> opt >> x >> c;
    qry.emplace_back ((array <int, 3>) {opt, x, c - 'a'});
    if (opt > 1) last = i;
  }
  for (int i = 0; i < q; ++i) {
    opt = qry[i][0], x = qry[i][1], y = qry[i][2];
    if (opt == 1) s[x - 1] = 'a' + y;
    else {
      if (i == last) {
        if (opt == 2) {
          for (auto &ch : s) {
            if (ch - 'a' < 0) ch = 'a' + (ch - 'A');
          }
        }
        else {
          for (auto &ch : s) {
            if (ch - 'a' >= 0) ch = 'A' + (ch - 'a');
          }
        }
      }
    }
  }
  cout << s << endl;
}

signed main () {
  charming ();
  return 0;
}