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

int n, m;
ll c[maxn], bel[maxn], cnt[maxn];
pii res[maxn];
struct query {
	int tot;
	int l, r;
	bool operator < (const query &a) const {
		if (bel[l] != bel[a.l]) return bel[l] < bel[a.l];
		if (bel[l] & 1) return bel[r] < bel[a.r];
		return bel[r] > bel[a.r];
	}
}q[maxn];

pii simp (pii & a) {
	ll num = a.fi, fac1 = a.se, fac2 = a.se - 1;
	if (!num) return {0, 1};
	if (fac1 & 1) fac2 >>= 1;
	else fac1 >>= 1;
	vi prim[2];
	for (ll i = 2; i * i <= fac1; ++i) {
		if (!(fac1 % i)) {
			prim[0].pb (i);
			while (!(fac1 % i)) fac1 /= i;
		}
	}
	if (fac1 > 1) prim[0].pb (fac1);
 	for (ll i = 2; i * i <= fac2; ++i) {
		if (!(fac2 % i)) {
			prim[1].pb (i);
			while (!(fac2 % i)) fac2 /= i;
		}
	}
	if (fac2 > 1) prim[1].pb (fac2);
	fac1 = a.se, fac2 = a.se - 1;
	if (fac1 & 1) fac2 >>= 1;
	else fac1 >>= 1;
	for (auto it : prim[0]) {
		while (!(num % it) && !(fac1 % it)) {
			num /= it;
			fac1 /= it;
		}
	}
	for (auto it : prim[1]) {
		while (!(num % it) && !(fac2 % it)) {
			num /= it;
			fac2 /= it;
		}
	}
	return {num, fac1 * fac2};
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	int block = sqrt ((double) n);
	for (int i = 1; i <= n; ++i) {
		bel[i] = (i - 1) / block + 1;
	}
	for (int i = 1; i <= m; ++i) {
		q[i].l = read (), q[i].r = read ();
		q[i].tot = i;	
	}
	sort (q + 1, q + 1 + m);
	int pl = 1, pr = 0, son = 0, mo = 0;
	for (int i = 1; i <= m; ++i) {
		while (pr < q[i].r) {
			++pr;
			son += cnt[c[pr]];
			++cnt[c[pr]];
		}
		while (pr > q[i].r) {
			son -= cnt[c[pr]] - 1;
			--cnt[c[pr]];
			--pr;
		}
		while (pl < q[i].l) {
			son -= cnt[c[pl]] - 1;
			--cnt[c[pl]];
			++pl;
		}
		while (pl > q[i].l) {
			--pl;
			son += cnt[c[pl]];
			++cnt[c[pl]];
		}
		res[q[i].tot] = {son, q[i].r - q[i].l + 1};
	}
	for (int i = 1; i <= m; ++i) {
		res[i] = simp (res[i]);
	}
	for (int i = 1; i <= m; ++i) {
		cout << res[i].fi << '/' << res[i].se << endl;
	}
}
signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	charming ();
	return 0;
}