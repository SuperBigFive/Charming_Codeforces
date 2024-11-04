#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, k;
int arr[maxn];
pair <int, int> ans[maxn];

void init () {}

void charming () {
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) cin >> arr[i];
	int now = 1, id = 1;
	ans[1].first = 1, ans[1].second = 0;
	for (int i = 2; i <= n; ++i) {
		if (i == arr[id + 1]) {
			ans[i].first = i;
			ans[i].second = 0;
			++id;
			continue;
		}
		for (int j = 1; j <= id; ++j) {
			if (ans[i - arr[j]].second + arr[j] > ans[i].first) {
				ans[i].first = arr[j] + ans[i - arr[j]].second;
				ans[i].second = ans[i - arr[j]].first;
			}
		}
	}
	cout << ans[n].first << endl;
}

signed main () {
	charming ();
	return 0;
}