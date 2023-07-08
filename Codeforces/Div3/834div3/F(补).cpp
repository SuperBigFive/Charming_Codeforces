#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, p;

void init () {}

void charming () {
	init ();
	scanf ("%d%d", &n, &p);
	vector <int> a (n + 1);
	map <int, bool> vis;
	for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]), vis[a[i]] = true;
	int res = 0, tmp = a.back ();
	bool flag = true;
	for (int i = 0; i <= a[n]; ++i) if (!vis[i]) {
		flag = false;
		break;
	}
	if (flag) {
		int id = -1;
		for (int i = p - 1; i >= a.back (); --i) {
			if (!vis[i]) {
				id = i;
				break;
			}
		}
		if (id != -1) res += id - a.back ();
		cout << res << endl;
		return;
	}
	else {
		res += p - a.back ();
		vis[0] = true;
		++a[n - 1];
		int q = n - 1;
		while (a[q] >= p) {
			a[q - 1] += a[q] / p;
			a[q] %= p;
			vis[a[q]] = true;
			--q;
		}
		vis[a[n - 1]] = true;
		vis[a[q]] = true;
		a[n] = 0;
	}
	int id = -1;
	for (int i = tmp - 1; i >= 0; --i) {
		if (!vis[i]) {
			id = i;
			break;
		}
	}
	if (id != -1) res += id;
	printf ("%d\n", res);
}

signed main () {
	scanf ("%d", &t);
	while (t--) charming ();
	return 0;
}