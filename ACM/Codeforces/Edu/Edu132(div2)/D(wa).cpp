#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 5e5 + 5;

struct Node{
	int r,l;
	ll mmax;
	ll lazy_max;
}node[maxn << 2];

ll n, m, q, high, tot;
ll a[maxn], nl[maxn << 1], nr[maxn << 1];

void build (int l,int r, int cnt){
	node[cnt].r = r;
	node[cnt].l = l;
	if(r==l) {
		node[cnt].mmax = a[l];
		return;
	}
	int mid = (l + r) / 2;
	if (!nl[cnt]) nl[cnt] = ++tot;
	build (l, mid, nl[cnt]);
	if (!nr[cnt]) nr[cnt] = ++tot;
	build (mid + 1, r, nr[cnt]);
	node[cnt].mmax = max (node[nl[cnt]].mmax, node[nr[cnt]].mmax);
}

void find_max (int cnt, int l, int r){
	if(node[cnt].l>=l && node[cnt].r <=r){
		high = max (high, node[cnt].mmax);
		return;
	}
	int mid = (node[cnt].l + node[cnt].r)/2;
	if(l <= mid) find_max (nl[cnt], l, r);
	if(r > mid) find_max (nr[cnt], l, r); 
}


void charming () {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	build (1, m, 0);
	cin >> q;
	ll x1, y1, x2, y2, k;
	ll step1, step2, step3;
	for (int i = 1; i <= q; ++i) {
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		high = step1 = step2 = step3 = -1;
		find_max (0, min (y1, y2), max (y1, y2));
		if (high >= n) {
			cout << "NO" << endl;
			continue;
		}
		if (high < max (x1, x2)) {
			step1 = max (y2, y1) - min (y2, y1);
			step2 = max (x2, x1) - min (x2, x1);
			//road = max (x1, x2) - min (x1, x2) + max (y1, y2) - min (y1, y2);
		}
		else {
			step1 = high - x1 + 1;
			step2 = max (y2, y1) - min (y2, y1);
			step3 = high - x2 + 1;
			//road = 2 * (high + 1) - x1 - x2 + max (y1, y2) - min (y1, y2);
		}
		if ((!(step1 % k)) && (!(step2 % k))) {
			if (step3 != -1) {
				if (step3 % k) {
					cout << "NO" << endl;
					continue;
				}
				else {
					cout << "YES" << endl;
					continue;
				}
			}
			else cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}

signed main () {
	charming ();
	return 0;
}
