#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const long long M = (long long) (1e9 * 1e4) + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), b (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	vector <pair <int, int> > stk;
	int tag = 0;
	for (int i = 1, j, LCM, nLCM; i <= n; i = j + 1) {
		j = i, stk.emplace_back (make_pair (i, b[i]));
		LCM = b[i];
		while (j + 1 <= n) {
			nLCM = LCM * b[j + 1] / __gcd (LCM, b[j + 1]);
			if (nLCM != LCM) {
				bool ok = true;
				for (auto it : stk) {
					if (a[it.first] % (nLCM / it.second)) {
						ok = false; break;
					}
				}
				if (!ok) {
					++tag, stk.clear ();
					break;
				}
			}
			if (a[j + 1] % (nLCM / b[j + 1])) {++tag; stk.clear (); break;}
			stk.emplace_back (make_pair (j + 1, b[j + 1]));
			++j, LCM = nLCM;
		}
		if (j == n) {tag += 1; break;}
	}
	cout << tag << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}