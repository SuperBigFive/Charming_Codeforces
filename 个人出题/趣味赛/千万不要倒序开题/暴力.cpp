#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e2 + 5;
mt19937 rnd (random_device {} ());

int t, n, m, mx;
int seq[maxn], vis[maxn];
vector <array <int, 4> > old_ans, ans, tmp;

void init () {
	old_ans.clear ();
	ans.clear (), tmp.clear ();
	fill (seq, seq + maxn, 0);
	fill (vis, vis + maxn, 0);
	mx = 0;
}

void check () {
	int tims = 0, sco = 0;
	for (int i = 0; i < tmp.size () && tims + tmp[seq[i]][3] <= m; ++i) {
		auto [a, b, c, d] = tmp[seq[i]];
		sco += b - tims * c;
		tims += d;
	}
	if (mx < sco) {
		mx = sco;
		ans.clear ();
		for (int i = 0; i < tmp.size (); ++i)
		ans.emplace_back (tmp[seq[i]]);
	}
}

void dfs (int id) {
	if (id >= tmp.size ()) {
		check ();
		return;
	}
	for (int i = 0; i < tmp.size (); ++i) {
		if (vis[i]) continue;
		seq[id] = i;
		vis[i] = true;
		dfs (id + 1);
		vis[i] = false;
	}
}

void Insert (array <int, 4> &d) {
	tmp = ans;
	fill (vis, vis + n + 5, 0);
	tmp.emplace_back (d);
	dfs (0);
	/*for (auto [a, b, c, d] : ans) {
		cout << a << " ";
	}
	cout << endl;*/
}

void charming () {
	init ();
	cin >> n >> m;
	//cout << "-----------------------------" << endl;
	//n = 10;
	for (int i = 1; i <= n; ++i) {
		array <int, 4> d;
		d[0] = i;
		cin >> d[1] >> d[2] >> d[3];
		/*d[1] = rnd () % 200 + 200;
		d[2] = rnd () % 10 + 1;
		d[3] = rnd () % 10 + 1;
		cout << d[1] << " " << d[2] << " " << d[3] << endl;*/
		mx = 0;
		Insert (d);
		bool ok = true;
		for (int j = 0, p = 0; j < old_ans.size (); ++j, ++p) {
			if (ans[p][0] == i) ++p;
			if (ans[p][0] != old_ans[j][0]) {
				ok = false;
				break;
			}
		}
		/*if (ok) cout << "OK" << endl;
		else {
			cout << "NO!" << endl;
			return;
		}*/
		old_ans = ans;
	}	
	int tims = 0, sco = 0, res = 0;
	for (auto [a, b, c, d] : ans) {
		if (tims + d > m) break;
		res += b - tims * (c);
		tims += d;
	}
	cout << res << endl;
	tims = 0;
	for (auto [a, b, c, d] : ans) {
		tims += d;
		if (tims > m) break;
		//cout << a << " ";
	}
}

signed main () {
	charming ();
	return 0;
}