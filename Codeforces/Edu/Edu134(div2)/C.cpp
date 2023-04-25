#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn], b[maxn];

void init () {

}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}

	for (int i = 1, id; i <= n; ++i) {
		id = lower_bound (b + 1, b + 1 + n, a[i]) - b;
		cout << b[id] - a[i] << " \n"[i == n];
	}
	
	for (int i = 1, p = 1; i <= n; i = p + 1, p = i) {
		while (b[p] >= a[p + 1] && p + 1 <= n) ++p;
		for (int j = i; j <= p; ++j) {
			cout << b[p] - a[j] << " \n"[j == n];
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}