#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 5;

int n, m;
int a[N];
string s;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

void init () {}

void charming () {
  init ();
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> a[i];
  int mx = -1;
  vector <int> score (n);
  vector <vector <int> > remain (n);
  iota (score.begin (), score.end (), 1);
  bool mul = false;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'o') score[i] += a[j];
      else remain[i].emplace_back (j);
    } 
    sort (remain[i].begin (), remain[i].end (), [] (int x, int y) {
      return a[x] > a[y];
    });
    if (score[i] == mx) mul = true;
    else if (score[i] > mx) mx = score[i], mul = false;
  }
  for (int i = 0; i < n; ++i) {
    int delta = mx - score[i];
    // cout << mx << " " << score[i] << endl;
    if (delta == 0) {
      if (mul) cout << 1 << endl;
      else cout << 0 << endl;
    } else {
      int cnt = 0;
      while (delta > 0) {
        delta -= a[remain[i][cnt++]];
      } 
      cout << cnt << endl;
    }
  }
}

signed main () {
  charming ();
  return 0;
}
