#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int n;
int a[maxn];

void init () {}

bool check (int mx) {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1;i <= n; ++i) {
		if (a[i] <= mx) {
			if (a[i] != a[i - 1]) ++cnt1;
			else ++cnt2;
		}
		if (a[i] > mx) ++cnt2;
	}
	return cnt1 + cnt2 / 2 >= mx;
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a + 1, a + 1 + n);
	int l = 0, r = n, res = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}