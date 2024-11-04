#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

void init () {

}

void charming () {
	init ();
	int a[105];
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	cout << sum << endl;
}

signed main () {
	charming ();
	return 0;
}