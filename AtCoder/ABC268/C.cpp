#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
int p[maxn], ans[maxn];

void init () {}

void charming () {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		++ans[((p[i] - i + 1) % n + n) % n];
		++ans[((p[i] - i) % n + n) % n];
		++ans[((p[i] - i + 2) % n + n) % n];
	}
	int res = 0;
	for (int i = 0; i < n; ++i) res = max (res, ans[i]);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}