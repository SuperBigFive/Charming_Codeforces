#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
const int M = 1e5;

int t, n, m;

void init () {

}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> ans (m + 1, INT_MAX), vis (m + 1);
	vector <array <int, 3> > opt (n + 1);
	vis[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> opt[i][0] >> opt[i][1] >> opt[i][2];	
		vector <int> nvis = vis;
		for (int j = 0; j <= m; ++j) {
			if (vis[j]) {
				int cur_k = j;
				for (int k = 1; k <= opt[i][2]; ++k) {
					if (opt[i][0] == 1) cur_k = cur_k + ceil ((double) opt[i][1] / M);
					else cur_k = ceil ((double)cur_k * opt[i][1] / M);
					if (cur_k > m) break;
					if (vis[cur_k]) break;
					ans[cur_k] = i;
					nvis[cur_k] = true;
				}
			}
		}
		vis = nvis;
	}
	for (int i = 1; i <= m; ++i) {
		if (ans[i] >= INT_MAX) cout << -1 << " ";
		else cout << ans[i] << " ";
	}
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}