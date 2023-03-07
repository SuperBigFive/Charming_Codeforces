#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 998244353;

int n, q, x, a, b, p;
int icpc[maxn][4];
int cpc[maxn][3];
int pc[maxn][2];
int sumc[maxn];
char s[maxn];

void init () {}

int get_ans (int l, int r) {
	int res_icpc = icpc[r][3] % mod;
	res_icpc = (res_icpc - icpc[l][3]) % mod;
	int res_pc = pc[r][1] % mod;
	res_pc = (res_pc - pc[l][0] * (sumc[r] - sumc[l]) - pc[l][1]) % mod;
	int res_cpc = cpc[r][2] % mod;
	res_cpc = (res_cpc - cpc[l][2] - (cpc[l][1] * (sumc[r] - sumc[l])) % mod - (cpc[l][0] * res_pc) % mod) % mod;
	res_icpc = (res_icpc - (icpc[l][2] * (sumc[r] - sumc[l])) % mod 
	- (icpc[l][1] * res_pc) % mod - (icpc[l][0] * res_cpc) % mod) % mod;
	return ((res_icpc % mod) + mod) % mod;
}

void charming () {
	cin >> n >> q;
	cin >> s + 1;
	for (int i = 1; i <= n; ++i) {
		sumc[i] = sumc[i - 1];
		for (int j = 0; j < 4; ++j) icpc[i][j] = icpc[i - 1][j];
		for (int j = 0; j < 3; ++j) cpc[i][j] = cpc[i - 1][j];
		for (int j = 0; j < 2; ++j) pc[i][j] = pc[i - 1][j];
		
		if (s[i] == 'I') ++icpc[i][0];
		else if (s[i] == 'C') {
			icpc[i][3] = (icpc[i][3] + icpc[i][2]) % mod;
			icpc[i][1] = (icpc[i][1] + icpc[i][0]) % mod;
			cpc[i][2] = (cpc[i][2] + cpc[i][1]) % mod;
			++cpc[i][0];
			pc[i][1] = (pc[i][1] + pc[i][0]) % mod;
			++sumc[i];
		}
		else if (s[i] == 'P') {
			icpc[i][2] = (icpc[i][2] + icpc[i][1]) % mod;
			cpc[i][1] = (cpc[i][1] + cpc[i][0]) % mod;
			++pc[i][0];
		}
	}
	cin >> x >> a >> b >> p;
	int res = 0;
	vector <int> u, v;
	for (int i = 1; i <= q; ++i) {
		x = (a * x + b) % p;
		u.emplace_back (x % n + 1);
	}
	for (int i = 1; i <= q; ++i) {
		x = (a * x + b) % p;
		v.emplace_back (x % n + 1);
	}
	for (int i = 0, uu, vv; i < q; ++i) {
		uu = u[i], vv = v[i];
		if (uu > vv) swap (uu, vv);
		res = (res + get_ans (uu - 1, vv)) % mod;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}