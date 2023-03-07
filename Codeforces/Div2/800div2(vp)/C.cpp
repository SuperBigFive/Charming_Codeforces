#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 15;

int n, t;
int arr[maxn], pos[maxn];
int len[maxn];

void charming () {
	cin >> n;
	ll sum = 0;
	bool ok = false;
	int endd = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i]) endd = i;
	}
	for (int i = 1; i < endd; ++i) {
		sum += arr[i];
		if (sum <= 0) {
			ok = true;
		}
	}
	sum += arr[endd];
	if (sum) ok = true;
	if (ok) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
