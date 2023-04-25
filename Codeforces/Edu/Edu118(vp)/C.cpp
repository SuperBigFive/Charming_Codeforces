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
ll h;
ll atk[maxn];

void init () {
	
}

bool check (int k) {
	bool poi = false;
	ll dam = k;
	for (int i = n - 1; i > 0; --i) {
		if (atk[i + 1] - atk[i] >= k) dam += k;
		else dam += atk[i + 1] - atk[i];
	}
	return dam >= h;
}

void charming () {
	cin >> n >> h;
	for (int i = 1; i <= n; ++i) {
		cin >> atk[i];
	}
	int l = 1, r = h;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check (mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}