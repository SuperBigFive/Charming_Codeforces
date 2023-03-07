#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n, k;
int a[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i]) ++cnt;
	}
	int res = 0;
	for (int i = n; n - i < cnt; --i) {
		if (!a[i]) ++res;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}