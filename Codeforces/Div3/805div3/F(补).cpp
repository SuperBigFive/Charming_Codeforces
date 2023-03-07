#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;
const int maxn = 4e5 + 5;

int t, n;
int a[maxn], b[maxn];
map <int, int> cnt;

void init () {
	cnt.clear ();
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		while (!(a[i] & 1)) a[i] >>= 1;
		while (!(b[i] & 1)) b[i] >>= 1;
		++cnt[a[i]];
	}
	for (int i = 1; i <= n; ++i) {
		while (b[i] && !cnt[b[i]]) b[i] >>= 1;
		if (!b[i]) {
			cout << "NO" << endl;
			return;
		}
		--cnt[b[i]];
	}
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}