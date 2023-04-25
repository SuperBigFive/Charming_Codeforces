#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	int sum = 0;
	vector <pair <int, int> > seq (n);
	for (int i = 0; i < n; ++i) cin >> seq[i].first;
	for (int i = 0; i < n; ++i) cin >> seq[i].second, sum += seq[i].second - seq[i].first + 1;
	if (sum < k) return void (cout << -1 << endl);
	vector <int> pos1;
	for (int i = 0; i < n; ++i) if (seq[i].first == seq[i].second) pos1.emplace_back (seq[i].first);
	int ans = LLONG_MAX;
	int curk = 0, step = 0, last = 0, cnt = 0;
	for (int i = 0; i < n && curk < k; ++i) {
		auto [l, r] = seq[i];
		if (r == l) {
			step += r - last;
			last = r;
			++cnt;
		} else if (r - l + 1 < (k - curk)) {
			step += r - last + 2;
			curk += (r - l + 1);
			last = r;
		} else {
			step += l + (k - curk) - 1 - last + 2;
			return void (cout << min (ans, step) << endl);
		}
		if (i + 1 < n) {
			if (cnt + curk < k) continue;
			else ans = min (ans, step + 2 * (k - curk));
		} else {
			if (cnt >= k - curk) return void (cout << min (ans, step + 2 * (k - curk)) << endl);
			else {
				step += 2 * (k - curk), curk += cnt;
				int p = 0;
				while (p < pos1.size () && pos1[p] <= r) ++p;
				p += (k - curk - 1);
				step += pos1[p] - r;
				return void (cout << min (step, ans) << endl);
			}
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}