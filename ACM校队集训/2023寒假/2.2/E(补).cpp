#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	//'R' = 1, 'S' = 2, 'P' = 3;
	char ch[4] = {'#', 'R', 'S', 'P'};
	int defeat[4], pre[4];
	map <char, int> dict;
	dict['R'] = 1, dict['S'] = 2, dict['P'] = 3;
	defeat[1] = 2, defeat[2] = 3, defeat[3] = 1;
	pre[1] = 3, pre[2] = 1, pre[3] = 2;
	string s;
	cin >> s, s = '#' + s;
	vector <pair <int, int> > a;
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while (j + 1 <= n && s[j + 1] == s[i]) ++j;
		a.emplace_back (make_pair (dict[s[i]], j - i + 1));
	}
	vector <int> ok (n), nxt (n);
	for (int i = 0; i < a.size () - 1; ++i) {
		if (defeat[a[i].first] != a[i + 1].first) continue;
		ok[i] = true, ++i;
	}
	vector <pair <int, int> > seq;
	for (int i = 0, j; i < a.size () - 1; i = j + 1) {
		j = i;
		if (ok[i]) {
			while (j + 2 < a.size () - 1 && ok[j + 2] &&
			a[j + 2].first == a[i].first) j += 2;		
			seq.emplace_back (i, j + 1);
		}
	}
	for (auto [l, r] : seq) {
		int remain = m;
		for (int i = l; i < r; i += 2) {
			if (a[i].second <= remain) remain -= a[i].second, a[i].second = 0;
			else a[i].second -= remain, remain = 0;
		}
		nxt[r] += (m - remain);
	}
	for (int i = 0; i < a.size (); ++i) {
		while (a[i].second--) cout << ch[a[i].first];
		while (nxt[i]--) cout << ch[pre[a[i].first]];
	}
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}