#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e3 + 5;
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

int t, n;

int Send (int l, int r) {
  if (l >= r) return 0;
  cout << "? " << l << " " << r << endl;
  cout.flush ();
  int x;
  cin >> x;
  return x;
}

void Answer (int x) {
  cout << "! " << x << endl;
  cout.flush ();
}

void init () {}

void charming () {
  init ();
  cin >> n;
  for (int i = 1, r1, r2, rig, j; i <= n; i = j + 1) {
    rig = 1, j = i;
    // cout << "i = " << i << endl;
    while (true) {
      if (i + rig > n) {
        r1 = Send (i + 1, n);
        r2 = Send (i, n);
        if (r2 - r1 == n - i) {
          Answer (i);
          return;
        }
        else break;
      }
      else {
        r1 = Send (i + 1, i + rig);
        r2 = Send (i, i + rig);
        // cout << r1 << " " << r2 << endl;
        if (r2 - r1 == rig) j = i + rig, rig <<= 1;
        else break;
      }
    }
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}