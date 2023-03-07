#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int arr[maxn];

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	int tmp;
	for (int i = 1; i <= n; ++i) {
		tmp = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			tmp = tmp ^ arr[j];
		}
		if (tmp == arr[i]) {
			cout << arr[i] << endl;
			return;
		}
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
