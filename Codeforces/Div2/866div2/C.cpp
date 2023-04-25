#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n), b;
	for (auto &it : a) cin >> it;
	b = a, sort (b.begin (), b.end ());
	b.resize (unique (b.begin (), b.end ()) - b.begin ());
	int mex = 0, flag = false;
	for (int i = 0; i < b.size (); ++i) {
		if (b[i] == i) ++mex;
		else if (b[i] == i + 1) {flag = true; break;}
		else {flag = false; break;}
	}
	if (!flag) {
		if (mex < n) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		pair <int, int> pos = make_pair (-1, -1);
		for (int i = 0; i < n; ++i) if (a[i] == mex + 1) {
			if (pos.first == -1) pos.first = i;
			pos.second = i;
		}
		for (int i = pos.first; i <= pos.second; ++i)
		a[i] = mex;
		b = a, sort (b.begin (), b.end ());
		b.resize (unique (b.begin (), b.end ()) - b.begin ());
		int nmex = 0;
		for (int i = 0; i < b.size (); ++i) {
			if (b[i] == i) ++nmex;
			else break;
		}
		if (nmex == mex + 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}