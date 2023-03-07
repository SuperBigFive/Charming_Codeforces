#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {} ());

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; ++i) cin >> s;
	for (int i = 1; i <= 50000; ++i) {
		int r = rnd () % 4;
		if (r == 0) cout << "U";
		else if (r == 1) cout << "D";
		else if (r == 2) cout << "L";
		else cout << "R";
	}
}

signed main () {
  charming ();
  return 0;
}