#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
int arr[maxn];
vector <int> prim, cnt;

void init () {}

void get_prim (ll k) {
	prim.clear ();
	for (int i = 2; i * i <= k; ++i) {
		if (!(k % i)) {
			int tmp = 0;
			prim.emplace_back (i);
			while (!(k % i)) k /= i, ++tmp;
			cnt.emplace_back (tmp);
		}
	}
	if (k > 1) prim.emplace_back (k), cnt.emplace_back (1);
}

bool check (ll num) {
	if (num < 2) return false;
	int m = arr[1] % num;
	for (int i = 2; i <= n; ++i) {
		if (arr[i] % num != m) return false;
	}
	return true;
}

void dfs (int now, int en, ll k) {
	if (now >= en) {
		if (check (k)) {
			cout << 1 << endl;
			exit (0);
		}
		return;
	}
	int last = 1;
	for (int i = 0, tmp = 1; i <= cnt[now]; ++i) {
		if (i) tmp = last * prim[now];
		dfs (now + 1, en, k * tmp);
		last = tmp;
	}
}

void charming () {
	init ();
	cin >> n;
	bool odd = false, even = false;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] & 1) odd = true;
		else even = true;
	}
	if (!odd || !even) {
		cout << 1 << endl;
		return;
	}
	sort (arr + 1, arr + 1 + n);
	n = unique (arr + 1, arr + 1 + n) - arr - 1;
	int d = LLONG_MAX;
	for (int i = 2; i <= n; ++i) 
	d = min (arr[i] - arr[i - 1], d);
	get_prim (d);
	dfs (0, prim.size (), 1);
	cout << 2 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}