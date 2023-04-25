#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 15;

int t, n, z;
ll ans;
int arr[maxn];
void init () {ans = 0;}

void charming () {
	cin >> n ;
	init ();
	bool ok1 = false;
	bool ok2 = false;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		if (arr[i]) ok1 = true;
	}
	int p1 = 1, p2 = n;
	while (!arr[p1] && p1 <= n) ++p1;
	while (!arr[p2] && p2 >= 1) --p2;
	for (int i = p1; i <= p2; ++i) {
		if (!arr[i]) {
			while (!arr[i] && i <= p2) ++i;
			--i;
			++ans;
		}
	}
	if (ans) cout << 2 << endl;
	else {
		if (p1 <= n) cout << 1 << endl;
		else cout << 0 << endl;
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
