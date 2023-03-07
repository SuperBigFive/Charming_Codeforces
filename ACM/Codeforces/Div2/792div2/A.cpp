#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int t, n, tot;
int arr[maxn];

void init () {
	tot = 0;
}

void check () {}

void solve () {
	cin >> n;
	init ();
	int mmin = 1e9 + 1;
	while (n > 0) {
		arr[++tot] = n % 10;
		n /= 10;
		if (mmin > arr[tot]) mmin = arr[tot];
	}
	if (tot == 2) {
		cout << arr[1] << endl;
		return;
	}
	cout << mmin << endl;
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) solve ();
}
