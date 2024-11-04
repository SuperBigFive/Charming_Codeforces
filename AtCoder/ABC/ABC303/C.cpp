#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, h, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init () {}

void charming () {
	cin >> n >> m >> h >> k;
	string s;
	cin >> s;
	map <char, int> ch2num;
	ch2num['R'] = 0, ch2num['L'] = 1;
	ch2num['U'] = 2, ch2num['D'] = 3;
	int x = 0, y = 0, nx, ny;
	set <pair <int, int> > item;
	for (int i = 0, ix, iy; i < m; ++i) {
		cin >> ix >> iy;
		item.insert (make_pair (ix, iy));
	}
	for (auto &ch : s) {
		nx = x + dx[ch2num[ch]];
		ny = y + dy[ch2num[ch]];
		if (h <= 0) {
			cout << "No" << endl;
			return;
		}
		else if (item.count (make_pair (nx, ny))) {
			if (h <= k) h = k, item.erase (make_pair (nx, ny));
			else --h;
		} 
		else --h;
		x = nx, y = ny;
	}
	cout << "Yes" << endl;
}

signed main () {
	//freopen ("data.in", "r", stdin);
	charming ();
	return 0;
}
