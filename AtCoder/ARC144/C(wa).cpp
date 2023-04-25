#include <bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 3e5 + 5;

int n, k;
int res[maxn], tmp[maxn];

void charming () {
	cin >> n >> k;
	int tot = 0;
	if (n / 2 < k) {
		cout << -1 << endl;
	}
	for (int i = 1; i <= n; ++i) {
		if (i <= k || n - i + 1 >= 1 + k) res[i] = i + k;
		else res[i] = ++tot;
	}		
	bool ok = true;
	while (ok) {
		ok = false;
		int p1 = 1, p2 = n - tot + 1;
		while (p1 <= p2 && p2 <= n) {
			if (abs (res[p2] - p1) >= k && abs (res[p1] - p2) >= k && res[p2] < res[p1]) {
				swap (res[p1], res[p2]);
				++p1, ++p2;
				ok = true;
			}
			else ++p1;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}