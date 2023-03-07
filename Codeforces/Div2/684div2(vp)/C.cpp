#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

void init () {}

void solve (vector <vector <int> > &mp, int x, int y, 
int cnt, vector <array <int, 6> > &ans) {
	array <int, 6> nans;
	if (cnt == 0) return;
	else if (cnt == 1) {
		for (int i = 0, nx, ny, cnt = 0, ok = 0; i < 4; ++i) {
			nx = x + (dx[i] ^ 1), ny = y + (dy[i] ^ 1);
			if (mp[nx][ny] && !ok) {ok = true; continue;};
			nx = x + dx[i], ny = y + dy[i];
			nans[cnt++] = nx, nans[cnt++] = ny;
			mp[nx][ny] ^= 1;
		}
		ans.emplace_back (nans);
		solve (mp, x, y, 2, ans);
	}
	else if (cnt == 2) {
		for (int i = 0, nx, ny, cnt = 0, ok = 0; i < 4; ++i) {
			nx = x + dx[i], ny = y + dy[i];
			if (mp[nx][ny] && !ok) {ok = true; continue;}
			nans[cnt++] = nx, nans[cnt++] = ny;
			mp[nx][ny] ^= 1;
		}
		ans.emplace_back (nans);
		solve (mp, x, y, 3, ans);
	}
	else if (cnt == 3) {
		for (int i = 0, nx, ny, cnt = 0; i < 4; ++i) {
			nx = x + dx[i], ny = y + dy[i];
			if (!mp[nx][ny]) continue;
			nans[cnt++] = nx, nans[cnt++] = ny;
			mp[nx][ny] ^= 1;
		}
		ans.emplace_back (nans);
	}
	else {
		for (int i = 1, nx, ny, cnt = 0; i < 4; ++i) {
			nx = x + dx[i], ny = y + dy[i];
			nans[cnt++] = nx, nans[cnt++] = ny;
			mp[nx][ny] ^= 1;
		}
		ans.emplace_back (nans);
		solve (mp, x, y, 1, ans);
	}
}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > mp (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s, s = '#' + s;
		for (int j = 1; j <= m; ++j)
		mp[i][j] = (s[j] - '0');
	}
	vector <array <int, 6> > ans;
	if (mp[n][m] && (n >= 3 || m >= 3)) {
		array <int, 6> nans;
		for (int i = 0, nx, ny, cnt = 0; i < 4; ++i) {
			nx = n - 1 + dx[i], ny = m - 1 + dy[i];
			if (nx == n - 1 && ny == m - 1) continue;
			nans[cnt++] = nx, nans[cnt++] = ny;
			mp[nx][ny] ^= 1;
		}
		ans.emplace_back (nans);
	}
	if (m & 1) {
		array <int, 6> nans;
		for (int i = 1, x, y; i < n; ++i) if (mp[i][m]) {
			x = max (1ll, min (n - 1, i - 1)), y = m - 1;
			for (int j = 0, nx, ny, cnt = 0; j < 4; ++j) {
				nx = x + dx[j], ny = y + dy[j];
				if ((nx == i + 1 || nx == i - 1) && ny == m) continue;
				nans[cnt++] = nx, nans[cnt++] = ny;
				mp[nx][ny] ^= 1;
			}
			ans.emplace_back (nans);
		}
	}
	if (n & 1) {
		array <int, 6> nans;
		for (int i = 1, x, y; i < m; ++i) if (mp[n][i]) {
			x = n - 1, y = max (1ll, min (m - 1, i - 1));
			for (int j = 0, nx, ny, cnt = 0; j < 4; ++j) {
				nx = x + dx[j], ny = y + dy[j];
				if (nx == n && (ny == i + 1 || ny == i - 1)) continue;
				nans[cnt++] = nx, nans[cnt++] = ny;
				mp[nx][ny] ^= 1;
			}
			ans.emplace_back (nans);
		}
	}
	for (int i = 1; i < n; i += 2) {
		for (int j = 1, cnt; j < m; j += 2) {
			cnt = 0;
			for (int k = 0; k < 4; ++k)
			cnt += (mp[i + dx[k]][j + dy[k]]);
			solve (mp, i, j, cnt, ans);
		}
	}
	cout << ans.size () << endl;
	for (auto &it : ans)
	for (int i = 0; i < 6; ++i)
	cout << it[i] << " \n"[i == 5];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}