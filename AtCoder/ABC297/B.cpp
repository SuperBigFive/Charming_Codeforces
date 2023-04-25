#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	int pb1 = -1, pb2 = -1, pr1 = -1, pr2 = -1, pk;
	for (int i = 0; i < 8; ++i) {
		if (s[i] == 'B') {
			if (pb1 == -1) pb1 = i;
			else pb2 = i;
		}
		else if (s[i] == 'R') {
			if (pr1 == -1) pr1 = i;
			else pr2 = i;
		}
		else if (s[i] == 'K') pk = i;
	}
	if ((pb1 & 1) != (pb2 & 1) && pr1 < pk && pk < pr2) cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}