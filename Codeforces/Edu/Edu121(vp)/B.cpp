#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	n = s.length ();
	int mx1 = -1, mx2 = -1, id1 = -1, id2 = -1;
	for (int i = 0, sum, old; i < n - 1; ++i) {
		int num1 = s[i] - '0';
		int num2 = s[i + 1] - '0';
		sum = num1 + num2;
		if (sum >= 10) {
			mx2 = sum;
			id2 = i;
		}
		if (sum < 10 && mx1 == -1) {
			mx1 = sum;
			id1 = i;
		}
	}
	if (id2 != -1) {
		id1 = -1;
		s[id2] = (char) ('0' + mx2 / 10);
		s[id2 + 1] = (char) ('0' + mx2 % 10);
	}
	else if (id1 != -1) {
		s[id1 + 1] = (char) ('0' + mx1);
	}
	for (int i = 0; i < n; ++i) {
		if (i == id1) continue;
		cout << s[i];
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}