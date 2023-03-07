#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

struct Node {
	int val;
	int pos;
}a[maxn], b[maxn];
int t, n, tot;
int i, j, k;
int a1[maxn], a2[maxn], b1[maxn], b2[maxn];
int ansi[maxn], ansj[maxn];

void init () {
	tot = 0;
	for (i = 1; i <= 101; ++i) a1[i] = b1[i] = a2[i] = b2[i] = 0;
}

bool check () {}

void solve () {
	cin >> n;
	init ();
	for (i = 1; i <= n; ++i) cin >> a1[i], a2[i] = a1[i];
	for (i = 1; i <= n; ++i) cin >> b1[i], b2[i] = b1[i];
	sort (a2 + 1, a2 + 1 + n);
	int tmp;
	for (i = 1; i <= n; ++i) {
		if (a1[i] != a2[i]) {
			j = i; 
			while (a1[j] != a2[i]) {
				++j;
			}
			tmp = a1[j];
			a1[j] = a1[i];
			a1[i] = tmp;
			tmp = b1[j];
			b1[j] = b1[i];
			b1[i] = tmp;
			ansi[++tot] = i;
			ansj[tot] = j;
		}
	}
	sort (b2 + 1, b2 + 1 + n);
	for (i = 1; i <= n; ++i) {
		k = i;
		while (a1[k+1] == a1[k] && k <= n) ++k;
		if (b1[i] != b2[i]) {
			j = i;
			while (b1[j] != b2[i]) {
				++j;
			}
			if (j > k) {
				cout << -1 << endl;
				return;
			}
			tmp = b1[j];
			b1[j] = b1[i];
			b1[i] = tmp;
			ansi[++tot] = i;
			ansj[tot] = j;
		}
	}
	if (tot > 10000) {
		cout << -1 << endl;
		return;
	}
	cout << tot << endl;
	for (i = 1; i <= tot; ++i) {
		cout << ansi[i] << " " << ansj[i] << endl;
	}
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) solve ();
}
