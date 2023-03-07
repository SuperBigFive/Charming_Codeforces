#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e3 + 5;
const int maxm = 3e6 + 5;

int t, n, m;
int mp[maxn][maxn], color[maxn][maxn];
bool vis[maxn][maxn];

void init () {}

void charming () {
	init ();
	scanf ("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	scanf ("%lld", &mp[i][j]);
	queue <pair <int, int> > q;;
	vector <pair <int, pair <int, int> > > ans;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i < n && j < m) {
				int cnt = 0;
				for (int k = 0; k <= 1; ++k)
				for (int p = 0; p <= 1; ++p) {
					if (mp[i + k][j + p] == mp[i][j])
					++cnt;
				}
				if (cnt >= 4) {
					ans.emplace_back (make_pair (mp[i][j], make_pair (i, j)));
					for (int k = 0; k <= 1; ++k) 
					for (int p = 0; p <= 1; ++p) {
						q.push (make_pair (i + k, j + p));
						vis[i + k][j + p] = true;
					}
				}
			}
		}
	}
	while (!q.empty ()) {
		auto [x, y] = q.front ();
		q.pop ();
		for (int i = -1; i <= 0; ++i)
		for (int j = -1; j <= 0; ++j) {
			if (x + i >= 1 && x + i < n 
			&& y + j >= 1 && y + j < m) {
				int cx = x + i, cy = y + j, cnt = 0;
				set <int> s;
				for (int k = 0; k <= 1; ++k)
				for (int p = 0; p <= 1; ++p) {
					if (vis[cx + k][cy + p]) ++cnt;
					else s.insert (mp[cx + k][cy + p]);
				}
				if (cnt == 4 || s.size () != 1) continue;
				ans.emplace_back (make_pair (*(s.begin ()), make_pair (cx, cy)));
				for (int k = 0; k <= 1; ++k)
				for (int p = 0; p <= 1; ++p) {
					if (!vis[cx + k][cy + p]) {
						vis[cx + k][cy + p] = true;
						q.push (make_pair (cx + k, cy + p));
					}
				}
			}
		}
	}
	reverse (ans.begin (), ans.end ());
	for (auto [co, pos] : ans) {
		auto [x, y] = pos;
		for (int p = 0; p <= 1; ++p)
		for (int q = 0; q <= 1; ++q)
		color[x + p][y + q] = co;
	}
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	if (color[i][j] != mp[i][j]) {
		printf ("-1\n");
		return;
	}
	printf ("%d\n", ans.size ());
	for (auto [co, pos] : ans) {
		auto [x, y] = pos;
		printf ("%lld %lld %lld\n", x, y, co);
	}
}

signed main () {
	charming ();
	return 0;
}