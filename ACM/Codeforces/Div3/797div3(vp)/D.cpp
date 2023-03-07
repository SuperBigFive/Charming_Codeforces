#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;
char str[maxn];
int sum_black[maxn];

void charming () {
	cin >> n >> k;
	str[n+1] = '\0';
	for (int i = 1; i <= n; ++i) {
		cin >> str[i];
		if (str[i] == 'B') {
			sum_black[i] = sum_black[i-1] + 1;
		}
		else sum_black[i] = sum_black[i-1];
	}
	int ans = INT_MAX;
	for (int i = 1; i <= n - k + 1; ++i) {
		//if (str[i-1] == 'B' || str[i+k] == 'B' ) continue;
		ans = min (ans, k - sum_black[i+k-1] + sum_black[i-1]);
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
