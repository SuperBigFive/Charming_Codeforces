#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
mt19937 rnd (random_device {} ());

int n, k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <vector <int> > a (n + 5, vector <int> (n + 5));
	vector <vector <vector <int> > > b (n + 5, vector <vector <int> > (n + 5)); 
	vector <vector <vector <int> > > c (n + 5, vector <vector <int> > (n + 5)); 
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	cin >> a[i][j];
	if (n == 1) return void (cout << (a[1][1] == k) << endl);
	auto dfs = [&] (auto && me, int cx, int cy, int x, int y, int st, 
	int mx, int mss, int tmp_mss, int sum) -> void {
		if (mss > k) return;
		if ((x == 1 && y == 1) || (x == n && y == n)) {
			if (mss == k) b[cx][cy].emplace_back (mx);
			else c[cx][cy].emplace_back (mx);
			return;
		}
		for (int i = st, nx, ny; i < st + 2; ++i) {
			nx = x + dx[i], ny = y + dy[i];
			if (nx > n || nx < 1 || ny > n || ny < 1) continue;
			me (me, cx, cy, nx, ny, st, max (mx, sum + a[nx][ny]), max ({mss, a[nx][ny], 
			tmp_mss + a[nx][ny]}), max (a[nx][ny], tmp_mss + a[nx][ny]), sum + a[nx][ny]);
		}
	};
	for (int i = 1; i <= n; ++i)
	dfs (dfs, i, n - i + 1, i, n - i + 1, 2, a[i][n - i + 1], 
	a[i][n - i + 1], a[i][n - i + 1], a[i][n - i + 1]);
	for (int i = 2; i <= n; ++i)
	dfs (dfs, i, n - i + 2, i, n - i + 2, 0, a[i][n - i + 2], 
	a[i][n - i + 2], a[i][n - i + 2], a[i][n - i + 2]);
	for (int i = 1; i <= n; ++i) {
		sort (b[i][n - i + 1].begin (), b[i][n - i + 1].end ());
		sort (c[i][n - i + 1].begin (), c[i][n - i + 1].end ());
		sort (b[i][n - i + 2].begin (), b[i][n - i + 2].end ());
		sort (c[i][n - i + 2].begin (), c[i][n - i + 2].end ());
	}
	auto cal = [&] (int x1, int y1, int x2, int y2) -> ll {
		ll res = 0, p = (int) b[x2][y2].size () - 1;
		for (int i = 0; i < b[x1][y1].size () && p >= 0; ++i) {
			while (p >= 0 && b[x1][y1][i] + b[x2][y2][p] > k) --p;
			if (p < 0) break;
			res += p + 1;
		}
		p = (int) c[x2][y2].size () - 1;
		for (int i = 0; i < b[x1][y1].size () && p >= 0; ++i) {
			while (p >= 0 && b[x1][y1][i] + c[x2][y2][p] > k) --p;
			if (p < 0) break;
			res += p + 1;
		}
		p = (int) b[x2][y2].size () - 1;
		for (int i = 0; i < c[x1][y1].size () && p >= 0; ++i) {
			while (p >= 0 && c[x1][y1][i] + b[x2][y2][p] > k) --p;
			if (p < 0) break;
			res += p + 1;
		}
		p = (int) c[x2][y2].size () - 1;
		for (int i = 0, ni, np; i < c[x1][y1].size () && p >= 0; i = ni + 1) {
			while (p >= 0 && c[x1][y1][i] + c[x2][y2][p] > k) --p;
			if (p < 0) break;
			ni = i, np = p;
			if (c[x1][y1][i] + c[x2][y2][p] < k) continue;
			while (ni + 1 < c[x1][y1].size () && c[x1][y1][ni + 1] == c[x1][y1][i]) ++ni;
			while (np - 1 >= 0 && c[x2][y2][np - 1] == c[x2][y2][p]) --np;
			res += (ni - i + 1) * (p - np + 1);
			p = np;
		}
		return res;
	};
	ll res = 0;
	for (int i = 1, x, y; i <= n; ++i) {
		x = i, y = n - i + 1;
		for (int j = 0, nx, ny; j < 2; ++j) {
			nx = x + dx[j], ny = y + dy[j];
			if (nx > n || nx < 1 || ny > n || ny < 1) continue;
			res += cal (x, y, nx, ny);
		}
	}
	cout << res << endl;
}

//35345263800

void test () {
	cin >> n >> k;
	vector <vector <int> > a (n + 5, vector <int> (n + 5));
	vector <vector <vector <int> > > b (n + 5, vector <vector <int> > (n + 5)); 
	vector <vector <vector <int> > > c (n + 5, vector <vector <int> > (n + 5)); 
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	cin >> a[i][j];
	cout << endl;
	vector <int> stk;
	auto dfs = [&] (auto && me, int x, int y) -> void {
		if (x == n && y == n) {
			int sum = 0, res = 0;
			for (auto it : stk) sum = max (sum + it, it), res = max (res, sum);
			if (res == k) {
				for (auto it : stk) cout << it << " ";
				cout << endl;
			}
			return;
		}
		for (int i = 0, nx, ny; i < 2; ++i) {
			nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			stk.emplace_back (a[nx][ny]);
			me (me, nx, ny);
			stk.pop_back ();
		}
	};
	stk.emplace_back (a[1][1]);
	dfs (dfs, 1, 1);
}

signed main () {
	/*cout << 20 << " " << 0 << endl;
	for (int i = 1; i <= 20; ++i)
	for (int j = 1; j <= 20; ++j)
	cout << 0 << " \n"[j == 20];*/
	//test ();
	charming ();
	return 0;
}