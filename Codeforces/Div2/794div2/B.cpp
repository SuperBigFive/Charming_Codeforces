#include <bits/stdc++.h>
using namespace std;
const int maxn  = 1e5 + 5;

int t, n;
int i, j, k;
int arr[maxn];
char str[maxn];
bool flag1, flag2;

void init () {}

bool valid () {}

void solve () {
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> arr[i];
	int ans = 0;
	for (i = 1;  i < n; ++i) {
		if (arr[i] > arr[i+1]) ++ans, ++i;
	}
	cout << ans << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) solve ();
}
