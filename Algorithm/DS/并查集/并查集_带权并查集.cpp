#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e6 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> stk (N), val (N), siz (N, 1), pre (N), last (N);
	for (int i = 1; i <= n; ++i) pre[i] = last[i] = i;	

	auto find = [&] (auto &&me, int x) -> int {
		if (x == pre[x]) return x;
		int p = pre[x];
		pre[x] = me (me, pre[x]);
		val[x] += val[p];
		return pre[x];
	};
	
	auto joint = [&] (int x, int y) -> void {
		int fx = find (find, x), fy = find (find, y);
		if (fx == fy) return;
		pre[fx] = fy;
		val[fx] = siz[fy];
		siz[fy] += siz[fx];
		last[fy] = last[fx];
	};
	
	for (int i = 1, opt, k, p, t, x, cnt = 0; i <= m; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> k;
			stk[i] = k;
			++cnt;
		}
		else if (opt == 2) {
			cin >> p >> t;
			joint (stk[t], last[p]);
		}
		else if (opt == 3) cout << cnt << endl;
		else {
			cin >> x;
			cout << siz[find (find, x)] - val[x] << endl;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}