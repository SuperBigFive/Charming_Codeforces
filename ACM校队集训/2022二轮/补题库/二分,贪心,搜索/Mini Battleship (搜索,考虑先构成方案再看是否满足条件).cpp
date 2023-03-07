#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 10;

int n, k, ans;
int siz[maxn];
char mmap[maxn][maxn];
bool vis[maxn][maxn];

void init () {
	
}

bool ok () {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (mmap[i][j] == 'O' && (!vis[i][j])) return false;
		}
	}
	return true;
}

bool check (int x, int y, int opt, int sz) {
	if (opt & 1) {
		if (y + sz - 1 > n) return false;
		for (int i = y; i < y + sz; ++i) {
			if (vis[x][i]) return false;
		}
	}
	else {
		if (x + sz - 1 > n) return false;
		for (int i = x; i < x + sz; ++i) {
			if (vis[i][y]) return false;
		}
	}
	return true;
}

void add_ship (int x, int y, int opt, int sz) {
	if (opt & 1) {
		if (opt == 1) {
			for (int i = y; i < y + sz; ++i) {
				vis[x][i] = true;
			}
		}
		else {
			for (int i = y; i < y + sz; ++i) {
				vis[x][i] = false;
			}
		}
	}
	else {
		if (opt == 2) {
			for (int i = x; i < x + sz; ++i) {
				vis[i][y] = true;
			}
		}
		else {
			for (int i = x; i < x + sz; ++i) {
				vis[i][y] = false;
			}
		}
	}
}

void dfs (int now) {
	if (now > k) {
		if (ok ()){
			++ans;
			/*for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (vis[i][j]) cout << 'O';
					else cout << 'X';
				}
				cout << endl;
			}
			cout << endl;*/
		}
		return;
	}
	int opt = siz[now] == 1 ? 1 : 2;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (vis[i][j]) continue;
			for (int p = 1; p <= opt; ++p) {
				if (check (i, j, p, siz[now])) {
					add_ship (i, j, p, siz[now]);
					dfs (now + 1);
					add_ship (i, j, p + 2, siz[now]);
				}
			}
		}
	}
}

void charming () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> mmap[i] + 1;
		for (int j = 1; j <= n; ++j)
		if (mmap[i][j] == 'X') vis[i][j] = true;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> siz[i];
	}
	sort (siz + 1, siz + 1 + k);
	dfs (1);
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}