#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
ll arr[maxn];

void charming () {
	cin >> n >> m;
	
	cout << 1 << " ";
	for (int i = 1; i <= 1; ++i) {
		for (int j = 2; j <= m; ++j) {
			if (i & 1) {
				if ((j / 2) & 1) cout << 0 << " "; 
				else cout << 1 << " ";
			}
			else {
				if ((j / 2) & 1) cout << 1 << " ";
				else cout << 0 << " ";
			}
		}
	}
	cout << endl;
	
	for (int i = 2; i <= n; ++i) {
		if (!((i / 2) & 1)) cout << 1 << " ";
		else cout << 0 << " ";
		for (int j = 2; j <= m; ++j) {
			if (!((i / 2) & 1)) {
				if ((j / 2) & 1) cout << 0 << " "; 
				else cout << 1 << " ";
			}
			else {
				if ((j / 2) & 1) cout << 1 << " ";
				else cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
