#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	string s;
	vector <vector <int> > mp (n + 1);
	for (int i = 1; i <= n; ++i) {
		mp[i].resize (m + 1);
		cin >> s, s = '#' + s;
		for (int j = 1; j <= m; ++j)
		mp[i][j] = s[j] - '0';
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!mp[i][j]) continue;
			queue <pair <int, int> > q;
			vector <pair <int, int> > vec;
			q.push (make_pair (i, j));
			vec.emplace_back (make_pair (i, j));
			mp[i][j] = 0;
			pair <int, int> cur, nxt;
			while (!q.empty ()) {
				cur = q.front ();
				q.pop ();
				for (int k = 0; k < 4; ++k) {
					nxt = make_pair (cur.first + dx[k], cur.second + dy[k]);
					if (nxt.first >= 1 && nxt.first <= n && nxt.second >= 1 
					&& nxt.second <= m && mp[nxt.first][nxt.second]) {
						mp[nxt.first][nxt.second] = 0;
						q.push (make_pair (nxt.first, nxt.second));
						vec.emplace_back (make_pair (nxt.first, nxt.second));
					}
				}
			}
			sort (vec.begin (), vec.end (), [] (pair <int, int> &a, 
			pair <int, int> &b) {
				if (a.first != b.first) return a.first < b.first;
				return a.second < b.second;
			});
			auto [x1, y1] = vec[0];
			auto [x2, y2] = vec.back ();
			sort (vec.begin (), vec.end (), [] (pair <int, int> &a, 
			pair <int, int> &b) {
				if (a.second != b.second) return a.second < b.second;
				return a.first < b.first;
			});
			auto [x3, y3] = vec[0];
			auto [x4, y4] = vec.back ();
			if (x1 != x3 || x2 != x4 || y1 != y3 || y2 != y4) {
				cout << "NO" << endl;
				return;
			}
			if ((x2 - x1 + 1) * (y2 - y1 + 1) != vec.size ()) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}