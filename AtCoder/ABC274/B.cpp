#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e3 + 5;

int h, w;
char mp[maxn][maxn];

void init () {}

void charming () {
	cin >> h >> w;
	char ch;
	for (int i = 1; i <= h; ++i)
	for (int j = 1; j <= w; ++j)
	cin >> ch, mp[i][j] = ch;
	for (int i = 1; i <= w; ++i) {
		int res = 0;
		for (int j = 1; j <= h; ++j) {
			if (mp[j][i] == '#') ++res;
		}
		cout << res << " ";
	}
}

signed main () {
	charming ();
	return 0;
}