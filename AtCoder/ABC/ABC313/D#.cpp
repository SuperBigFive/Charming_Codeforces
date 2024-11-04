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

int n, k;

int Ask (vector <int> &x) {
  cout << "? ";
  for (int i : x) cout << i << " ";
  cout << endl;
  fflush (stdout);
  int tmp;
  cin >> tmp;
  return tmp;
}

void Ans (vector <int> &a) {
  cout << "! ";
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
  fflush (stdout);
}

void init () {}

void charming () {
  init ();
  cin >> n >> k;
  vector <int> t1, t2;
  vector <int> ans (n + 1);
  int r = 0;
  for (int i = 1; i <= k + 1; ++i) {
    vector <int> x;
    for (int j = 1; j <= k + 1; ++j) {
      if (i != j) x.emplace_back (j);
    }
    ans[i] = Ask (x);
    r ^= ans[i];
  }
  for (int i = 1; i <= k + 1; ++i) ans[i] ^= r;
  int s = 0;
  for (int i = 1; i < k; ++i) s ^= ans[i];
  for (int i = k + 2; i <= n; ++i) {
    vector <int> x;
    for (int j = 1; j < k; ++j) x.emplace_back (j);
    x.emplace_back (i);
    ans[i] = s ^ Ask (x);
  }
  Ans (ans);
}

signed main () {
  charming ();
  return 0;
}