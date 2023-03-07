#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pip pair <int, pii> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 1e6 + 5;

inl int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar();
	}
	int k = ch -'0';
	while (ch = getchar(), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch-'0');
	}
	if (flag) return k;
	return -k;
}

struct Q {
	int tot, type;
	int pos1, pos2;
}q[maxn], tmp[maxn];
int n, m, k;
int val[maxn], cnt1[maxn], cnt2[maxn], bel[maxn], res[maxn];


void charming () {
	n = read ();
	//int t = clock ();
	for (int i = 1; i <= n; ++i) val[i] = read ();
	int len = sqrt ((double) n);
	for (rg i = 1; i <= n; ++i) {
		bel[i] = (i - 1) / len + 1;
	}
	m = read ();
	int cnt = 0, l1, r1, l2, r2;
	for (int i = 1; i <= m; ++i) {
		l1 = read (), r1 = read (), l2 = read (), r2 = read ();
		q[++cnt].pos1 = r1;
		q[cnt].pos2 = r2;
		q[cnt].tot = i;
		q[cnt].type = -1;
		
		q[++cnt].pos1 = r1;
		q[cnt].pos2 = l2 - 1;
		q[cnt].tot = i;
		q[cnt].type = 1;
		
		q[++cnt].pos1 = l1 - 1;
		q[cnt].pos2 = r2;
		q[cnt].tot = i;
		q[cnt].type = 1;
		
		q[++cnt].pos1 = l1 - 1;
		q[cnt].pos2 = l2 - 1;
		q[cnt].tot = i;
		q[cnt].type = -1;
	}
	sort (q + 1, q + 1 + (m << 2), [] (Q a, Q b) {
		if (bel[a.pos1] != bel[b.pos1]) return a.pos1 < b.pos1;
		if (bel[a.pos1] & 1) return a.pos2 < b.pos2;
		return a.pos2 > b.pos2;
	});
	int p1 = 0, p2 = 0;
	int ans = 0;
	for (int i = 1; i <= (m << 2); ++i) {
		while (p1 < q[i].pos1) {
			++p1;
			++cnt1[val[p1]];
			ans += cnt2[val[p1]];
		}
		while (p1 > q[i].pos1) {
			ans -= cnt2[val[p1]];
			--cnt1[val[p1]];
			--p1;
		}
		while (p2 < q[i].pos2) {
			++p2;
			++cnt2[val[p2]];
			ans += cnt1[val[p2]];
		}
		while (p2 > q[i].pos2) {
			ans -= cnt1[val[p2]];
			--cnt2[val[p2]];
			--p2;
		}
		res[q[i].tot] += ans * (-1) * q[i].type;
	}
	for (int i = 1; i <= m; ++i) {
		printf ("%lld\n", res[i]);
	}
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	charming ();
	return 0;
}