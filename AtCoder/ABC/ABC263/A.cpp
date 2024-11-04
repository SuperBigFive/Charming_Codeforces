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

int n;
int vis[maxn];

void init () {
	
}

void charming () {
	init ();
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	++vis[a], ++vis[b], ++vis[c], ++vis[d], ++vis[e];
	int cnt = 0;
	bool ok = false;
	for (int i = 1; i <= 13; ++i) {
		if (vis[i]) ++cnt;
		if (vis[i] == 3) ok = true;
	}
	if (ok && cnt == 2) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}