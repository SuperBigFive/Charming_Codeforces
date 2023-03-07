#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int arr[maxn];
int l[maxn], r[maxn];
int mmin[maxn];

void init () {
	for (int i = 1; i <= n; ++i) l[i] = r[i] = 0;
}

void charming () {
	init ();
	cin >> n;
	mmin[0] = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		mmin[i] = arr[i] < mmin[i-1] ? arr[i] : mmin[i-1];
	}
	l[0] = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		r[i] = r[i-1];
		l[i] = min (mmin[i], min (l[i-1], arr[i] - r[i]));
		
		if (r[i] > arr[i]) {
			cout << "NO" << endl;
			return;
		}
		if (arr[i] > l[i]) {
			if (r[i] > arr[i] - l[i]) {
				cout << "NO" << endl;
				return;
			}
			r[i] = arr[i] - l[i];
		} 
	}
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
