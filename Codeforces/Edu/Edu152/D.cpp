#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), c (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int ans = 0;
	for (int i = 1, j, two; i <= n; i = j + 1) {
		j = i;
		if (a[i] == 0) continue;
		else {
			j = i, two = (a[j] == 2);
			while (j + 1 <= n && a[j + 1]) {
				two |= (a[++j] == 2);
			}
			++ans;
			if (two) {
				for (int k = i - 1; k <= j + 1; ++k) c[k] = 1;
			}
			else {
				for (int k = i; k <= j; ++k) c[k] = 1;
				if ((i > 1 && c[i - 1]) || i == 1) c[j + 1] = 1;
				else c[i - 1] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) if (!a[i] && !c[i]) ++ans;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}
