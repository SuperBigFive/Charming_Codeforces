#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 1e5 + 5;

int t, n;
int arr[maxn], tmp[maxn];

void init () {}

void charming () {
	cin >> n;
	bool ok;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	for (int i = n - 1; i >= 1; --i) {
		ok = true;
		int pre = arr[i + 1];
		for (int j = i; j >= 1; --j) {
			if (!arr[j]) ok = false;
			arr[j] = pre - arr[j];
			pre = pre - arr[j];
			if (!ok) {
				sort (arr + j, arr + i + 1);
				break;
			}
		}
		if (ok) sort (arr + 1, arr + 1 + i);
	}                           
	cout << arr[1] << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}