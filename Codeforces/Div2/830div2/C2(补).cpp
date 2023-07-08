#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> arr (n + 5), preSum (n + 5), preXor (n + 5);
	vector <int> pos;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		preSum[i] = preSum[i - 1] + arr[i];
		preXor[i] = preXor[i - 1] ^ arr[i];
		if (arr[i]) pos.emplace_back (i);
	}
	int l, r, mx, id1, id2, len;
	while (q--) {
		cin >> l >> r;
		len = r - l + 1;
		mx = (preSum[r] - preSum[l - 1]) - (preXor[r] ^ preXor[l - 1]);
		if (!mx) {
			cout << l << " " << l << endl;
			continue;
		}
		id1 = lower_bound (pos.begin (), pos.end (), l) - pos.begin ();
		id2 = upper_bound (pos.begin (), pos.end (), r) - pos.begin () - 1;
		int p1, p2;
		for (p1 = id1; p1 < pos.size () && pos[id1] <= pos[id2] && p1 - id1 <= 31; ++p1) {
			bool ok = false;
			for (p2 = id2; p2 >= 0 && pos[id2] >= pos[p1] && id2 - p2 <= 31; --p2) {
				if ((preSum[pos[p2]] - preSum[pos[p1] - 1]) 
				- (preXor[pos[p2]] ^ preXor[pos[p1] - 1]) >= mx) {
					ok = true;
				}
				else break;
			}
			if (ok && pos[++p2] - pos[p1] + 1 < len) {
				l = pos[p1], r = pos[p2];
				len = r - l + 1;
			}
		}
		cout << l << " " << r << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}