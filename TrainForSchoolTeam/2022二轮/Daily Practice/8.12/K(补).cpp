#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int n, m;
int dx[4] = {0, -1, 0, 1}, dy[4]= {1, 0, -1, 0};
int mp[50][50];
char dir[4] = {'R', 'U', 'L', 'D'};
bool vis[50][50];
vector <char> ans;

void init () {
	
}

void dfs (int now_x, int now_y) {
	vis[now_x][now_y] = true;
	for (int i = 0; i < 4; ++i) {
		int nxt_x = now_x + dx[i];
		int nxt_y = now_y + dy[i];
		if (nxt_x > 0 && nxt_x <= n && nxt_y > 0 && nxt_y <= m && mp[nxt_x][nxt_y] && !vis[nxt_x][nxt_y]) {
			ans.emplace_back (dir[i]);
			dfs (nxt_x, nxt_y);
			ans.emplace_back (dir[(i + 2) % 4]);
		}
	}
}

void charming () {
	cin >> n >> m;
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			if (ch == '1') mp[i][j] = 1;
			else mp[i][j] = 0;
		}
	}
	pii beg;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j]) {
				beg = make_pair (i, j);
				memset (vis, 0, sizeof vis);
				dfs (beg.fi, beg.se);
			}
		}
	}
	int cnt = 0;
	for (auto it : ans) {
		cout << it;
		++cnt;
		if (cnt >= 50000) break;
	}
}

signed main () {
	charming ();
	return 0;
}