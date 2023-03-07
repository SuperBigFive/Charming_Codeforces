#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
void init () {}

void charming () {
	init ();
	cin >> n;
	if (n == 3) {
		cout << "1 3 2" << endl;
		return;
	}
	else {
		if (n & 1) {
			for (int i = 1; i <= n; ++i) {
				if (i & 1) {
					cout << i / 2 + 1 << " ";
				}
				else {
					cout << i / 2 + n / 2 + 1 << " ";
				}
			}
		}
		else {
			for (int i = 1; i <= n; ++i) {
				if (i & 1) {
					cout << i / 2 + n / 2 + 1 << " ";
				}
				else {
					cout << i / 2 << " ";
				}
			}
		}
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}