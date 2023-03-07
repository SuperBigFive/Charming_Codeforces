#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
ll height[maxn], cost[maxn];
ll sum_odd[maxn], sum_even[maxn];

void init () {
	for (int i = 1; i <= n; ++i) cost[i] = sum_odd[i] = sum_even[i] = 0;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> height[i];
	}
	int cool = (n + 1) / 2 - 1;
	ll ans1 = 0, ans2 = LONG_MAX, mmax;
	for (int i = 2; i < n; ++i) {
		mmax = max (height[i - 1], height[i + 1]);
		if (mmax >= height[i]) cost[i]= mmax - height[i] + 1;
		sum_even[i] = sum_even[i - 2];
		sum_odd[i] = sum_odd[i - 2];
		if (i & 1) sum_odd[i] += cost[i];
		else sum_even[i] += cost[i];
	}
	if (n & 1) {
		for (int i = 2; i <= n; i += 2) {
			ans1 += cost[i];
		}
		cout << ans1 << endl;
		return;
	}
	sum_even[n] = sum_even[n - 2] + cost[n];
	ans1 = sum_even[n];
	for (int i = 2; i <= n; i +=2) {
		ans2 = sum_even[i - 2] + sum_odd[n - 1] - sum_odd[i - 1];
		ans1 = min (ans1, ans2);
	}
	cout << ans1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}