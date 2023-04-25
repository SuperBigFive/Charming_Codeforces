#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, d;

void init () {}

void charming () {
	init ();
	cin >> n >> d;
	vector <int> a (n + 5);
	int id = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i > 1 && a[i] - a[i - 1] <= d && id == -1) id = a[i];
	}
	cout << id << endl;
}

signed main () {
	charming ();
	return 0;
}