#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <pair <int, int> > a (n);
	for (int i = 0; i < n; ++i) cin >> a[i].first;
	for (int i = 0; i < n; ++i) cin >> a[i].second;
	vector <int> query, id;
	vector <vector <int> > b (n + 5);
	for (auto [x, y] : a) b[x].emplace_back (y);
	for (int i = 1; i <= n; ++i) if (b[i].size ()) {
		sort (b[i].begin (), b[i].end ());
		id.emplace_back (i);
	}
	ll ans = 0, target, p, q, siz;
	for (int i = 0; i < id.size (); ++i) {
		query.clear ();
		for (int j = i + 1; j < id.size () && 1ll * id[i] * id[j] <= 2 * n; ++j) {
			for (int bj : b[id[j]]) {
				target = id[i] * id[j] - bj;
				query.emplace_back (target);
			}
		}
		sort (query.begin (), query.end ());
		p = q = 0, siz = b[id[i]].size ();
		for (auto it : query) {
			while (p < siz && b[id[i]][p] < it) ++p;
			if (p >= siz) break;
			else if (b[id[i]][p] > it) continue;
			q = max (p, q);
			while (q + 1 < siz && b[id[i]][q + 1] == b[id[i]][q]) ++q; 
			ans += q - p + 1;
		}
	}
	ll ans_same = 0;
	for (int i = 1, p, q, q2, siz, target; i * i <= 2 * n; ++i) {
		p = 0, siz = b[i].size (), q = q2 = siz - 1;
		while (p < siz) {
			target = 1ll * i * i - b[i][p];
			if (target < b[i][p]) break;
			while (q > p && b[i][q] > target) --q;
			if (q <= p) break;
			else if (b[i][q] < target) {++p; continue;}
			q2 = min (q2, q);
			q2 = max (p + 1, q2);
			while (q2 - 1 > p && b[i][q2 - 1] == target) --q2;
			ans_same += q - q2 + 1;
			++p;
		}
	}
	cout << ans + ans_same << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}