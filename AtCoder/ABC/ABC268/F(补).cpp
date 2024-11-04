#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

struct func {
	double val;
	int tot;
}f[maxn];
int n;
int x[maxn], y[maxn];
vector <string> str;

void init () {}

void charming () {
	cin >> n;
	str.resize (n);
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		for (auto it : str[i]) {
			if (it == 'X') ++x[i];
			else y[i] += it - '0';
		}
		if (x[i]) f[i].val = (double) y[i] / x[i];
		else f[i].val = LLONG_MAX;
		f[i].tot = i;
	}
	sort (f, f + n, [](func &a, func &b) {
		return a.val < b.val;
	});
	string tmp;
	for (int i = 0; i < n; ++i) tmp += str[f[i].tot];
	ll res = 0;
	for (int i = 0, cnt = 0; i < tmp.size (); ++i) {
		if (tmp[i] != 'X') res += cnt * (tmp[i] - '0');
		else ++cnt;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}