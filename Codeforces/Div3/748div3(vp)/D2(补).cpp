#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n;

void init () {}

void dfs (int id, vector <pair <int, int> > &prim,
vector <int> &res, int val) {
	if (id >= prim.size ()) {
		res.emplace_back (val);
		return;
	}
	for (int i = 0, last = 1; i <= prim[id].second; ++i) {
		dfs (id + 1, prim, res, val * last);
		last *= prim[id].first;	
	}	
}

vector <int> get_fac (int num) {
	vector <pair <int, int> > prim;
	for (int i = 2; i * i <= num; ++i) {
		if (!(num % i)) {
			int cnt = 0;
			while (!(num % i)) {
				++cnt;
				num /= i;
			}
			prim.emplace_back (make_pair (i, cnt));
		}
	}
	if (num > 1) prim.emplace_back (make_pair (num, 1));
	vector <int> res;
	dfs (0, prim, res, 1);
	return res;
}

bool check (vector <vector <pair <int, int> > > &edge, 
vector <int> &b, vector <int> &cnt, int k, int half) {
	if (k == 2) {
		k = 2;
	}
	if (edge[k].size () < half) return false;
	vector <int> pre (n), siz (n);
	for (int i = 0; i < n; ++i) pre[i] = i, siz[i] = cnt[b[i]];
	auto find = [&] (auto&& me, int x) -> int {
		if (x == pre[x]) return x;
		return pre[x] == me (me, pre[x]);
	};
	for (auto &[u, v] : edge[k]) {
		int fu = find (find, u), fv = find (find, v);
		if (fu == fv) continue;
		pre[fu] = fv;
		siz[fv] += siz[fu];
		if (siz[fv] >= half) return true;
	}
	return false;
}

void charming () {
	init ();
	cin >> n;
	int half = n / 2;
	vector <int> a (n), cnt (N << 1);
	set <int> exist;
	bool ok = false;
	for (auto &it : a) {
		cin >> it;
		it += N, ++cnt[it];
		if (cnt[it] >= half) ok = true;
		exist.insert (it);
	}
	int tim = clock ();
	if (ok) return (void) (cout << -1 << endl);
	vector <int> b;
	for (auto &it : exist) b.emplace_back (it);
	sort (b.begin (), b.end (), greater <int> ());
	n = b.size ();
	vector <vector <int> > fac (N << 1);
	vector <vector <pair <int, int> > > edge (N << 1);
	vector <vector <int> > pre (N << 1), siz (N << 1);
	int res = 2;
	auto find = [&] (auto&& me, int k, int x) -> int {
		if (!pre[k][x]) {
			siz[k][x] = cnt[b[x]];
			return pre[k][x] = x;
		}
		else if (x == pre[k][x]) return x;
		else return pre[k][x] = me (me, k, pre[k][x]);
	};
	for (int i = 0, diff; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			diff = b[i] - b[j];
			if (!fac[diff].size ()) fac[diff] = get_fac (diff);
			for (auto &it : fac[diff]) {
				if (!pre[it].size ()) pre[it].resize (n), siz[it].resize (n);
				int fi = find (find, it, i), fj = find (find, it, j);
				if (fi == fj) continue;
				pre[it][fi] = fj;
				siz[it][fj] += siz[it][fi];
				if (siz[it][fj] >= half) res = max (res, it);
			}
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}