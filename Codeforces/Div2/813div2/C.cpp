#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int val[maxn];
bool vis[maxn];
stack <int> stk;

void init () {
	while (!stk.empty ()) stk.pop ();
	for (int i = 0; i <= n; ++i) {
		vis[i] = false;
	}
}

void charming () {
	init ();
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		if (vis[val[i]]) val[i] = 0;
		if (!stk.empty () && val[i] < stk.top ()) {
			while (!stk.empty ()) {
				if (stk.top () && !vis[stk.top ()]) ++res;
				vis[stk.top ()] = true;
				stk.pop ();
			}
		}
		if (vis[val[i]]) val[i] = 0;
		stk.push (val[i]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}