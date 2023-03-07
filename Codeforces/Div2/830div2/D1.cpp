#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int q;
map <int, int> ans;
set <int> s;

void init () {}

void charming () {
	init ();
	cin >> q;
	char opt;
	for (int i = 1, x; i <= q; ++i) {
		cin >> opt >> x;
		if (opt == '+') {
			s.insert (x);
		}
		else {
			int res = (ans.count (x) ? ans[x] : x);
			while (s.count (res)) res += x;
			ans[x] = res;
			cout << res << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}