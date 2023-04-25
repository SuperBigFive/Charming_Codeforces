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
	vector <int> pos, neg, zero;
	for (int i = 1, val; i <= n; ++i) {
		cin >> val;
		if (val > 0) pos.emplace_back (val);
		else if (val < 0) neg.emplace_back (val);
		else zero.emplace_back (0);
	}
	if (zero.size () >= n) {cout << "No" << endl; return;}
	sort (pos.begin (), pos.end (), [] (int &x, int &y) {
	return x < y;});
	sort (neg.begin (), neg.end (), [] (int &x, int &y) {
	return x > y;});
	cout << "Yes" << endl;
	int p1 = 0, p2 = 0, sum = 0;
	vector <int> ans (zero.size (), 0);
	while (p1 < pos.size () || p2 < neg.size ()) {
		if (p2 >= neg.size () || sum <= 0) ans.emplace_back (pos[p1++]);
		else ans.emplace_back (neg[p2++]);
		sum += ans.back ();
	}
	for (auto it : ans) cout << it << " ";
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}