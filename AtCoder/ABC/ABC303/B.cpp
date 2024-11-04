#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
	cin >> n >> m;
	vector <vector <int> > a (n + 5, vector <int> (n + 5));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1, last = 0, cur; j <= n; ++j) {
			cin >> cur;
			a[cur][last] = a[last][cur] = 1;
			last = cur;
		}
	}		
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = i + 1; j <= n; ++j) ans += (a[i][j] ^ 1);
	cout << ans << endl;
}

signed main () {
	//freopen ("data.in", "r", stdin);
	charming ();
	return 0;
}
