#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, x;

void init () {}

void charming () {
	init ();
	cin >> n >> x;
	if (n % x) {
		cout << -1 << endl;
		return;
	}
	vector <int> num (n + 1);
	for (int i = 2; i < n; ++i) num[i] = i;
	num[1] = x, num[x] = n, num[n] = 1;
	int p = x, q;
	while (true) {
		q = p + p;
		while (q < n && (n % num[q])) q += p;
		if (q >= n) break;
		swap (num[p], num[q]);
		p = q;
	}
	for (int i = 1; i <= n; ++i) 
	cout << num[i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
