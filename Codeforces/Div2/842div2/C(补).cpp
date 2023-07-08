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
	vector <int> p (n), q (n);
	vector <pair <int, int> > a (n);
	map <int, int> cnt;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		++cnt[a[i].first];
		a[i].second = i;
	}
	sort (a.begin (), a.end ());
	int p1 = 1, p2 = 1;
	for (int i = 0; i < n; ++i) {
		if (cnt[a[i].first] > 2) {
			cout << "NO" << endl;
			return;
		}
		if (i == 0 || a[i].first != a[i - 1].first) {
			p[a[i].second] = a[i].first;
			while (p2 <= a[i].first && cnt[p2] >= 2) ++p2;
			if (p2 > a[i].first) {
				cout << "NO" << endl;
				return;
			}
			q[a[i].second] = p2++;
		}
		else {
			while (p1 <= a[i].first && cnt[p1]) ++p1;
			if (p1 > a[i].first) {
				cout << "NO" << endl;
				return;
			}
			p[a[i].second] = p1++;
			q[a[i].second] = a[i].first;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << p[i] << " \n"[i == n - 1];
	}
	for (int i = 0; i < n; ++i) {
		cout << q[i] << " \n"[i == n - 1];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
	