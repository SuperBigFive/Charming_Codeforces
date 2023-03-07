#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll 
#define ld long double
#define inl inline
using namespace std;
const int maxn = 1e2 + 5;

int t, n, m;
ll mmap[maxn][maxn];
bool can_incre[maxn][maxn];
bool need_change[maxn][maxn];

void init () {
	memset (mmap, 0, sizeof mmap);
	memset (need_change, false, sizeof need_change);
	memset (can_incre, false, sizeof can_incre);
}

void dfs (int row, int line) {
	
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mmap[i][j];
			if ((mmap[i][j] & 1) != ((i + j) & 1)) ++mmap[i][j];
		}	
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << mmap[i][j] << ' ';
		}
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}