#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int arr[maxn];

void init () {}

void charming (){
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	sort (arr + 1, arr + 1 + n);
	int cnt = 0, mmax = -1;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		cnt = 0;
		while (arr[j] == arr[i] && j <= n) ++cnt, ++j;
		i = j - 1;
		mmax = max (cnt, mmax);
	}
	if (arr[1] == arr[n]) {
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	while (mmax < n) {
		int tmp = mmax;
		++ans;
		if (mmax + tmp <= n) {
			ans += tmp;
			mmax += tmp;
		}
		else {
			ans += n - tmp;
			break;
		}
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
}
