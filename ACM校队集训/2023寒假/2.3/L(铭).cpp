#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-8;

int t, n, l, r;

struct Point {
	double x, y, bel;
};

double get_dis (Point &a, Point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool check (Point &a, Point &b, Point &c) {
	double dis1 = get_dis (a, b);
	double dis2 = get_dis (a, c);
	double dis3 = get_dis (b, c);
	if (abs (dis1 - dis2) <= eps && abs (dis1 - dis3) <= eps) return true;
	return false;
}

void init () {}

void test () {
	init ();
	vector <Point> p;
	n = 50;
	Point rt;
	rt.x = 0, rt.y = 0, rt.bel = 1;
	vector <int> vis (N);
	queue <Point> q;
	q.push (rt);
	while (!q.empty ()) {
		Point cur = q.front (), nxt;
		q.pop ();
		if (cur.bel > n) continue;
		p.emplace_back (cur);
		q.back ();
		if (!vis[cur.bel]) {
			nxt.x = cur.x - 0.5;
			nxt.y = cur.y - sqrt (3) / 2;
			nxt.bel = cur.bel + 1;
			q.push (nxt);
			vis[cur.bel] = true;
		}
		nxt.x = cur.x + 0.5;
		nxt.y = cur.y - sqrt (3) / 2;
		nxt.bel = cur.bel + 1;
		q.push (nxt);
	}
	cin >> l >> r;
	auto solve = [&] () -> int {
		int res = 0;
		for (int i = 0; i < p.size (); ++i) {
			if (p[i].bel < l) continue;
			if (p[i].bel > r) break;
			for (int j = i + 1; j < p.size (); ++j) {
				if (p[j].bel < l) continue;
				if (p[j].bel > r) break;
				for (int k = j + 1; k < p.size (); ++k) {
					if (p[k].bel < l) continue;
					if (p[k].bel > r) break;
					if (check (p[i], p[j], p[k])) ++res;
				}
			}
		}
		return res;
	};
	cout << solve () << endl;
	/*for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			l = i, r = j;
			cout << "l = " << i << ", " << "r = " << r;
			cout << ": " << solve () << endl;
		}
	}
	cout << "-----------------------------" << endl;
	for (int len = 1; len <= n; ++len) {
		for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
			l = i, r = j;
			cout << "l = " << i << ", " << "r = " << r;
			cout << ": " << solve () << endl;
		}
	}*/
}

vector <ll> arr_d1 (N), arr_d2 (N), arr_d3 (N);
vector <ll> fiEle (N), add_d (N);

void get () {
	for (int i = 1; i < N; ++i)
	arr_d1[i] = arr_d1[i - 1] + i;
	arr_d2[1] = 1;
	for (int i = 2; i < N; ++i)
	arr_d2[i] = arr_d2[i - 1] + arr_d1[i];
	for (int i = 2; i < N; ++i)
	fiEle[i] = fiEle[i - 1] + arr_d2[i - 1];
	add_d[2] = 2;
	for (int i = 3, remain = 6, add = 6; i < N; ++i) {
		add_d[i] = add_d[i - 1] + remain;
		remain += add;
		add += 2;
	}
	for (int i = 1; i < N; ++i)
	arr_d3[i] = arr_d3[i - 1] + arr_d2[i];
	/*for (int i = 2; i <= 5; ++i)
	cout << arr_d1[i] << " \n"[i == 5];
	for (int i = 2; i <= 5; ++i)
	cout << arr_d2[i] << " \n"[i == 5];
	for (int i = 2; i <= 5; ++i)
	cout << fiEle[i] << " \n"[i == 5];
	for (int i = 2; i <= 5; ++i)
	cout << add_d[i] << " \n"[i == 5];*/
}
	
void charming (int cnt) {
	init ();
	cin >> l >> r;
	ll res = 0;
	if (r == l) res = 0;
	else {
		res = fiEle[r - l + 1] + add_d[r - l + 1] * (l - 1);
		if (l - 1 >=  r - l - 1) res -= arr_d3[r - l - 1];
		else res = res - arr_d3[r - l - 1] + arr_d3[r - 2 * l];
	}
	cout << "Case #" << cnt << ": " << res << endl;
}
signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	get ();
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i); //test ();
	return 0;
}