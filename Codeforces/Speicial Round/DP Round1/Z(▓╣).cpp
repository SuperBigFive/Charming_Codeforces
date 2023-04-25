#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e7 + 5;

int t, c, d, x;
int POW2[55];
vector <int> vis (N), prim;

void init () {}

void sieve () {
	POW2[0] = 1;
	for (int i = 1; i < 55; ++i) POW2[i] = POW2[i - 1] * 2;
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prim.emplace_back (i), vis[i] = 1;
		for (int j = 0; j < prim.size () && prim[j] * i < N; ++j) {
			if (i % prim[j] == 0) {
				vis[i * prim[j]] = vis[i];
				break;
			}
			vis[i * prim[j]] = vis[i] + 1;
		}
	}
}
	
void charming () {
	init ();
	cin >> c >> d >> x;
	auto cal = [&] (int num) -> int {
		num += d;
		if (num % c) return 0;
		return POW2[vis[num /  c]];
	};
	int res = 0;
	for (int i = 1; i * i <= x; ++i) {
		if (x % i) continue;
		res += cal (i) + cal (x / i) * (i * i < x);
	}
	cout << res << endl;
}

signed main () {
	sieve ();
	cin >> t;
	while (t--)	charming ();
	return 0;
}