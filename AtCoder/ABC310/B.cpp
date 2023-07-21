#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> p (n + 5), c (n + 5);
	vector <vector <int> > F (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i) {
		cin >> p[i] >> c[i];
		for (int j = 1; j <= c[i]; ++j) {
			cin >> F[i][j];
		}
		sort (F[i].begin () + 1, F[i].begin () + 1 + c[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (p[j] > p[i]) continue;
			else {
				int q = 1, ok = 1;
				for (int p = 1; p <= c[i]; ++p) {
					while (q <= c[j] && F[j][q] < F[i][p]) ++q;
					if (q > c[j] || F[j][q] > F[i][p]) {ok = 0; break;}
				}
				if (!ok) continue;
				if (p[j] < p[i] || c[j] > c[i]) {
					cout << "Yes" << endl;
					exit (0);
				}
			}
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i - 1; j >= 1; --j) {
			if (p[j] > p[i]) continue;
			else {
				int q = 1, ok = 1;
				for (int p = 1; p <= c[i]; ++p) {
					while (q <= c[j] && F[j][q] < F[i][p]) ++q;
					if (q > c[j] || F[j][q] > F[i][p]) {ok = 0; break;}
				}
				if (!ok) continue;
				if (p[j] < p[i] || c[j] > c[i]) {
					cout << "Yes" << endl;
					exit (0);
				}
			}
		}
	}
	cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}