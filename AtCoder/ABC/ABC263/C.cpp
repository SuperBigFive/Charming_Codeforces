#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int val[maxn];
bool vis[maxn];

void init () {
	
}

void dfs (int now, int last) {
	if (now > n) {
		for (int i = 1; i <= n; ++i) {
			cout << val[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = last + 1; i <= m; ++i) {
		if (vis[i]) continue;
		val[now] = i;
		vis[i] = true;
		dfs (now + 1, i);
		vis[i] = false;
	}
}


void charming () {
	init ();
	cin >> n >> m;
	dfs (1, 0);
}

signed main () {
	charming ();
	return 0;
}