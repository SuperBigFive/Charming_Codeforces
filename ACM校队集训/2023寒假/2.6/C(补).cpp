#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = (1 << 20) + 5;

int n;

void init () {} 

void charming () {
	init ();
	cin >> n;
	vector <int> a (1 << n);
	for (auto &it : a) cin >> it;
	for (int x = 0; x < 1 << n; ++x) {
		for (int y = 1; y < 1 << n; y <<= 1) if (!(x & y)) {
			for (int z = 1; z < 1 << n; z <<= 1) if (!(x & z) && y != z) {
				if (a[x + y] + a[x + z] < a[x] + a[x + y + z]) {
					cout << x + y << " " << x + z << endl;
					return;
				}
			}
		}
	}
	cout << -1 << endl;
	return;
}

signed main () {
	charming ();
	return 0;
}