#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int n, k;
ll p[maxn], siz[maxn], res[maxn];
map <ll, ll> bel;
vector <ll> pil[maxn];
set <ll> pile;

void charming () {
	cin >> n >> k;
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	set <int> ::iterator it;
	int id, mmax;
	for (int i = 1; i <= n; ++i) {
		if (!tot) pile.insert (p[i]), bel[p[i]] = ++tot, pil[tot].pb (p[i]);
		else {
			it = pile.lower_bound (p[i]);
			if (*it < p[i]) {
				pile.insert (p[i]);
				bel[p[i]] = ++tot;
				pil[tot].pb (p[i]);
			}
			else {
				pil[bel[*it]].pb (p[i]);
				bel[p[i]] = bel[*it];
				pile.erase (*it);
				pile.insert (p[i]);
			}
		}
		if (pil[bel[p[i]]].size () >= k) {
			pile.erase (p[i]); 
			for (auto itt : pil[bel[p[i]]]) {
				res[itt] = i;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (res[i]) cout << res[i] << endl;
		else cout << -1 << endl;
	}
}

signed main () {
	charming ();
	return 0;
}