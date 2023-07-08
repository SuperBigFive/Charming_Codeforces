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
	string s, tmp;
	map <string, pair <int, int> > str2, str3;
	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		if (s.size () == 1) ok = true;
		else if (s.size () == 2) {
			if (s[0] == s[1]) ok = true;
			if (!str2.count (s)) str2[s] = make_pair (i, i);
			else str2[s].second = i;
		}
		else if (s.size () == 3) {
			if (s[0] == s[2]) ok = true;
			if (!str3.count (s)) str3[s] = make_pair (i, i);
			else str3[s].second = i;
		}
	}
	if (ok) {
		cout << "YES" << endl;
		return;
	}
	for (auto &it : str2) {
		tmp = it.first;
		reverse (tmp.begin (), tmp.end ());
		if (str2.count (tmp)) {
			cout << "YES" << endl;
			return;
		}
		string tmp2;
		for (int i = 0; i < 26; ++i) {
			tmp2.clear ();
			tmp2.push_back ('a' + i);
			tmp2 += tmp;
			if (str3.count (tmp2) && 
			str3[tmp2].second > it.second.first) {
				cout << "YES" << endl;
				return;
			}
		}
		for (int i = 0; i < 26; ++i) {
			tmp2.clear ();
			tmp2 += tmp;
			tmp2.push_back ('a' + i);
			if (str3.count (tmp2) &&
			str3[tmp2].first < it.second.second) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	for (auto &it : str3) {
		tmp = it.first;
		reverse (tmp.begin (), tmp.end ());
		if (str3.count (tmp)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}