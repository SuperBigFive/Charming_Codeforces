#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int t, n, p;
ll ans[maxn];

void init () {}

/*ll dfs (int cur) {
	if (ans.count (cur)) return ans[cur];
	if (cur > p) return ans[cur] = 0;
	return ans[cur] = (((1 + dfs (cur + 1)) % mod) + dfs (cur + 2)) % mod;
}*/

void charming () {
	init ();
	cin >> n >> p;
	vector <int> arr (n), seed;
	map <int, int> vis;
	for (auto &it : arr) cin >> it;
	sort (arr.begin (), arr.end ());
	for (auto &it : arr) {
		int tmp = it;
		while (tmp > 0) {
			if (tmp & 1) tmp >>= 1;
			else if (!(tmp % 4)) tmp /= 4;
			else break;
			if (vis[tmp]) {
				tmp = -1;
				break;
			}
		}
		if (tmp != -1) seed.emplace_back (it), vis[it] = true;
	}
	ll res = 0;
	ans[p + 1] = 0, ans[p] = 1;
	for (int i = p - 1; i >= 1; --i) 
	ans[i] = (1 + ans[i + 1] + ans[i + 2]) % mod;
	for (auto &it : seed) {
		for (int i = 30; i >= 1; --i) {
			if (!((it >> (i - 1)) & 1)) continue;
			it = i;
			break;
		}
		//dfs (it);
		res = (res + ans[it]) % mod;
	}
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}