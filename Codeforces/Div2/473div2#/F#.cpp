#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n);
	vector <vector <pair <int, int> > > query (n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0, l, x; i < q; ++i) {
		cin >> l >> x, --l;
		query[l].emplace_back (make_pair (x, i));
	}
	vector <bool> inSet (1 << 20);
	vector <int> ans (q), set;
	inSet[0] = true, set.emplace_back (0);
	for (int i = 0, cnt = 1, siz; i < n; ++i) {
		if (inSet[a[i]]) cnt = (cnt * 2) % MOD;
		else {
			siz = set.size ();
			for (int j = 0; j < siz; ++j) {
				set.emplace_back (set[j] ^ a[i]);
				inSet[set[j] ^ a[i]] = true;
			}
		}
		for (auto [x, id] : query[i]) {
			if (inSet[x]) ans[id] = cnt;
			else ans[id] = 0;
		}
	}
	for (int i = 0; i < q; ++i) cout << ans[i] << endl;
}

signed main () {
	charming ();
	return 0;
}