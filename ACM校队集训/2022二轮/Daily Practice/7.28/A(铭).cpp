#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int opt[maxn];
bool vis[maxn];
vi res;

void init () {
	
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> opt[i];
	}
	for (int i = m; i >= 1; --i) {
		if (!vis[opt[i]]) {
			vis[opt[i]] = true;
			res.pb (opt[i]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) res.pb (i);
	}
	for (auto it : res) {
		cout << it << endl;
	}
}
signed main () {
	//freopen ("input.in", "r", stdin);
	charming ();
	return 0;
}