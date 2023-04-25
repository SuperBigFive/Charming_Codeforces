#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int val[maxn], res[maxn];
bool vis[maxn];
vi cho[maxn];

void init () {
	for (int i = 0; i <= n; ++i) cho[i].clear (), vis[i] = 0;
}

void charming () {
	init ();
	scanf ("%lld", &n);
	int tt = clock ();
	for (int i = 0; i < n; ++i) {
		for (int j = sqrt (i); j * j <= n + i - 1 && j * j - i - i <= 900; ++j) {
			if (j * j < i) continue;
			cho[i].pb (j * j - i);
		}
	}
	int mmax = -1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = cho[i].size () - 1; j >= 0; --j) {
			if (!vis[cho[i][j]]) {
				vis[cho[i][j]] = true;
				res[i] = cho[i][j];
				mmax = max (mmax, cho[i][j] - i);
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf ("%lld ", res[i]);
	}
}

signed main () {
	scanf ("%lld", &t);
	while (t--) charming ();
	return 0;
}