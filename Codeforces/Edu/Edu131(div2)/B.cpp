#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int arr[maxn];
bool vis[maxn];

void init () {
	for (int i = 1; i <= n; ++i) vis[i] = false;
}

void charming () {
	init (); 
	cin >> n;
	int i, val = 1;
	for (i = 1; i <= n; ++i) {
		while (vis[val]) ++val;
		arr[i] = val;
		vis[arr[i]] = true;
		while (arr[i] * 2 <= n && i < n) {
			++i;
			arr[i] = arr[i-1] * 2, vis[arr[i]] = true;
		}
	}
	cout << 2 << endl;
	for (int i = 1; i <= n; ++i) {
		cout << arr[i] << " ";
	}
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
