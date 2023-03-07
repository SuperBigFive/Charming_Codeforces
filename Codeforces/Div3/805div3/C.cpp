#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;
int arr[maxn];
map <int, int> posf, posl;
vector <int> a;

void init () {
	for (int i = 0; i < a.size (); ++i) {
		posf[a[i]] = posl[a[i]] = 0;
	}
	a.clear ();
}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (!posf[arr[i]]) a.push_back (arr[i]), posf[arr[i]] = i, posl[arr[i]] = i;
		posl[arr[i]] = i;
	}
	int u, v;
	for (int i = 1; i <= k; ++i) {
		cin >> u >> v;
		if (!posf[v] || !posf[u] || posf[u] > posl[v]) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}