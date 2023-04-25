#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int t, n, k;
int arr[maxn];
vector <int> q;
void charming () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	int tootall = 0;
	for (int i = 2; i < n; ++i) {
		if (arr[i] > arr[i+1] + arr[i-1]) ++tootall; 
	}
	if (k > 1) cout << tootall << endl;
	else {
		cout << (n-1)/2 << endl;
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
