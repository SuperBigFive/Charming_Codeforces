#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s, n = s.size (), s = '#' + s;
	vector <bool> stay (n + 5), used (26);
	vector <vector <int> > pos (26), suf (26, vector <int> (n + 5));
	for (int i = 1; i <= n; ++i) {
		pos[s[i] - 'a'].emplace_back (i);
		suf[s[i] - 'a'][i] = 1;
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < 26; ++j)
		suf[j][i] += suf[j][i + 1];
	}
	for (int k = 0, be = 0; k < 26; ++k) {
		for (int i = 25; i >= 0; --i) {
			if (!pos[i].size () || used[i]) continue;
			auto id = upper_bound (pos[i].begin (), pos[i].end (),
			be) - pos[i].begin ();
			if (id >= pos[i].size ()) continue;
			bool ok = true;
			for (int j = 0; j < 26; ++j) {
				if (!pos[j].size () || used[j]) continue;
				if (!suf[j][pos[i][id]]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				be = pos[i][id];
				stay[pos[i][id]] = true;
				used[i] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i) if (stay[i])
	cout << s[i];
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}