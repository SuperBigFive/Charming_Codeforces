#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 64;

int n, MOD;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> shift1 (M), shift2 (M);
	
	auto Get_level = [] (int x) -> int {
		int level = 0;
		while (x) ++level, x /= 2;
		return level;
	};
		
	auto Get_ans = [&] (int level, int x) -> int {
		if (x == 1) return 0;
		MOD = (1ll << (level - 1));
		int node_x = x + shift1[level] + shift2[level];
		node_x = ((node_x % MOD) + MOD) % MOD + MOD;
		int node_fx = node_x / 2;
		MOD = (1ll << (level - 2));
		int fx = node_fx - shift1[level - 1];
		fx = ((fx % MOD) + MOD) % MOD + MOD;
		return fx;
	};
	
	for (int i = 0, t, x, k, level; i < n; ++i) {
		cin >> t >> x;
		level = Get_level (x);
		if (t == 1) {
			cin >> k;
			MOD = (1ll << (level - 1));
			shift1[level] += k;
			shift1[level] = ((shift1[level] % MOD) + MOD) % MOD;
		}
		else if (t == 2) {
			cin >> k;
			MOD = (1ll << (level - 1));
			shift2[level] += k;
			shift2[level] = ((shift2[level] % MOD) + MOD) % MOD;
		}
		else while (x) {
			cout << x << " \n"[x == 1];
			x = Get_ans (level--, x);
		}
	}
}

signed main () {
	charming ();
	return 0;
}