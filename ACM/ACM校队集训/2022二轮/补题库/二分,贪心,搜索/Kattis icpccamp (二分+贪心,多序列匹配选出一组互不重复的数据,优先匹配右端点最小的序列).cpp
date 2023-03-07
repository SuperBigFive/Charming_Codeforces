#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n, p, q, s;
int pro1[maxn], pro2[maxn];
struct cmp {
	bool operator () (const pii &x, pii &y) const {
		if (x.fi == y.fi) return x.se > y.se;
		return x.fi < y.fi;
	}
};
queue <pii > pq_all;
priority_queue <pii, vector <pii > , cmp> pq_now;


void init () {
	
}

bool check (int d) {
	while (!pq_all.empty ()) pq_all.pop ();
	while (!pq_now.empty ()) pq_now.pop ();
	int id_min, id_max;
	for (int i = 1; i <= p && pro1[i] <= s; ++i) {
		id_min = lower_bound (pro2 + 1, pro2 + 1 + q, pro1[i] - d) - pro2;
		id_max = upper_bound (pro2 + 1, pro2 + 1 + q, min (pro1[i] + d, s - pro1[i])) - pro2 - 1;
		if (id_min <= id_max) pq_all.push ({pro2[id_min], pro2[id_max]});
	}
	int res = 0;
	for (int i = 1; i <= q; ++i) {
		while (!pq_all.empty () && pq_all.front ().fi <= pro2[i]) {
			pq_now.push (pq_all.front ());
			pq_all.pop ();
		}
		while (!pq_now.empty ()) {
			int tmp = pq_now.top ().se;
			pq_now.pop ();
			if (tmp < pro2[i]) {
				continue;
			}
			++res;
			break;
		}
		if (res >= n) return true;
	}
	return res >= n;
}

void charming () {
	cin >> n >> p >> q >> s;
	for (int i = 1; i <= p; ++i) {
		cin >> pro1[i];
	}
	for (int i = 1;  i <= q; ++i) {
		cin >> pro2[i];
	}
	sort (pro1 + 1, pro1 + 1 + p);
	sort (pro2 + 1, pro2 + 1 + q);
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check (mid)) r = mid;
		else l = mid + 1;
	}
	if (check (r)) cout << r << endl;
	else cout << -1 << endl;
}

signed main () {
	charming ();
	return 0;
}