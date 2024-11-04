#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

char getch () { 
	static char buf[100000], *s1, *s2; 
	return (s1 == s2) && (s2 = (s1 = buf) + 
	fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++; 
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {ch = getch (); if (ch == '-') w = -1;}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

int n;

void init () {}

void charming () {
  init ();
  cin >> n;
  string s;
  cin >> s;
  vector <pair <int, int> > seq;
  for (int i = 0, j; i < n; i = j + 1) {
    j = i;
    if (s[i] == '1') {
      while (j + 1 < n && s[j + 1] == '1') ++j;
      seq.emplace_back (make_pair (1, j - i + 1));
    }
    else if (i < n - 1 && s[i + 1] != '1') return void (cout << -1 << endl);
    else seq.emplace_back (make_pair (s[i] - '0', 1));
  }
  reverse (seq.begin (), seq.end ());
  ll ans = 0;
  int last = 1;
  for (auto [num, cnt] : seq) {
    if (num == 1) {
      ans = (ans + (last - 1) * ans + cnt) % MOD;
    }
    else {
      ans = (ans + 1) % MOD;
      last = num;
    }
  }
  ans = ((ans - 1) % MOD + MOD) % MOD;
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}