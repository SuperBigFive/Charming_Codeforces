#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e3 + 5;
mt19937 rnd (random_device {} ());

int n, m, k;
vector <pair <int, int> > p1, p2;
int mp[maxn][maxn];

void init () {
	p1.clear (), p2.clear ();
};

void check () {
	while (true) {
		init ();
		n = 500, m = 500;
		k = 0;
		if (n * m > 250000) continue;
		int mx = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				mp[i][j] = rnd () % mx;
				if (mp[i][j]) mp[i][j] = 0;
				else mp[i][j] = 1, ++k;
			}
		}
		cout << n << " " << m << " " << k << endl;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
			cout << mp[i][j];
			cout << endl;
		}
		break;
	}
}

void solve () {
	/*cin >> n >> m >> k;
	char ch;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	cin >> ch, mp[i][j] = ch;*/
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((j - 1) * m + i > k) continue;
			if (mp[j][i] == 0) p1.emplace_back (make_pair (j, i));
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((j - 1) * m + i <= k) continue;
			if (mp[j][i] == 1) p2.emplace_back (make_pair (j, i));
		}
	}
	int res = 0, siz = p1.size ();
	for (int i = 0; i < siz; ++i) {
		auto [x1, y1] = p1[i];
		auto [x2, y2] = p2[i];
		res += abs (x1 - x2) + abs (y1 - y2);
	}
	cout << res << endl;
}

void charming () {
	init ();
	
	freopen ("C:\\Users\\15113\\Desktop\\input\\20.in", "w", stdout);
	check ();
	fclose (stdout);
	
	freopen ("C:\\Users\\15113\\Desktop\\output\\20.out", "w", stdout);
	solve ();
	fclose (stdout);
	
	/*freopen ("C:\\Users\\15113\\Desktop\\input\\18.in", "w", stdout);
	check ();
	fclose (stdout);
	
	freopen ("C:\\Users\\15113\\Desktop\\output\\18.out", "w", stdout);
	solve ();
	fclose (stdout);
	
	freopen ("C:\\Users\\15113\\Desktop\\input\\19.in", "w", stdout);
	check ();
	fclose (stdout);
	
	freopen ("C:\\Users\\15113\\Desktop\\output\\19.out", "w", stdout);
	solve ();
	fclose (stdout);*/
}

signed main () {
	charming ();
	return 0;
}

