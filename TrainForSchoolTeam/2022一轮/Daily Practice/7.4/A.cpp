#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e5;

int t, n;
ll cnt[maxn];
ll val[maxn];
ll dp[maxn];

void charming () {
	cin >> n;
	int arr;
	for (int i = 1; i <= n; ++i) {
		cin >> arr;
		++cnt[arr];
	}
	for (int i = 1; i <= 1e5; ++i) {
		val[i] = cnt[i] * i;
	}
	dp[1] = val[1];
	for (int i = 1; i <= 1e5; ++i) {
		dp[i] = max (dp[i-1], dp[i-2] + val[i]);
	}
	cout << dp[maxm] << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
} 
