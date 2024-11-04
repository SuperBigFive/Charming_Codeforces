#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <vector <int> > a (n + 5, vector <int> (n + 5));
	vector <vector <int> > b (n + 5, vector <int> (n + 5));
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	cin >> a[i][j];
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j) 
	cin >> b[i][j];
	for (int i = 1; i <= 4; ++i) {
		auto na = a;
		for (int j = 1; j <= n; ++j)
		for (int k = 1; k <= n; ++k)
		na[j][k] = a[n + 1 - k][j];
		a = na;
		bool ok = true;
		for (int j = 1; j <= n; ++j)
		for (int k = 1; k <= n; ++k)
		if (a[j][k] == 1 && b[j][k] == 0) ok = false;
		if (ok) 
		return void (cout << "Yes" << endl);
	}
	cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}