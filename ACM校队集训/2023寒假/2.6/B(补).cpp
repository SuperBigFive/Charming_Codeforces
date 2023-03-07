#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	if (n == 2) {
		if (k > 1) cout << "NO" << endl;
		else if (k == 1) cout << "YES" << endl << "#." << endl << ".." << endl;
		else cout << "YES" << endl << ".." << endl << ".." << endl;
	} 
	else if (k > n * n - n) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 1, cnt = 0; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (cnt >= k || (i == 1 && j == n) || 
				(i == n && j == 1) || (i > 1 && i < n && i == j)) cout << ".";
				else ++cnt, cout << "#";
			}
			cout << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}