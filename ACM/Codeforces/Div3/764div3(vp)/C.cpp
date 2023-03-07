#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int arr[maxn];
int cnt[maxn];

void init () {
	for (int i = 1; i <= n; ++i) cnt[i] = 0;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		while (arr[i] > n) arr[i] >>= 1;
		++cnt[arr[i]];
	}
	sort (arr + 1, arr + 1 + n);
	bool ok = false;
	while (!ok) {
		ok = true;
		for (int i = n; i >= 1; --i) {
			if (arr[i] == arr[i-1]) arr[i] >>= 1, ok = false;
			if (!arr[i]) {
				cout << "NO" << endl;
				return;
			}
		}
		sort (arr + 1, arr + 1 + n);
	}
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--)
		charming ();
	return 0;
}
