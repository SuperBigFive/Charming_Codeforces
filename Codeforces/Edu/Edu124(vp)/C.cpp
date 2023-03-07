#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int mmin[5][5];
int val[5][maxn];

void init () {
	
}

void charming () {
	cin >> n;
	for (int i = 1; i <= 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> val[i][j];
		}
	}
	for (int i = 1; i <= 2; ++i) {
		for (int j = 1; j <= 2; ++j) {
			mmin[i][j] = INT_MAX;
			for (int k = 1; k <= n; ++k) {
				mmin[i][j] = min (mmin[i][j], abs (val[i][j == 1 ? 1 : n] - val[1 + ((i - 1) ^ 1)][k]));
			}
		}
	}
	ll cost1 = abs (val[1][1] - val[2][1]) + abs (val[1][n] - val[2][n]);
	ll cost2 = abs (val[1][1] - val[2][n]) + abs (val[1][n] - val[2][1]);
	ll cost3 = abs (val[1][1] - val[2][1]) + abs (mmin[1][2]) + abs (mmin[2][2]);
	ll cost4 = abs (val[1][1] - val[2][n]) + abs (mmin[1][2]) + abs (mmin[2][1]);
	ll cost5 = abs (val[1][n] - val[2][1]) + abs (mmin[1][1]) + abs (mmin[2][2]);
	ll cost6 = abs (val[1][n] - val[2][n]) + abs (mmin[1][1]) + abs (mmin[2][1]);
	ll cost7 = abs (mmin[1][1]) + abs (mmin[1][2]) + abs (mmin[2][1]) + abs (mmin[2][2]);
	ll res = INT_MAX;
	res = min (cost1, min (cost2, min (cost3, min (cost4, min (cost5, min (cost6, cost7))))));
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--)	charming ();
	return 0;
}