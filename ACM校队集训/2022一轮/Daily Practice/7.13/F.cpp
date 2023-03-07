#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
ll val[maxn], res[maxn];

void init () {
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	sort (val + 1, val + 1 + n, [] (int x, int y) {
		return x > y;
	});
	int mid = 2e5;
	int p1 = mid, p2 = mid;
	res[mid] = val[1];
	for (int i = 2; i <= n; ++i) {
		if (i & 1) res[--p1] = val[i];
		else res[++p2] = val[i];
	}
	res[p1 - 1] = res[p2];
	res[p2 + 1] = res[p1];
	for (int i = p1; i <= p2; ++i) {
		if (res[i] >= res[i - 1] + res[i + 1]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	for (int i = p1; i <= p2; ++i) {
		cout << res[i] << ' ';
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
} 