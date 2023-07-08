#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e6 + 15;

int t, n;
int arr[maxn];
int fb[maxn], fs[maxn];
stack <int> stb, stb_idx, sts, sts_idx;

void build_f () {
	for (int i = 1; i <= n; ++i) {
		while (!stb.empty () && stb.top () < arr[i]) {
			stb.pop ();
			fb[stb_idx.top ()] = i;
			stb_idx.pop (); 
		}
		stb.push (arr[i]);
		stb_idx.push (i);
		while (!sts.empty () && sts.top () > arr[i]) {
			sts.pop ();
			fs[sts_idx.top ()] = i;
			sts_idx.pop ();
		}
		sts.push (arr[i]);
		sts_idx.push (i);
	}
	while (!stb.empty ()) {
		fb[stb_idx.top ()] = n;
		stb.pop ();
		stb_idx.pop ();
	}
	while (!sts.empty ()) {
		fs[sts_idx.top ()] = n;
		sts.pop ();
		sts_idx.pop ();
	}
}

void charming () {
	cin >> n;
	for (int i = 1; i <= n; ++i) scanf ("%d", &arr[i]);
	if (n == 1) {
		cout << "0" << endl;
		return;
	}
	build_f ();
	int ans = 0, now = 1;
	int mmax, mmin;
	int ub, start;
	while (now != n) {
		++ans;
		int last = now;
		mmax = max (arr[last], arr[last+1]), mmin = min (arr[last], arr[last+1]);
		if (arr[last] < arr[last+1]) ub = fs[last], start = fb[last+1];
		else ub = fb[last], start = fs[last+1];
		for (int i = start; i <= ub; ++i) {
			mmax = max (mmax, arr[i]);
			mmin = min (mmin, arr[i]);
			if ((mmax == arr[last] && mmin == arr[i]) || ((mmax == arr[i] && mmin == arr[last]))) {
				now = i;
			}
			if ((mmax != arr[last] && mmin != arr[last])) break;
		}
		now = max (last + 1, now);
	}
	cout << ans << endl;
}

int main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
