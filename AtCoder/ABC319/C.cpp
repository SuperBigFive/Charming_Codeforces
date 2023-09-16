#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

void init () {}

void charming () {
  init ();
  vector <vector <int> > c (3, vector <int> (3));
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> c[i][j];
  vector <int> p (9);
  iota (p.begin (), p.end (), 1);
  int cnt = 0, sum = 1;
  for (int i = 1; i <= 9; ++i) sum *= i;
  do {
    vector <vector <int> > a (3, vector <int> (3));
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        a[i][j] = p[i * 3 + j];
      }
    }
    bool chk = true;
    for (int i = 0; i < 3; ++i) {
      vector <int> b;
      for (int j = 0; j < 3; ++j) b.emplace_back (c[i][j]);
      vector <int> d (3);
      iota (d.begin (), d.end (), 0);
      sort (d.begin (), d.end (), [&] (int x, int y) {
        return a[i][x] < a[i][y];
      });
      if (b[d[0]] == b[d[1]]) {chk = false; break;}
    }
    for (int j = 0; j < 3; ++j) {
      vector <int> b;
      for (int i = 0; i < 3; ++i) b.emplace_back (c[i][j]);
      vector <int> d (3);
      iota (d.begin (), d.end (), 0);
      sort (d.begin (), d.end (), [&] (int x, int y) {
        return a[x][j] < a[y][j];
      });
      if (b[d[0]] == b[d[1]]) {chk = false; break;}
    }
    vector <int> b;
    for (int i = 0; i < 3; ++i) {
      b.emplace_back (c[i][i]);
    }
    vector <int> d (3);
    iota (d.begin (), d.end (), 0);
    sort (d.begin (), d.end (), [&] (int x, int y) {
      return a[x][x] < a[y][y];
    });
    if (b[d[0]] == b[d[1]]) chk = false;
    b.clear ();
    for (int i = 0; i < 3; ++i) {
      b.emplace_back (c[i][2 - i]);
    }
    sort (d.begin (), d.end (), [&] (int x, int y) {
      return a[x][2 - x] < a[y][2 - y];
    });
    if (b[d[0]] == b[d[1]]) chk = false;
    if (chk) ++cnt;
  } while (next_permutation (p.begin (), p.end ()));
  cout << fixed << setprecision (15) << 1.0 * cnt / sum << endl;
}

signed main () {
  charming ();
  return 0;
}