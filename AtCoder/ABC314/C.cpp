#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 40;

int n, m;
string s;

void init () {}

void charming () {
  init ();
  cin >> n >> m >> s;
  vector <int> col (n);
  vector <vector <int> > pos (m);
  for (int i = 0; i < n; ++i) {
    cin >> col[i], --col[i];
    pos[col[i]].emplace_back (i);
  }
  vector <int> head (m);
  for (int i = 0; i < m; ++i) head[i] = (int) pos[i].size () - 1;
  for (int i = 0; i < n; ++i) {
    cout << s[pos[col[i]][head[col[i]]]];
    ++head[col[i]];
    head[col[i]] %= (int) pos[col[i]].size ();
  }
}

signed main () {
  charming ();
  return 0;
}