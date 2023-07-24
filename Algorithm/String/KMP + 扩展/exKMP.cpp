#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct exKMP {
	int n, m;
	string s, t;
	vector <int> z, p;
	
	exKMP (string &s, string &t) {
		this -> s = '#' + s, this -> t = '#' + t;
		this -> n = s.size (), this -> m = t.size ();
		this -> z = vector <int> (m + 5);
		this -> p = vector <int> (n + 5);
		Get_z (), Get_p ();
	}
	
	void Get_z () {
		for (int i = 2, l = 0, r = 0; i <= m; ++i) {
			if (i <= r) z[i] = min (r - i +  1, z[i - l + 1]);
			while (i + z[i] <= m && t[i + z[i]] == t[z[i] + 1]) ++z[i];
			if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
		}
		z[1] = m;
	}
	
	void Get_p () {
		for (int i = 1, l = 0, r = 0; i <= n; ++i) {
			if (i <= r) p[i] = min (r - i + 1, z[i - l + 1]);
			while (i + p[i] <= n && p[i] + 1 <= m
			&& s[i + p[i]] == t[p[i] + 1]) ++p[i];
			if (r < i + p[i] - 1) l = i, r = i + p[i] - 1;
		}
	}
};

void init () {}

void charming () {
	init ();
	string s, t;
	cin >> s >> t;
	exKMP exkmp (s, t);
	int ans_z = 0, ans_p = 0;
	for (int i = 1; i <= exkmp.m; ++i) ans_z ^= (i * (exkmp.z[i] + 1));
	for (int i = 1; i <= exkmp.n; ++i) ans_p ^= (i * (exkmp.p[i] + 1));
	cout << ans_z << endl << ans_p << endl;
}

signed main () {
	charming ();
	return 0;
}