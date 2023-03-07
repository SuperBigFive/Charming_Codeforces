#include <bits/stdc++.h>
using namespace std;
const int maxn  = 1e5 + 5;

int t, n;
int i, j, k;
int arr[maxn];
char str[maxn];
bool flag1, flag2;

void init () {}

bool valid () {}

void solve () {
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> arr[i];
	double sum = 0; 
	for (i = 1; i <= n; ++i) sum += arr[i];
	if (!sum) {
		cout << "YES" << endl;
		return;
	}
	sum /= n;
	for (i = 1; i <= n; ++i) if (arr[i] == sum) {
		cout << "YES" << endl;
		return;
	}
	/*for (i = 1 ; i <= n; ++i) {
		for (j = i ; j <= n; ++j) {
			if (arr[i] + arr[j] == 2*sum) {
				cout << "YES" << endl;
				return;
			}
		} 
	}*/
	cout << "NO" << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) solve ();
}
