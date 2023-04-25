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
	vector <int> a (n + 5), pos (n + 5, -1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int cnt = 0, r = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i - 1]) ++cnt;
		else if (pos[a[i]] != -1 && r < pos[a[i]] + 1)
		r = i - 1, ++cnt;
		pos[a[i]] = i;
	}
	cout << n - cnt << endl;
}

signed main () {
	charming ();
	return 0;
}