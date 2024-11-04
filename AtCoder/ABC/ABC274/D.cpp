#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, x, y;
vector <int> a, move_x, move_y;
set <int> reach_x, reach_y;

void init () {}

bool check_x () {
	for (auto it1 : move_x) {
		set <int> nxt;
		for (auto it : reach_x) {
			nxt.insert (it + it1);
			nxt.insert (it - it1);
		}
		reach_x = nxt;
	}
	return reach_x.count (x);
}

bool check_y () {
	for (auto it1 : move_y) {
		set <int> nxt;
		for (auto it : reach_y) {
			nxt.insert (it + it1);
			nxt.insert (it - it1);
		}
		reach_y = nxt;
	}
	return reach_y.count (y);
}

void charming () {
	cin >> n >> x >> y;
	a.resize (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if ((i & 1) && i > 1) move_x.emplace_back (a[i]);
		else if (!(i & 1)) move_y.emplace_back (a[i]);
	}
	reach_x.insert (a[1]);
	reach_y.insert (0);
	if (!check_x ()) {
		cout << "No" << endl;
		return;
	}
	if (!check_y ()) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
}

signed main () {
	charming ();
	return 0;
}