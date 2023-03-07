#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
using namespace std;
const int maxn = 2e6 + 5;

int n, m;
int lim[maxn], beg[maxn];
char s[maxn], t[maxn];
vi pos[27];

void charming () {
	cin >> n >> m;
	cin >> s + 1;
	cin >> t + 1;
	
	int num, num_nxt;
	for (int i = 1; i <= n; ++i) {
		num = s[i] - 'a' + 1;
		pos[num].pb (-i);
	}
	
	int p;
	p = 1; 
	for (int i = 1; i <= n && p <= m; ++i) {
		if (s[i] == t[p]) {
			beg[p] = i;
			++p;
		}
	}
	
	p = m;
	for (int i = n; i >= 1 && p > 2; --i) {
		if (s[i] == t[p]) {
			lim[p] = i;
			--p;
		}
	}
	lim[m + 1] = n + 1;
	for (int i = 1; i <= 26; ++i) {
		if (pos[i].size ()) sort (pos[i].begin (), pos[i].end ());
	}
	
	ll res = -1000000000;
	int id;
	for (int i = 1; i < m; ++i) {
		num = t[i] - 'a' + 1;
		num_nxt = t[i + 1] - 'a' + 1;
		p = lim[i + 2];
		if (i == m - 1) {
			id = 0;
			while (-pos[num_nxt][id] >= p) ++id;
			res = max (res, -pos[num_nxt][id] - beg[i]);
			break;
		}
		id = lower_bound (pos[num_nxt].begin (), pos[num_nxt].end (), -p) - pos[num_nxt].begin ();
		while (-pos[num_nxt][id] >= p) ++id;
		res = max (res, -pos[num_nxt][id] - beg[i]);		
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}