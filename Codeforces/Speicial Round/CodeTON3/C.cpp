#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;	
	string s, t;
	cin >> s >> t;
	s = '#' + s + '0', t = '#' + t + '0';
	vector <pair <int, int> > ans;
	int flag = 0;
	if (s != t) {
		for (int i = 1; i <= n; ++i)
		s[i] = (s[i] == '1' ? '0' : '1');
		ans.emplace_back (make_pair (1, n));
		flag = 1;
	}
	if (s != t) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	int cnt = 0, id = -1;
	for (int i = 1; i <= n + 1; ++i) {
		if (s[i] == '1') {
			if (id == -1) id = i;
			++cnt;
		}
		else {
			if (cnt) ans.emplace_back (make_pair (id, i - 1));
			cnt = 0, id = -1;
		}
	}
	if ((ans.size () - flag) & 1) {
		ans.emplace_back (make_pair (1, n));
		ans.emplace_back (make_pair (1, 1));
		ans.emplace_back (make_pair (2, n));
	}
	cout << ans.size () << endl;
	for (auto it : ans) cout << it.first << " " << it.second << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}