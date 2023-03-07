#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m, tot;
int i, j, k;
int mmax, mmin;
int arr[maxn], arr2[maxn];
char str[maxn];

void init () {
	mmax = -1, mmin = INT_MAX;
	tot = 0;
}

bool check () {}

void solve () {
	cin >> n;
	init ();
	int idx;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] != i - 1) {
			arr2[++tot] = arr[i];
		}
	}
	int ans = arr2[1] & arr2[2];
	for (i = 3; i <= tot; ++i) {
		ans = ans & arr2[i];
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
