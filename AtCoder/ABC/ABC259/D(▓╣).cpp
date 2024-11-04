#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define eps 1e-5
using namespace std;
const int maxn = 3e3 + 5;

ll n, beg, endd;
bool ok;
bool vis[maxn];

void init () {ok = false;}

struct Circle {
	ll x;
	ll y;
	ll r;
}c[maxn];
vector <int> node[maxn];

void dfs (int fa, int u) {
	if (ok) return;
	int v;
	for (int i = 0; i < node[u].size (); ++i) {
		v = node[u][i];
		if (v == fa || vis[v]) continue;
		if (v == endd) {
			ok = true;
			return;
		}
		vis[v] = true;
		dfs (u, v);
		if (ok) return; 
	}
}

void charming () {
	init ();
	cin >> n;
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll x, y, r;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> r;
		//scanf ("%ld%ld%ld", &x, &y, &r);
		c[i].x = x, c[i].y = y, c[i].r = r;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			ll k = (c[i].x - c[j].x) * (c[i].x - c[j].x) + (c[i].y - c[j].y) * (c[i].y - c[j].y);
			if ((k <= (c[i].r + c[j].r) * (c[i].r + c[j].r)) && (k >= (c[i].r - c[j].r) * (c[i].r - c[j].r))){
				node[i].push_back (j);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (abs((x1 - c[i].x) * (x1 - c[i].x) + (y1 - c[i].y) * (y1 - c[i].y) - c[i].r * c[i].r) <= eps) {
			beg = i;
			break;
		}
	} 
	for (int i = 1; i <= n; ++i) {
		if (abs((x2 - c[i].x) * (x2 - c[i].x) + (y2 - c[i].y) * (y2 - c[i].y) - c[i].r * c[i].r) <= eps) {
			endd = i;
			break;
		}
	} 
	if (beg == endd) {
		cout << "Yes" << endl;
		return;
	}
	dfs (-1, beg);
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main () {
	charming ();
	return 0;
}
