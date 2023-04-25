#include <bits/stdc++.h>
#define ll long long
#define Pii pair <int, int>
#define fir first
#define se second
#define pb push_back
using namespace std;
const int maxn = 1e6 + 5;

int t, n, k;
char str[maxn];
bool vis[maxn];

void init () {
	memset (vis, false, sizeof vis);
}

void charming () {
	init ();
	cin >> n;
	cin >> str + 1;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[str[i] - 'A']) vis[str[i] - 'A'] = true, ans += 2;
		else ans += 1;
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}