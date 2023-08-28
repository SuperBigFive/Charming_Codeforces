#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;

int t, n, m;
int arr[maxn];
map <pair <int, int>, int> mp;

void init () {
	mp.clear ();
}

int dfs (vector <int> &p, int last, int cur, int siz, int mul, int mx) {
	if (cur > siz) return mx - mx / mul;
	int res = 0;
	for (int i = last + 1; siz - cur + i < p.size (); ++i) {
		res += dfs (p, i, cur + 1, siz, mul * p[i], mx);
	}
	return res;
}

int get_res (int num, int mx) {
	int res = 0;
	if (num == 1) return mx;
	if (mp.count (make_pair (num, mx)))
	return mp[make_pair (num, mx)];
	vector <int> prim;
	for (int i = 2; i * i <= num; ++i) {
		if (!(num % i)) {
			prim.emplace_back (i);
			while (!(num % i)) num /= i;
		}
	}
	if (num > 1) prim.emplace_back (num);
	for (int i = 0; i < prim.size (); ++i) {
		res = res + (i & 1 ? -1 : 1) * dfs (prim, -1, 1, i + 1, 1, mx);
	}
	return mp[make_pair (num, mx)] = res;
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 1; --i) {
		if (arr[i] % arr[i + 1] && arr[i + 1] != 1) {
			cout << 0 << endl;
			return;
		}
	}
	ll res = 1;
	for (int i = 2; i <= n; ++i) {
		res = (res * get_res (arr[i - 1] / arr[i], m / arr[i])) % mod; 
	}
	cout << (((res % mod) + mod) % mod) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}