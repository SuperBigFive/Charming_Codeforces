#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e7 + 5;

int n;

vector <int> Get_prime () {
	vector <int> vis (N), prime;
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prime.emplace_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < N; ++j) {
			vis[i * prime[j]] = true;
			if ((i % prime[j]) == 0) break;
		}
	}
	return prime;
}

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	for (auto &ai : a) cin >> ai;
	vector <int> prime = Get_prime ();
	int siz = prime.size ();
	vector <int> vis (N);
	int p = 0;
	vector <int> ans;
	while (p < n) {
		bool flag = false;
		int tmp = a[p];
		vector <int> a_prime;
		for (int i = 0; i < siz && prime[i] * prime[i] <= tmp; ++i) {
			if ((tmp % prime[i]) == 0) {
				flag |= vis[prime[i]];
				a_prime.emplace_back (prime[i]);
				while ((tmp % prime[i]) == 0) tmp /= prime[i];
			}
		}
		if (tmp > 1) flag |= vis[tmp], a_prime.emplace_back (tmp);
		if (flag) break;
		else {
			ans.emplace_back (a[p++]);
			for (int i : a_prime) vis[i] = 1;
		}
	}
	
	auto Check = [&] (int num) -> bool {
		vector <int> num_prime;
		for (int i = 0; i < siz && prime[i] * prime[i] <= num; ++i) {
			if ((num % prime[i]) == 0) {
				if (vis[prime[i]]) return false;
				num_prime.emplace_back (prime[i]);
				while ((num % prime[i]) == 0) num /= prime[i];
			}
		}
		if (num > 1 && vis[num]) return false;
		else {
			if (num > 1) num_prime.emplace_back (num);
			for (int i : num_prime) vis[i] = 1;
			return true;
		}
	};
	
	if (p < n) {
		int target = a[p];
		int nans = target + 1;
		while (!Check (nans)) ++nans;
		ans.emplace_back (nans);
	}
	
	p = 0;
	while ((int) ans.size () < n) {
		while (vis[prime[p]]) ++p;
		ans.emplace_back (prime[p++]);
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}

signed main () {
	charming ();
	return 0;
}