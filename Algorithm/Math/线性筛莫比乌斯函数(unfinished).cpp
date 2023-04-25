#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 1e3 + 5;

int mu[maxn], prime[maxn];
bool vis[maxn];

void get_mu () {
	mu[1] = 1;
	int tot = 0;
	for (int i = 2; i < maxn; ++i) {
		if (!vis[i]) mu[i] = -1, prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] < maxn; ++j) {
			vis[i * prime[j]] = true;
			if (!(i % prime[j])) break;
			mu[i * prime[j]] = -mu[i];
		}
	}
}

void charming () {
	get_mu ();
	for (int i = 1; i < maxn; ++i) {
		cout << mu[i] << ' ';
	}
}

signed main () {
	charming ();
	return 0;
}