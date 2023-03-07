#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n, x;
int h1[maxn], h2[maxn];

void charming () {
	cin >> n >> x;
	for (int i = 1; i <= 2 * n; ++i) cin >> h1[i];
	sort (h1 + 1, h1 + 1 + 2 * n);
	for (int i = 1; i <= n; ++i) {
		if (h1[i] + x > h1[i + n]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}