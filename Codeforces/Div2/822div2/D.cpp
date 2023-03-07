#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;
int arr[maxn];

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	int l = k - 1, r = k + 1, hp = arr[k], curl = hp, curr = hp, last = 0;
	while (l >= 1 && r <= n) {
		while (r <= n) {
			if (curr + arr[r] >= 0) curr += arr[r];
			else break;
			++r;
			if (curr > hp) curl += curr - hp, hp = curr;
		}
		if (r > n) {
			cout << "YES" << endl;
			return;
		}
		while (l >= 1) {
			if (curl + arr[l] >= 0) curl += arr[l];
			else break;
			--l;
			if (curl > hp) curr += curl - hp, hp = curl;
		}
		if (l < 1) {
			cout << "YES" << endl;
			return;
		}
		if (last == r - l) {
			cout << "NO" << endl;
			return;
		}
		last = r - l;
	}
	cout << "YES" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--)	charming ();
	return 0;
}