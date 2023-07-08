#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 26;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <string> s (n);
	vector <int> val (n);
	vector <vector <int> > cnt (n, vector <int> (M));
	vector <array <vector <int>, 2> > lack (M);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];	
		for (auto &it : s[i])
		cnt[i][it - 'a'] += 1;
		for (int j = 0; j < M; ++j) if (!cnt[i][j]) {
			lack[j][s[i].size () & 1].emplace_back (i);
			val[i] = val[i] * 2;
		} else if (cnt[i][j] & 1) val[i] = val[i] * 2 + 1;
		else val[i] = val[i] * 2;
	}
	int res = 0;
	for (int i = 0, target; i < M; ++i) {
		target = ((1 << 26) - 1) ^ (1 << (M - i - 1));
		map <int, int> mp;
		for (auto &it : lack[i][1]) mp[val[it]] += 1;
		for (auto &it : lack[i][0]) res += mp[target ^ val[it]];
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}