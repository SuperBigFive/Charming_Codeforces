#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int P1 = 131, P2 = 2333;
const int MOD1 = 1e9 + 7, MOD2 = 998244353;

struct KMP {
	int m;
	string t;
	vector <int> fail;
	
	KMP (string &t) {
		this -> t = '#' + t, this -> m = t.size ();
		this -> fail = vector <int> (m + 5);
		Get_fail ();
	}
	
	void Get_fail () {
		for (int i = 2, j; i <= m; ++i) {
			j = fail[i - 1];
			while (j && t[j + 1] != t[i]) j = fail[j];
			if (t[j + 1] == t[i]) fail[i] = j + 1;
		}
	}
};

int n, tot;

void init () {}

void charming () {
	init ();
	cin >> n;
	string t;

	auto Calc_hash = [&] (string t) -> pair <ll, ll> {
		ll h1 = 0, h2 = 0;
		for (int i = 0, siz = t.size (); i < siz; ++i) {
			h1 = (h1 * P1 + (t[i] - 'a' + 1)) % MOD1;
			h2 = (h2 * P2 + (t[i] - 'a' + 1)) % MOD2;
		}
		h1 = ((h1 % MOD1) + MOD1) % MOD1;
		h2 = ((h2 % MOD2) + MOD2) % MOD2;
		return make_pair (h1, h2);
	};
	
	map <pair <ll, ll>, int> mp;
	vector <map <int, int> > last (n + 5);
	vector <set <int> > s (n + 5);
	
	auto Solve = [&] (int id, int step) -> int {
		int be = last[id][step];
		if (!be) be = step;
		while (s[id].count (be)) be += step;
		last[id][step] = be;
		s[id].insert (be);
		return be / step;
	};
	
	for (int i = 0, m, delta, id; i < n; ++i) {
		cin >> t, m = t.size ();
		KMP kmp (t);
		delta = m - kmp.fail[m];
		pair <ll, ll> h = (m % delta) == 0 ? 
		Calc_hash (t.substr (0, delta)) : Calc_hash (t);
		if (mp.count (h)) id = mp[h];
		else id = mp[h] = ++tot;
		cout << Solve (id, (m % delta) == 0 ? m / delta : m) << " \n"[i == n - 1];
	}
}

signed main () {
	charming ();
	return 0;
}