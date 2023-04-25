#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, k, siz;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	int sum = 0;
	vector <int> ox;
	vector <array <int, 3> > seq (n);
	for (auto &it : seq) {
		cin >> it[0] >> it[1]	>> it[2];
		ox.emplace_back (it[0]);
		ox.emplace_back (it[1]);
		sum += it[2];
	}
	sort (ox.begin (), ox.end ());
	ox.resize (unique (ox.begin (), ox.end ()) - ox.begin ());
	siz = ox.size ();
	for (auto &it : seq) {
		for (int i = 0; i < 2; ++i)
		it[i] = lower_bound (ox.begin (), ox.end (), it[i]) - ox.begin () + 1;
	}
	sort (seq.begin (), seq.end (), [] (array <int, 3> &x,
	array <int, 3> &y) {return x[1] < y[1];});
	int p = -1, sumk;
	vector <ll> dp (siz + 5);
	vector <vector <array <int, 3> > > be (siz + 5);
	priority_queue <int, vector <int>, greater <int> > pq;
	auto Insert = [&] (int val) -> void {
		if (pq.size () < k) {
			pq.push (val);
			sumk += val;
		} else if (pq.top () < val) {
			sumk -= pq.top ();
			pq.pop ();
			pq.push (val);
			sumk += val;
		}
	};
	for (int i = 1; i <= siz; ++i) {
		while (p + 1 < seq.size () && seq[p + 1][1] <= i) {
			be[seq[++p][0]].emplace_back (seq[p]);
		}
		sumk = 0;
		while (!pq.empty ()) pq.pop ();
		for (int j = i; j >= 1; --j) {
			for (auto it : be[j]) {
				Insert (it[2]);
			}
			dp[i] = max (dp[i], dp[j - 1] + sumk);
		}
	}
	cout << sum - dp[siz] << endl;
}

signed main () {
	charming ();
	return 0;
}