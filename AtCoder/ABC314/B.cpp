#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 40;

int n, x;

void init () {}

void charming () {
  init ();
  cin >> n;
  vector <int> c (n);
  vector <array <int, M> > bet (n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    for (int j = 0, k; j < c[i]; ++j) {
      cin >> k;
      bet[i][k] = 1;
    }
  }
  cin >> x;
  vector <int> vec;
  for (int i = 0; i < n; ++i) if (bet[i][x]) {
    while ((int) vec.size () && c[vec.back ()] > c[i]) vec.pop_back ();
    if (((int) vec.size () && c[vec.back ()] == c[i]) || vec.empty ()) vec.emplace_back (i);
  } 
  cout << (int) vec.size () << endl;
  for (int i : vec) cout << i + 1 << " ";
  cout << endl;
}

signed main () {
  charming ();
  return 0;
}