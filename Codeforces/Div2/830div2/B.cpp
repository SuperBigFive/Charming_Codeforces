#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int sum1[maxn], sum2[maxn];
string s;

void init () {
	fill (sum1, sum1 + n + 5, 0);
	fill (sum2, sum2 + n + 5, 0);
}

void charming () {
	init ();
	cin >> n >> s;
	s = '#' + s;
	int cnt = 0, res = INT_MAX;
	sum1[n] = (s[n] == '1' ? 0 : 1);
	sum2[n] = sum1[n] ^ 1;
	for (int i = n - 1; i >= 1; --i) {
		sum1[i] = sum1[i + 1];
		sum2[i] = sum2[i + 1];
		if (s[i] == '0' && s[i + 1] == '1') sum1[i] += 2;
		if (s[i] == '1' && s[i + 1] == '0') sum2[i] += 2;
	}
	int be = 1;
	while (s[be] == '0') ++be;
	for (int i = be; i <= n; ++i) {
		if (cnt) res = min (res, sum2[i] + cnt);
		else res = min (res, sum1[i] + cnt);
		if (!(cnt & 1) && s[i] == '1') ++cnt;
		if ((cnt & 1) && s[i] == '0') ++cnt;
	}
	if (res == INT_MAX) res = 0;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}