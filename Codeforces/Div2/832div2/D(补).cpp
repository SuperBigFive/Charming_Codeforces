#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, q;
int a[maxn], Xor[maxn], Sum[maxn];
map <int, vector <int> > id[2];

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		Xor[i] = Xor[i - 1] ^ a[i];
		Sum[i] = Sum[i - 1] + a[i];
		if (i & 1) id[1][Xor[i]].emplace_back (i);
		else id[0][Xor[i]].emplace_back (i);
	}
	for (int i = 1, l, r, id1; i <= q; ++i) {
		cin >> l >> r;
		if ((Xor[r] ^ Xor[l - 1])) {
			cout << -1 << endl;
			continue;
		}
		else if (Sum[r] - Sum[l - 1] == 0) {
			 cout << 0 << endl;
			 continue;
		}
		else if ((r - l + 1) & 1) {
			cout << 1 << endl;
			continue;
		}
		else if (a[r] == 0 || a[l] == 0) {
			cout << 1 << endl;
			continue;
		}
		else {
			int sig = (r & 1) ^ 1;
			int pl = lower_bound (id[sig][Xor[r]].begin (), 
			id[sig][Xor[r]].end (), l) - id[sig][Xor[r]].begin ();
			if ((pl < id[sig][Xor[r]].size () && id[sig][Xor[r]][pl] < r)) {
				cout << 2 << endl;
				continue;
			}
			sig = l & 1;
			int pr = lower_bound (id[sig][Xor[l - 1]].begin (),
			id[sig][Xor[l - 1]].end (), l) - id[sig][Xor[l - 1]].begin ();
			if ((pr < id[sig][Xor[l - 1]].size () && id[sig][Xor[l - 1]][pr] < r)) {
				cout << 2 << endl;
				continue;
			}
			cout << -1 << endl;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}