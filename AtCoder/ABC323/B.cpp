#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 5;

int n;
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
  cin >> n;
  vector <pair <int, int> > rank (n);
  for (int i = 0; i < n; ++i) {
    rank[i].second = i + 1;
    int cnt = 0;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == 'o') ++cnt;
    } 
    rank[i].first = cnt;
  }
  sort (rank.begin (), rank.end (), [] (pair <int, int> x,
  pair <int, int> y) {
    if (x.first != y.first) return x.first > y.first;
    else return x.second < y.second;
  });
  for (int i = 0; i < n; ++i) cout << rank[i].second << " \n"[i == n - 1];
}

signed main () {
  charming ();
  return 0;
}
