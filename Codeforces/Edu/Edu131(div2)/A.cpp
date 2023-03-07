#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int arr[maxn];

void init () {
	
}

void charming () {
	cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	if (!arr[1] && !arr[2] && !arr[3] && !arr[4]) {
		cout << 0 << endl;
		return;
	}
	if (arr[1] && arr[2] && arr[3] && arr[4]) {
		cout << 2 << endl;
		return;
	}
	cout << 1 << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
