#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, k;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k;
	map <int, int> target;
	vector <pair <int, int> > pos;
	for (int i = 0, a; i < n; ++i) cin >> a, ++target[a];
	pos.emplace_back (make_pair (-2 * 1e18 - 5, 0));
	for (auto [num, cnt] : target) pos.emplace_back (make_pair (num, cnt));
	pos.emplace_back (make_pair (2 * 1e18 + 5, 0));
	int siz = pos.size ();
	vector <int> pre (siz);
	for (int i = 1; i < siz; ++i) pre[i] = pre[i - 1] + pos[i].second;
	
	auto check = [&] (int cur, int p, int &mx, int &ans) -> void {
		if (p > m || p < 0) return;
		while (cur + 1 < siz && pos[cur + 1].first <= p) ++cur;
		while (cur - 1 >= 0 && pos[cur].first > p) --cur;
		int l = 0, r = cur, k1 = cur, k2;
		while (l <= r) {
			int mid = l + r >> 1;
			if (pre[cur] - pre[mid] < k) r = mid - 1, k1 = mid;
			else l = mid + 1;
		}
		l = cur + 1, r = siz - 1, k2 = cur;
		while (l <= r) {
			int mid = l + r >> 1;
			if (pre[mid - 1] - pre[cur - (pos[cur].first == p)] < k) l = mid + 1, k2 = mid;
			else r = mid - 1;
		}
		int nmx = min (p, (p - pos[k1].first - 1) / 2) + min (m - p, (pos[k2].first - p - 1) / 2);
		if (pos[cur].first == p) nmx += (pos[cur].second < k);
		else nmx += 1;
		if (nmx > mx) mx = nmx, ans = p;
	};
	
	int mx = 0, ans = 0;
	check (0, 0, mx, ans);
	check (0, 1, mx, ans);
	check (0, 2, mx, ans);
	for (int i = 1; i < siz - 1; ++i) {
		check (i - 1, pos[i].first - 2, mx, ans);
		check (i - 1, pos[i].first - 1, mx, ans);
		check (i, pos[i].first, mx, ans);
		check (i, pos[i].first + 1, mx, ans);
		check (i, pos[i].first + 2, mx, ans);
	}
	check (siz - 1, m, mx, ans);
	check (siz - 1, m - 1, mx, ans);
	check (siz - 1, m - 2, mx, ans);
	cout << mx << " " << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}