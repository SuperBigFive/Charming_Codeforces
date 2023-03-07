#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> h (n + 1);
	int id = -1;
	for (int i = 1, mx = -1; i <= n; ++i) {
		cin >> h[i];	
		if (h[i] > mx) {
			mx = h[i];
			id = i;
		}
	}
	cout << id << endl;
}

signed main () {
	charming ();
	return 0;
}