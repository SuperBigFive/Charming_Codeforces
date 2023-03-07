#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 4e3 + 5;
const int mod = 998244353;

int n;
int dx[4] = {-1, 0, 0, -1}, dy[4] = {1, 1, 0, 0};
int dx2[4] = {0, 0, -1, -1}, dy2[4] = {1, 0, 0, 1};
int dx3[4] = {-1, 0, 1, 0}, dy3[4] = {0, 1, 0, -1};
int dx4[4] = {-1, 1, 1, -1}, dy4[4] = {1, 1, -1, -1};
bool have_s[maxn][maxn], have_c[maxn][maxn];
vector <pair <int, int> > pos_s, pos_c;

void init () {}

ll qpow (ll num, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = (res * num) % mod;
		p >>= 1;
		num = (num * num) % mod;
	}
	return res % mod;
}

void charming () {
	cin >> n;
	for (int i = 1, op, x, y; i <= n; ++i) {
		cin >> op >> x >> y;
		x += 105, y += 105;
		if (op == 1) {
			for (int i = 0, new_x, new_y; i < 4; ++i) {
				new_x = x + dx[i], new_y = y + dy[i];
				if (have_s[new_x][new_y]) continue;
				pos_s.emplace_back (make_pair (new_x, new_y));
				have_s[new_x][new_y] = true;
			}
		}
		else {
			if (have_c[x][y]) continue;
			pos_c.emplace_back (make_pair (x, y));
			have_c[x][y] = true;
		}
	}
	int res_a = 0, res_2 = 0, res_6 = 0;
	int cur_x, cur_y, new_x, new_y;
	for (auto it : pos_s) {
		cur_x = it.first + 1, cur_y = it.second - 1;
		for (int i = 0; i < 4; ++i) {
			new_x = cur_x + dx[i], new_y = cur_y + dy[i];
			if (!have_s[new_x + dx2[i]][new_y + dy2[i]]
			&& !have_c[cur_x + dx[(i + 1) % 4]][cur_y + dy[(i + 1) % 4]]
			&& !have_c[new_x][new_y]) ++res_a;
		}
	}
	for (auto it : pos_c) {
		cur_x = it.first, cur_y = it.second;
		for (int i = 0; i < 4; ++i) {
			new_x = cur_x + dx[i], new_y = cur_y + dy[i];
			if (have_s[new_x][new_y]) continue;
			bool ok1 = have_c[cur_x + dx3[i]][cur_y + dy3[i]];
			bool ok2 = have_c[cur_x + dx3[(i + 1) % 4]][cur_y + dy3[(i + 1) % 4]];
			bool ok3 = have_c[cur_x + dx4[i]][cur_y + dy4[i]];
			if ((ok1 && ok2) || ok3) continue;
			else if (!ok1 && !ok2) ++res_2;
			else ++res_6;
		}
	}
	int res = (3 * res_2 + res_6) * qpow (6, mod - 2);
	res = ((res % mod) + mod) % mod;
	cout << res_a << " " << res << endl;
}

signed main () {
	charming ();
	return 0;
}