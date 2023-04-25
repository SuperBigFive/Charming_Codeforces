#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, k;

void init () {}

void charming () {
	init ();
	cin>> n >> m >> k;
	int last = LLONG_MAX, head = 1, tail = 0, p = 0;
	vector <int> box (N), branch, give (n);
	vector <vector <int> > ans;
	for (auto &it : give) cin >> it;
	
	auto finish = [&] () -> void {
		ans.emplace_back (branch);
		last = LLONG_MAX;
		branch.clear ();
	};
	
	while (p < n) {
		if (head <= tail && box[tail] <= last) {
			branch.emplace_back (box[tail]);
			last = box[tail--];
			if (branch.size () >= k) finish ();
		}
		else if (give[p] <= last) {
			branch.emplace_back (give[p]);
			last = give[p++];
			if (branch.size () >= k) finish ();
		}
		else {
			if (tail - head + 1 >= m) finish ();
			else box[++tail] = give[p++];
		}
	}
	while (head <= tail) {
		if (box[tail] <= last) {
			branch.emplace_back (box[tail]);		
			last = box[tail--];
			if (branch.size () >= k) finish ();
		}
		else finish ();
	}
	if (branch.size () > 0) ans.emplace_back (branch);
	for (auto b : ans) {
		int siz = b.size ();
		for (int i = 0; i < siz; ++i)
		cout << b[i] << " \n"[i == siz - 1];
	}
}

signed main () {
	charming ();
	return 0;
}