#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int arr[maxn];

void init () {
	for (int i = 1; i <= n + 1; ++i) arr[i] = 0;
}

int main () {
	/*ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);*/
	cin >> t;
	while (t--) {
		init ();
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; ++i) cin >> arr[i];
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (arr[i] % 2) ++cnt1;
			else ++cnt2;
		}
		if (cnt1 > cnt2) cout << cnt2 << endl;
		else cout << cnt1 << endl;
	}
	return 0;
}
