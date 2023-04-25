#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, k, s;

void init () {}

void charming () {
	init ();
	cin>> n >> k >> s;
	vector <pair <int, int> > stu;
	for (int i = 0, a, b; i < n; ++i) {
		cin >> a >> b;
		if (a >= 175) stu.emplace_back (make_pair (a, b));
	}
	sort (stu.begin (), stu.end ());
	n = stu.size ();
	int ans = 0;
	for (int i = 0, j, pass, nopass; i < stu.size (); i = j + 1) {
		j = i, pass = nopass = 0;
		if (stu[i].second >= s) ++pass;
		else ++nopass;
		while (j + 1 < n && stu[j + 1].first == stu[j].first) {
			if (stu[j + 1].second >= s) ++pass;
			else ++nopass;
			++j;
		}
		ans += pass + min (k, nopass);
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}