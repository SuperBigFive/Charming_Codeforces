#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {

}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1);
	int emx1 = -1, emx2 = -1, omx1 = -1, omx2 = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		if ((a[i] & 1) && omx1 < a[i]) {
			omx1 = a[i];
		}
		if (!(a[i] & 1) && emx1 < a[i]) {
			emx1 = a[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if ((a[i] & 1)  && omx2 < a[i] && a[i] != omx1)
		omx2 = a[i];
		if (!(a[i] & 1) && emx2 < a[i] && a[i] != emx1)
		emx2 = a[i];
	}
	if (emx2 == -1 && omx2 == -1) {
		cout << -1 << endl;
		return;
	}
	if (emx2 == -1) {
		cout << omx1 + omx2 << endl;
		return;
	}
	if (omx2 == -1) {
		cout << emx1 + emx2 << endl;
		return;
	}
	cout << max (emx1 + emx2, omx1 + omx2) << endl;
}

signed main () {
	charming ();
	return 0;
}