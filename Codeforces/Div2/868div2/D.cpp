#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> x (k + 5), c (k + 5);
	vector <pair <int, int> > cons;
	string s;
	for (int i = 1; i <= k; ++i) cin >> x[i];
	for (int i = 1; i <= k; ++i) cin >> c[i];
	s += "abc";
	int num = 3, siz = 3, nxt = 0;
	for (int i = 1; i <= k; ++i) {
		cons.emplace_back (make_pair (x[i], c[i]));
	}
	for (int i = 0; i < k; ++i) {
		while (siz < cons[i].first) {
			++siz;
			if (num < cons[i].second) s += ('d' + i), ++num;
			else if (nxt == 0) s += 'a', nxt = 1;
			else if (nxt == 1) s += 'b', nxt = 2;
			else s += 'c', nxt = 0;
		}
		if (num < cons[i].second) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	while (siz < n) s += 'a', ++siz;
	cout << s << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}