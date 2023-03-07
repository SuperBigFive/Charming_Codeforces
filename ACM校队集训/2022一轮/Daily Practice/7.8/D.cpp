#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e3 + 5;

int t, n, k;
int arr[maxn];
bool vis[maxn];

void charming () {
	memset (vis, 0, sizeof vis);
	cin >> n >> k;
	if (k > (n - 1) / 2) {
		cout << -1 << endl;
		return;
	}
	arr[1] = 1;
	int i;
	for (i = 1; i <= n && k; ++i) {
		if (i & 1) arr[i] = (i + 1) / 2, vis[(i + 1) / 2] = true;
		else --k, arr[i] = n - (i / 2 - 1), vis[n - (i / 2 - 1)] = true;
	}
	int j = n;
	while (vis[j]) --j;
	for (i; i <= n; ++i) {
		arr[i] = j;
		--j;
	}
	for (int i = 1; i <= n; ++i) cout << arr[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
