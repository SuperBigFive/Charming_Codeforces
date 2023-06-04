#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, m;
int isPrime[N];

void init () {}

void Get () {
	vector <int> prim, vis (N);
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prim.emplace_back (i), isPrime[i] = 1;
		for (int j = 0; j < prim.size () && i * prim[j] < N; ++j) {
			vis[i * prim[j]] = 1;
			if (i % prim[j] == 0) break;
		}
	}
}

void charming () {
	init ();
	cin >> n >> m;
	if (m % 2 == 0) {
		for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j)
		cout << (i - 1) * m + j << " \n"[j == m];
	}
	else if (n % 2 == 0) {
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		cout << (j - 1) * n + i << " \n"[j == m];
	}
	else {
		vector <int> odd, even;
		for (int i = 1; i <= n * m; i += m) {
			if (i & 1) odd.emplace_back (i);
			else even.emplace_back (i);
		}
		int p0 = 0, p1 = 0, ok = 0;
		for (p0 = 0; p0 < odd.size () && !ok; ++p0)
		for (p1 = 0; p1 < even.size () && !ok; ++p1)
		if (isPrime[abs (even[p0] - odd[p1])]) continue;
		else ok = true;
		--p0, --p1;
		for (int i = 0; i < odd.size (); ++i) {
			if (i == p1) continue;
			else for (int j = 0; j < m; ++j) {
				cout << odd[i] + j << " \n"[j == m - 1];
			}
		}
		for (int j = 0; j < m; ++j) {
			cout << odd[p1] + j << " \n"[j == m - 1];
		}
		for (int j = 0; j < m; ++j) {
			cout << even[p0] + j << " \n"[j == m - 1];
		}
		for (int i = 0; i < even.size (); ++i) {
			if (i == p0) continue;
			else for (int j = 0; j < m; ++j) {
				cout << even[i] + j << " \n"[j == m - 1];
			}
		}
	}
}

signed main () {
	Get ();
	cin >> t;
	while (t--) charming ();
	return 0;
}