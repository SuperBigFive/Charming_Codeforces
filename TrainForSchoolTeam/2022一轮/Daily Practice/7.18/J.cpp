#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
using namespace std;
const int maxn = 4e5 + 5;

int t, n;
int type[maxn], res[maxn], tmp[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		type[i] = tmp[i] = res[i] = 0;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> type[i];
		tmp[i] = type[i];
	}

	sort (tmp + 1, tmp + 1 + n);
	if (tmp[1] == tmp[n]) {
		cout << 1 << endl;
		for (int i = 1; i <= n; ++i) {
			cout << 1 << ' ';
		}
		cout << endl;
		return;
	}

	bool ok = false;
	int spe = -1;
	for (int i = n; i > 1; --i) {
		if (type[i] == type[i - 1]) {
			spe = i;
			ok = true;
			break;
		}
	}
	ll ans = 0;
	res[1] = 1;
	if (!ok) {
		for (int i = 2; i < n; ++i) {
			if (type[i] != type[i - 1]) {
				if (res[i - 1] == 1) res[i] = 2;
				else res[i] = 1;
			}
			else res[i] = res[i - 1];
		}
		if (res[n - 1] != res[1]) {
			if (type[n] == type[1]) {
				res[n] = res[1];
				ans = 2;
			}
			else {
				res[n] = 3;
				ans = 3;
			}	
		}
		else {
			if (res[1] == 1) res[n] = 2;
			else res[n] = 1;
			ans = 2;
		}
	}
	else {
		ans = 2;
		res[n] = 2;
		if ((n - spe) & 1) {
			res[spe] = 1;
		}
		else res[spe] = 2;
		for (int i = 2; i < n; ++i) {
			if (res[i]) continue;
			if (type[i] != type[i - 1]) {
				if (res[i - 1] == 1) res[i] = 2;
				else res[i] = 1;
			}
			else res[i] = res[i - 1];
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--)	charming ();
	return 0;
}