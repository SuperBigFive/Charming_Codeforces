#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 5e4 + 5;

int n, start, x;

void ask (int num) {
	cout << "? " << num << endl;
	fflush (stdout);
}

void ans (int num) {
	cout << "! " << num << endl;
	fflush (stdout);
	exit (0);
}

void charming () {
	cin >> n >> start >> x;
	int val = -1, id = -1, tot = 0, tmp = rand ();
	int tmp_val, tmp_id;
	while (tot < 1000) {
		tmp = tmp * rand () % n + 1;
		ask (tmp);
		cin >> tmp_val >> tmp_id;
		if (tmp_val == x) ans (x);
		if (tmp_val < x) {
			if (tmp_val > val) {
				val = tmp_val;
				id = tmp_id;
			}
		}
		++tot;
	}
	if (id == -1) id = start;
	while (tot < 1999) {
		ask (id);
		cin >> tmp_val >> tmp_id;
		if (tmp_val >= x) ans (tmp_val);
		if (tmp_id == -1) ans (-1);
		id = tmp_id;
		++tot;
	}
	ans (-1);
}

signed main () {
	charming ();
	return 0;
}