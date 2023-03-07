#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int q;
set <int> s;
map <int, int> ans;
map <int, set <int> > vis, del;

void init () {}

void charming () {
	init ();
	cin >> q;
	char opt;
	for (int i = 0, x; i < q; ++i) {
		cin >> opt >> x;
		if (opt == '+') {
			s.insert (x);
			for (auto it : vis[x]) {
				del[it].erase (x);
			}
		}
		else if (opt == '-') {
			s.erase (x);
			for (auto it: vis[x]) del[it].insert (x);
		}
		else {
			int res = (ans.count (x) ? ans[x] : x);
			while (s.count (res)) {
				vis[res].insert (x);
				res += x;
			}
			ans[x] = res;
			vis[res].insert (x);
			if (!del[x].empty ()) res = min (res, *del[x].begin ());
			cout << res << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}