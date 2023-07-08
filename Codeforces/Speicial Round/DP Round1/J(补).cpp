#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1);
	vector <vector <int> > pos (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back (i);
	}
	for (int i = 0; i <= n; ++i) {
		pos[i].emplace_back (n + 1);
	}
	vector <int> a0, a1;
	a0.emplace_back (0);
	a1.emplace_back (0);
	for (int i = 1; i <= n; ++i) {
		if (a0.back () == a1.back ()) {
			a0.emplace_back (a[i]);
		}
		else {
			if (a0.back () == a[i])
			a1.emplace_back (a[i]);
			else if (a1.back () == a[i])
			a0.emplace_back (a[i]);
			else {
				int nxt0 = upper_bound (pos[a0.back ()].begin (),
				pos[a0.back ()].end (), i) - pos[a0.back ()].begin ();
				int nxt1 = upper_bound (pos[a1.back ()].begin (),
				pos[a1.back ()].end (), i) - pos[a1.back ()].begin ();
				nxt0 = pos[a0.back ()][nxt0];
				nxt1 = pos[a1.back ()][nxt1];
				if (nxt0 <= nxt1) a0.emplace_back (a[i]);
				else a1.emplace_back (a[i]);
			}
		}
	}
	int res = 0, p0 = 1, p1 = 1;
	while (p0 < a0.size ()) {
		int p = p0;
		while (p < a0.size () && a0[p0] == a0[p]) ++p;
		++res, p0 = p;
	}
	while (p1 < a1.size ()) {
		int p = p1;
		while (p < a1.size () && a1[p1] == a1[p]) ++p;
		++res, p1 = p;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}