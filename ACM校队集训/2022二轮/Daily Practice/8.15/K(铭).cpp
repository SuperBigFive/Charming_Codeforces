#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define int ll
#define vi vector <int> 
#define pb push_back
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;
int val[maxn];

void init () {

}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	sort (val + 1, val + 1 + n);
	int res = 1;
	for (int i = n - 1; i >= 1; --i) {
		if (val[i] >= val[i + 1] - k) ++res;
		else break;
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
