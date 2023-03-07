#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

ll t, k, l, r;

void init () {}

void charming (int cnt) {
	init ();
	cin >> k >> l >> r;
	ll sum = 0, siz;
	vector <ll> dl, dr, wet, dmx, dmn;
	vector <ll> pre;
	ll tmp_r = r, tmp_l = l;
	while (tmp_r) {	
		dr.emplace_back (tmp_r % k);
		tmp_r /= k;
		sum += dr.back ();
		pre.emplace_back ((pre.size () > 0 ? pre.back () : 0) + dr.back ());
	}
	sum += (siz = dr.size ()) - 2;
	while (tmp_l) {
		dl.emplace_back (tmp_l % k);
		tmp_l /= k;
	}
	while (dl.size () < dr.size ())
	dl.emplace_back (0);
	wet.emplace_back (1);
	while (wet.size () < dr.size ())
	wet.emplace_back (k * wet.back ());
	cout << "Case #" << cnt << ": ";
	ll mx = -1;
	pair <int, int> ans;
	bool ok = false;
	for (int i = dr.size () - 1, nmx; i > 0; --i) if ((ok |= (dr[i] > dl[i])) && dr[i]) {
		nmx = pre[siz - 1] - pre[i - 1] - 1 + i * (k - 1) 
		+ (siz - 1) - (i == dr.size () - 1 && dr[i] == 1) - 1;
		if (nmx < mx) continue;
		else if (nmx == mx) ans.first = i;
		else mx = nmx, ans = make_pair (i, i);
	}
	if (mx >= sum) {
		dmx = dr; --dmx[ans.first];
		dmn = dr; --dmn[ans.second];
		for (int i = ans.first - 1; i >= 0; --i) dmx[i] = k - 1;
		for (int i = ans.second - 1; i >= 0; --i) dmn[i] = k - 1;
		ll val_mx = 0, val_mn = 0;
		for (int i = 0; i < siz; ++i) 
		val_mx += wet[i] * dmx[i], val_mn += wet[i] * dmn[i];
		if (mx == sum) cout << mx << " " << val_mn << " " << r << endl;
		else cout << mx << " " << val_mn << " " << val_mx << endl;
	}
	else cout << sum << " " << r << " " << r << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}