#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 1e6 + 5;

int n;
bool exist[maxn];
vector <ll> node[maxn];

void init () {
	for (int i = 1; i < maxn; ++i) exist[i] = false;
}

void build () {
	for (ll i = i; i <= 1e6; ++i) {
		for (ll j = i + 1; j * j - i * i <= maxn; ++j) {
			node[i].push_back (j * j - i * i);
		}
	}
}

void charming () {
	init ();
	cin >> n;
	ll tmp;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		exist[tmp] = true;
	}
	build ();
	ll ans = 0;
	for (ll i = 1; i <= 1e6; ++i) {
		if (exist[i]) {
			for (ll j = 0; j < node[i].size (); ++j) {
				if (exist[node[i][j]]) ++ans;
			}
		}
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
