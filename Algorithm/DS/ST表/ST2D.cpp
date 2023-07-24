#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e3 + 5;

struct ST2D {
	int n, m, P;
	vector <int> POW2, LOG2;
	vector <vector <int> > a;
	vector <vector <vector <vector <int> > > > stmax, stmin;
	
	ST2D (int n, int m, vector <vector <int> > &a) {
		this -> n = n, this -> m = m, this -> P = 1;
		while ((1 << (P)) <= max (n, m)) ++P;
		this -> POW2 = vector <int> (P);
		this -> LOG2 = vector <int> (max (n, m) + 1);
		this -> stmax = vector <vector <vector <vector <int> > > > (n + 5, vector <
		vector <vector <int> > > (m + 5, vector <vector <int> > (P, vector <int> (P))));
		this -> stmin = vector <vector <vector <vector <int> > > > (n + 5, vector <
		vector <vector <int> > > (m + 5, vector <vector <int> > (P, vector <int> (P))));
		this -> a = a;
		Get ();
	}
	
	void Get () {
		POW2[0] = 1, LOG2[0] = -1;
		for (int i = 1; i < P; ++i) POW2[i] = POW2[i - 1] * 2;
		for (int i = 1; i <= max (n, m); ++i) LOG2[i] = LOG2[i / 2] + 1;
		for (int i = n; i >= 1; --i) {
			for (int j = m; j >= 1; --j) {
				stmax[i][j][0][0] = stmin[i][j][0][0] = a[i][j];
				for (int k1 = 0; k1 < P && j + POW2[k1] - 1 <= m; ++k1) {
					if (k1) {
						stmax[i][j][k1][0] = max (stmax[i][j][k1 - 1][0], stmax[i][j + POW2[k1 - 1]][k1 - 1][0]);
						stmin[i][j][k1][0] = min (stmin[i][j][k1 - 1][0], stmin[i][j + POW2[k1 - 1]][k1 - 1][0]);
					}
					for (int k2 = 0; k2 < P && i + POW2[k2] - 1 <= n; ++k2) {
						if (k2) {
							stmax[i][j][k1][k2] = max (stmax[i][j][k1][k2 - 1], stmax[i + POW2[k2 - 1]][j][k1][k2 - 1]);
							stmin[i][j][k1][k2] = min (stmin[i][j][k1][k2 - 1], stmin[i + POW2[k2 - 1]][j][k1][k2 - 1]);
						}
					}
				}
			}
		}
	}
	
	pair <int, int> Query (int x0, int y0, int x1, int y1) {
		if (x0 > x1 || y0 > y1) return make_pair (0, 0);
		int dx = x1 - x0 + 1, k1 = LOG2[dx];
		int dy = y1 - y0 + 1, k2 = LOG2[dy];
		return make_pair (max ({stmax[x0][y0][k1][k2], stmax[x1 - POW2[k2] + 1][y0][k1][k2],
		stmax[x0][y1 - POW2[k1] + 1][k1][k2], stmax[x1 - POW2[k2] + 1][y1 - POW2[k1] + 1][k1][k2]}),
		min ({stmin[x0][y0][k1][k2], stmin[x1 - POW2[k2] + 1][y0][k1][k2],
		stmin[x0][y1 - POW2[k1] + 1][k1][k2], stmin[x1 - POW2[k2] + 1][y1 - POW2[k1] + 1][k1][k2]}));
	}
};

int n, m, k;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k;
	vector <vector <int> > a (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
	ST2D st (n, m, a);
	int ans = 1e9;
	for (int i = 1; i + k - 1 <= n; ++i) {
		for (int j = 1; j + k - 1 <= m; ++j) {
			auto [mx, mn] = st.Query (i, j, i + k - 1, j + k - 1);
			ans = min (ans, mx - mn); 
		}
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}