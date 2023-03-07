#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;

void init () {}


void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (maxn), b (maxn);
	vector <pair <int, int> > exc (maxn);
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) b[i] = i;
	for (int i = 1; i <= m; ++i) {
		exc[i] = make_pair (b[a[i]], b[a[i] + 1]);
		swap (b[a[i]], b[a[i] + 1]);
	}
	vector <int> rev (maxn);
	for (int i = 1; i <= n; ++i) rev[b[i]] = i;
	for (int i = 1; i <= m; ++i) {
		if (exc[i].first != 1 && exc[i].second != 1) {
			cout << rev[1] << endl;
		}
		else if (exc[i].first == 1) {
			cout << rev[exc[i].second] << endl;
		}
		else if (exc[i].second == 1) {
			cout << rev[exc[i].first] << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}