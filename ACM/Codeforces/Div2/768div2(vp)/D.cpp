#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

pair <int, int> check (int len, vector <int> &cnt) {
	int sum = 0;
	for (int i = 1; i <= len; ++i) sum += cnt[i];
	if (sum >= n - sum + k) return make_pair (1, len);
	for (int i = 2, j = i + len - 1; j <= n; ++i, ++j) {
		sum += cnt[j] - cnt[i - 1];
		if (sum >= n - sum + k) return make_pair (i, i + len - 1);
	}
	return make_pair (-1, -1);
}

void charming () {
	init ();
	cin >> n >> k;	
	vector <int> a (n), ok (n), cnt (n + 1);
	for (auto &it : a) cin >> it, ++cnt[it];
	int l = 1, r = n, len = n;
	pair <int, int> range;
	while (l <= r) {
		int mid = l + r >> 1;
		range = check (mid, cnt);
		if (range.first != -1) r = mid - 1, len = mid;
		else l = mid + 1;
	}
	auto [x, y] = check (len, cnt);
	for (int i = 0; i < n; ++i) {
		ok[i] = (a[i] >= x && a[i] <= y);
	}
	vector <pair <int, int> > ans;
	for (int i = 0, cnt = 0, last = 0; i < n; ++i) {
		if (ok[i]) ++cnt;
		else --cnt;
		if (ans.size () >= k - 1) {
			ans.emplace_back (make_pair (i + 1, n));
			break;
		}
		if (cnt > 0) {
			ans.emplace_back (make_pair (last + 1, i + 1));
			last = i + 1;
			cnt = 0;
		}
	}
	cout << x << " " << y << endl;
	for (auto [lx, ry] : ans) {
		cout << lx << " " << ry << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}