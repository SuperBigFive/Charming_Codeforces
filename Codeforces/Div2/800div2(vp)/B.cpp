#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 15;

int t, n;
int pos0[maxn], pos1[maxn];
char str[maxn];

void charming () {
	cin >> n;
	cin >> str + 1;
	int tot0 = 0, tot1 = 0;
	for (int i = 1; i <= n; ++i) {
		if (str[i] == '0') pos0[++tot0] = i;
		else pos1[++tot1] = i;
	}
	ll ans = 0;
	int last0 = 1, last1 = 1;
	pos0[0] = pos1[0] = -1;
	for (int i = 1; i <= tot0; ++i) {
		if (pos0[i] - pos0[i-1] == 1) {
			++ans;
		}
		else ans += pos0[i];
	}
	for (int i = 1; i <= tot1; ++i) {
		if (pos1[i] - pos1[i-1] == 1) {
			++ans;
		}
		else ans += pos1[i];
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
