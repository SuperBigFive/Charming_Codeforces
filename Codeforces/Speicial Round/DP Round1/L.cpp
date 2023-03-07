#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e6 + 5;

int n, m;

void init () {}

void charming () {
	cin >> n >> m;
	vector <pair <int, int> > pab (n), pcd (m);
	for (auto &it : pab) cin >> it.first >> it.second;
	for (auto &it : pcd) cin >> it.first >> it.second;
	sort (pcd.begin (), pcd.end ());
	vector <pair <int, int> > npcd;
	for (int i = 0, j, mx = -1; i < m; i = j) {
		j = i, mx = -1;
		while (j < m && pcd[j].first == pcd[i].first) {
			mx = max (mx, pcd[j].second), ++j;
		}
		npcd.emplace_back (make_pair (pcd[i].first, mx));
	}
	pcd = npcd, m = npcd.size ();
	vector <vector <pair <int, int> > > tag (N);
	auto bisect = [&] (vector <pair <int, int> > &p, int val) -> int {
		if (p.back ().first < val) return p.size ();
		int l = 0, r = p.size () - 1, res = r;
		while (l <= r) {
			int mid = l + r >> 1;
			if (p[mid].first >= val) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		return res;
	};
	vector <int> mxh (m);
	for (int i = m - 1; i >= 0; --i) {
		mxh[i] = max (mxh[min (m - 1, i + 1)], pcd[i].second);
	}
	for (int i = 0, p, cur, en; i < n; ++i) {
		p = bisect (pcd, pab[i].first);
		cur = pab[i].first;
		while (p < m) {
			en = pcd[p].first + 1;
			if (mxh[p] >= pab[i].second) {
				tag[cur - pab[i].first].emplace_back (make_pair (
				mxh[p] - pab[i].second + 1, 1));
				tag[en - pab[i].first].emplace_back (make_pair (
				mxh[p] - pab[i].second + 1, 0));
			}
			cur = en;
			++p;
		}
	}
	multiset <int> ms;
	int res = INT_MAX;
	for (int i = 0; i < N; ++i) {
		for (auto [h, st] : tag[i]) {
			if (st) ms.insert (h);
			else {
				auto it = ms.find (h);
				ms.erase (it);
			}
		}
		if (ms.size ()) res = min (res, i + (*ms.rbegin ()));
		else res = min (res, i);
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}