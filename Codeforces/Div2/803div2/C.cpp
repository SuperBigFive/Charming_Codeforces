#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
ll arr[maxn];

void charming () {
	cin >> n;
	int neg = 0, pos = 0, zero = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] > 0) ++pos;
		if (arr[i] < 0) ++neg;
		if (!arr[i]) ++zero;
	}
	if (n <= 10) {
		ll tmp;
		for (int i = 1; i <= n; ++i) {
			for (int j = i+1; j <= n; ++j) {
				for (int k = j+1; k <= n; ++k) {
					tmp = arr[i] + arr[j] + arr[k];
					bool ok = false;
					for (int q = 1; q <= n; ++q) {
						if (tmp == arr[q]) {
							ok = true;
							break;
						}
					}
					if (!ok) {
						cout << "NO" << endl;
						return;
					}
				}
			}
		}
		cout << "YES" << endl;
		return;
	}
	if (pos >= 2 || neg >= 2) {
		cout << "NO" << endl;
		return;
	}
	sort (arr + 1, arr + 1 + n);
	int p1 = 1, p2 = n;
	if (!(arr[p1] + arr[p2]) || !arr[p1] || !arr[p2]) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
