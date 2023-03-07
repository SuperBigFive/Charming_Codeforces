#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e2 + 5;

int m, n, s, f, r;
int fx[4] = {-1, 0, 1, 0}, fy[4] = {0, 1, 0, -1};
int rx[4] = {0, 1, 0, -1}, ry[4] = {1, 0, -1, 0};
int mp[maxn][maxn];

void init () {}

bool check (int i, int j) {
	if (mp[i][j] != s) return false;
	int cx = i, cy = j;
	for (int i = 0; i < 4; ++i) {
		int nxf = cx + fx[i], nyf = cy + fy[i];
		int nxr = cx + rx[i], nyr = cy + ry[i];
		if (mp[nxf][nyf] == f && mp[nxr][nyr] == r) return true;
	}
	return false;
}

void charming () {
	init ();
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	for (int j = 1; j <= n; ++j)
	cin >> mp[i][j];
	cin >> s >> f >> r;
	vector <pair <int, int> > ans;
	for (int i = 1; i <= m; ++i)
	for (int j = 1; j <= n; ++j)
	if (check (i, j)) ans.emplace_back (make_pair (i - 1, j - 1));
	sort (ans.begin (), ans.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {
		if (x.first != y.first) return x.first < y.first;
		else return x.second < y.second;
	});
	for (auto [x, y] : ans) cout << x << " " << y << endl;
}

signed main () {
	charming ();
	return 0;
}