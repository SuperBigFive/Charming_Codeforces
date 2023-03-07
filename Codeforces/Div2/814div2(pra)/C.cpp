#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e3 + 5;

int t, n, m, cnt;
int dx[4] = {0, 0, 1, 1}, dy[4] = {0, 1, 0, 1};
int mp[maxn][maxn];

void init () {
	cnt = 0;
	for (int i = 0; i <= n + 1; ++i) mp[i][0] = mp[i][m + 1] = 1;
	for (int i = 0; i <= m + 1; ++i) mp[0][i] = mp[n + 1][i] = 1;
}

void charming () {
	cin >> n >> m;
	init ();
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			if (ch == '1') ++cnt;
			mp[i][j] = ch - '0';
		}
	}
	bool ok1 = false, ok2 = false;
	int tmp;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			tmp = 0;
			for (int k = 0; k < 4; ++k) {
				if (!mp[i + dx[k]][j + dy[k]])
				++tmp;
				if (tmp > 0) ok1 = true;
				if (tmp > 1) 
				ok2 = true;
			}
		}
	}
	if (!ok1) cnt -= 2;
	else if (!ok2) cnt -= 1;
	cout << cnt << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}