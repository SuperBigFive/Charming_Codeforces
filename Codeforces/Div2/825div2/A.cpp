#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn], b[maxn];

void init () {

}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	int cnta = 0, cntb = 0, cntc = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 1) ++cnta;
		if (b[i] == 1) ++cntb;
		if (a[i] != b[i]) ++cntc;
	}
	cout << min (cntc, abs (cnta - cntb) + 1) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}