#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int val[maxn];
int trans[10] = {0, 21, 20, 9, 18, 5, 6, 25, 14, 23};

void init () {
	
}

void charming () {
	cin >> n;
	bool flag1 = false, flag2 = false;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		if (!(val[i] % 5)) flag1 = true;
		else flag2 = true;
		val[i] += trans[val[i] % 10];
	}
	if (flag1 && !flag2) {
		for (int i = 2; i <= n; ++i) {
			if (val[i] != val[i - 1]) {
				cout << "No" << endl;
				return;
			}
		}
		cout << "Yes" << endl;
		return;
	}
	if (!flag1 && flag2) {
		for (int i = 2; i <= n; ++i) {
			if (abs (val[i] - val[i - 1]) % 20) {
				cout << "No" << endl;
				return;
			}
		}
		cout << "Yes" << endl;
		return;
	}
	if (flag1 && flag2) {
		cout << "No" << endl;
		return;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}