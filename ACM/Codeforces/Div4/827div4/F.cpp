#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, q;
int cnts[30], cntt[30];

void init () {
	fill (cnts, cnts + 30, 0);
	fill (cntt, cntt + 30, 0);
	cnts[0] = cntt[0] = 1;
}

string check () {
	for (int i = 1; i < 30; ++i) {
		if (cntt[i] > 0) return (string) "YES";
	}
	bool ok = cnts[0] < cntt[0];
	for (int i = 1; i < 30; ++i) {
		if (cnts[i] > 0) ok = false;
	}
	if (ok) return (string) "YES";
	return (string) "NO";
}

void charming () {
	init ();
	cin >> q;
	int opt, k, num;
	string x;
	int sign[3] = {0, 1, -1};
	for (int i = 1; i <= q; ++i) {
		cin >> opt >> k >> x;
		for (auto it : x) {
			num = it - 'a';
			if (opt == 1) cnts[num] += k;
			else cntt[num] += k;
		}
		cout << check () << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}