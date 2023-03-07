#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int t, n, m;
int i, j, k;
int arr[maxn];
int change[maxn];

void init () {}

bool check () {}

void solve () {
	cin >> n;
	init ();
	for (i = 1; i <= n; ++i) cin >> arr[i];
	cin >> m;
	ll sum = 0;
	for (i = 1; i <= m; ++i) cin >> change[i], sum = (sum + change[i]) % n;
	cout << arr[(sum%n)+1] << endl;
	
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) solve ();
}
