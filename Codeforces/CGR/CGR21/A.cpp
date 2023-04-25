#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 15;

int t, n, z;
ll ans;
int arr[maxn];
void init () {ans = 0;}

void charming () {
	cin >> n >> z;
	init ();
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if ((arr[i] | z) > ans) ans = arr[i] | z; 
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
