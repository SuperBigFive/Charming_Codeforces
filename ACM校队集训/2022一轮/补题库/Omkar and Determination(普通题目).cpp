#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int n, m, q;
vector <int> cannot;

void init () {
}

void charming () {
	init ();
	cin >> n >> m;
	char ch;
	vector <int> mmap[n + 1];
	for (int i = 1; i <= n; ++i) {
		mmap[i].pb ('#');
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			mmap[i].pb (ch);
		}
	}
	int tot = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (mmap[i + 1][j] == 'X' && mmap[i][j + 1] == 'X') {
				cannot.pb (j);
			}
		}
	}
	sort (cannot.begin (), cannot.end ());
	cin >> q;
	int x1, x2;
	bool ok;
	for (int i = 1; i <= q; ++i) {
		cin >> x1 >> x2;
		if (!cannot.size ()) {
			cout << "YES" << endl;
			continue;
		}
		int id = lower_bound (cannot.begin (), cannot.end (), x1) - cannot.begin ();
		if (id < cannot.size () && cannot[id] < x2 && cannot[id] >= x1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}