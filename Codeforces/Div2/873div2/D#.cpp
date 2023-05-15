#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 5e3 + 5;

int t, n;
int a[N];
int dp[N][N], pos[N][N];

void init () {
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= n; ++j) 
	dp[N][N] = pos[i][j] = 0;
}

void charming () {
	init ();
	cin >> n;	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = n, nxt; i >= 1; --i) {
		nxt = 1;
		for (int j = i; j >= 1; --j) {
			if (a[j] > a[i]) ++nxt;
			pos[j][i] = i - nxt + 1;
		}
	}
	ll ans = 0;
	for (int i = 1, cur; i <= n; ++i) {
		vector <array <int, 2> > stk;
		cur = 0;
		for (int j = i + 1, k; j <= n; ++j) {
			if (pos[i][j] == j) dp[i][j] = dp[i][j - 1], ans += 1ll * dp[i][j];
			else {
				while (stk.size () && stk.back ()[0] >= pos[i][j]) {
					stk.pop_back ();
				}
				if (!stk.size ()) {
					stk.emplace_back ((array <int, 2>) {pos[i][j], j});
					dp[i][j] = j - pos[i][j];
				}
				else {
					if (stk.back ()[1] >= pos[i][j]) {
						dp[i][j] = dp[i][max (i, stk.back ()[0] - 1)] + j - stk.back ()[0];
						stk.back ()[1]= j;
					}
					else {
						dp[i][j] = dp[i][pos[i][j] - 1] + j - pos[i][j];
						stk.emplace_back ((array <int, 2>) {pos[i][j], j});
					}
				}
				dp[i][j] = cur;
				ans += 1ll * cur;
			}
		}
	}
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
