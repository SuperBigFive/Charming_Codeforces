#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e3 + 5;

int n, k;
int sum[maxn];
int card[maxn][maxn];
map <string, int> mp;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	char ch[4] = "012";
	for (int i = 1; i <= n; ++i) {
		string s;
		for (int j = 1; j <= k; ++j) {
			cin >> card[i][j];
			s += ch[card[i][j]];
		}
		mp[s] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			string s;
			for (int p = 1; p <= k; ++p) {
				if (card[i][p] == card[j][p])
				s += ch[card[i][p]];
				else {
					for (int q = 0; q < 3; ++q) {
						if (card[i][p] != q && card[j][p] != q) {
							s += ch[q];
							break;
						}
					}
				}
			}
			int tmp = mp[s];
			if (tmp) ++sum[i];
		}
		sum[i] /= 2;
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i) 
	res += sum[i] * (sum[i] - 1) / 2;
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}