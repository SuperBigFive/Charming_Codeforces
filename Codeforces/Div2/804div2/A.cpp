#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
ll arr[maxn];

void charming () {
	cin >> n;
	if (n & 1) {
		cout << -1 << endl;
	}
	else {
		cout << (n >> 1) << " " << 0 << " " << 0 << endl;
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
