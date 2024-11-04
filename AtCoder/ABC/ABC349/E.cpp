#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 10;

int pow3[N];
vector <vector <int> > a (3, vector <int> (3));

bool DFS (int st, int player) {
  set <int> color;
  for (int i = 0; i < 3; ++i) {
    color.clear ();
    for (int j = 0; j < 3; ++j) {
      int k = i * 3 + j, d = (st / pow3[k]) % 3;
      color.insert (d);
    }
    if ((int) color.size () == 1 && (*color.begin ()) != 0) {
      return (*color.begin ()) == 1;
    }
  }

  for (int j = 0; j < 3; ++j) {
    color.clear ();
    for (int i = 0; i < 3; ++i) {
      int k = i * 3 + j, d = (st / pow3[k]) % 3;
      color.insert (d);
    }
    if ((int) color.size () == 1 && (*color.begin ()) != 0) {
      return (*color.begin ()) == 1;
    }
  }

  color.clear ();
  for (int k : {0, 4, 8}) {
    int d = (st / pow3[k]) % 3;
    color.insert (d);
  }
  if ((int) color.size () == 1 && (*color.begin ()) != 0) {
    return (*color.begin ()) == 1;
  }

  color.clear ();
  for (int k : {2, 4, 6}) {
    int d = (st / pow3[k]) % 3;
    color.insert (d);
  }
  if ((int) color.size () == 1 && (*color.begin ()) != 0) {
    return (*color.begin ()) == 1;
  }

  //--------------------------------------------------------//

  ll fir_val = 0, sec_val = 0;
  bool all_color = true;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int k = i * 3 + j, d = (st / pow3[k]) % 3;
      if (d == 1) fir_val += a[i][j];
      else if (d == 2) sec_val += a[i][j];
      else all_color = false;
    }
  }
  if (all_color) return fir_val > sec_val;
  
  //--------------------------------------------------------//

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int k = i * 3 + j, d = (st / pow3[k]) % 3;
      if (d == 0) {
        int nst = st + pow3[k] * (player + 1);
        if (player ^ DFS (nst, player ^ 1)) return player ^ 1;
      }
    }
  }

  return player;
}

void charming () {
  pow3[0] = 1;
  for (int i = 1; i < N; ++i) pow3[i] = pow3[i - 1] * 3;
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> a[i][j];
  if (DFS (0, 0)) puts ("Takahashi");
  else puts ("Aoki");
}

signed main () {
  charming ();
  return 0;
}