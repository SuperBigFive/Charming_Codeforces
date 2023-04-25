#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {}());

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <double> a (n);
	double sum = 0;
	for (auto &it : a) cin >> it, sum += it;
	cout << setprecision (15) << sum * 2 / (n + 1) << " ";
	for (int i = 1; i < n; ++i) cout << sum  / (n + 1) << " ";
}

signed main () {
	charming ();
	return 0;
}