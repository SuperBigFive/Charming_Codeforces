#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {}());

int t;

void init () {}

void charming (int cnt) {
	init ();
	vector <int> a (12);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end ());
	vector <vector <int> > res, nres1, nres2;
	vector <int> cho1, cho2;
	auto solve = [&] (vector <int> &cho) -> vector <vector <int> > {
		vector <int> nxt;
		vector <vector <int> > nres;
		for (int i = 2; i < 6; ++i) {
			if (a[cho[i]] < a[cho[i - 1]] + a[cho[i - 2]]) {
				for (int j = i; j >= i - 2; --j)
				nxt.emplace_back (a[cho[j]]);
				nres.emplace_back (nxt);
				nxt.clear ();
				break;
			}
		}
		if (nres.size () == 0) return nres;
		int sum = 0, mx = 0;
		for (int i = 0; i < 6; ++i) sum += a[cho[i]];
		for (int i = 4; i >= 1; --i) {
			for (int j = i - 1; j >= 0; --j) {
				if (a[cho[i]] + a[cho[j]] <= a[cho[5]]) break;
				sum = 0, mx = 0;
				for (int k = 0; k < 5; ++k) {
					if (k == i || k == j) continue;
					sum += a[cho[k]];
					mx = a[cho[k]];
				}
				if (sum - mx > mx) {
					nres.clear ();
					for (int k = 0; k < 5; ++k) {
						if (k == i || k == j) continue;
						nxt.emplace_back (a[cho[k]]);
					}
					nres.emplace_back (nxt);
					nxt[0] = a[cho[j]], nxt[1] = a[cho[i]], nxt[2] = a[cho[5]];
					nres.emplace_back (nxt);
					return nres;
				}
			}
		}
		return nres;
	};
	auto dfs1 = [&] (auto && me, int u) -> void {
		if (res.size () >= 4) return;
		if (cho1.size () >= 6) {
			cho2.clear ();
			for (int i = 0, p = 0; i < 12; ++i) {
				while (p < 6 && cho1[p] < i) ++p;
				if (p >= 6 || cho1[min (p, 5ll)] != i) cho2.emplace_back (i);
			}
			nres1 = solve (cho1);
			if (nres1.size () + 2 <= res.size ()) return;
			nres2 = solve (cho2);
			if (nres1.size () + nres2.size () > res.size ()) {
				res.clear ();
				for (int i = 0; i < nres1.size (); ++i)
				res.emplace_back (nres1[i]);
				for (int i = 0; i < nres2.size (); ++i)
				res.emplace_back (nres2[i]);
			}
			return;
		}
		for (int i = u; i + (6 - (cho1.size () + 1)) < 12; ++i) {
			cho1.emplace_back (i);
			me (me, i + 1);
			cho1.pop_back ();
			if (u == 0) break;
		}
	};
	dfs1 (dfs1, 0);
	cout << "Case #" << cnt << ": " << res.size () << endl;
	for (int i = 0; i < res.size (); ++i) {
		for (int j = 0; j < 3; ++j) 
		cout << res[i][j] << " \n"[j == 2];
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}