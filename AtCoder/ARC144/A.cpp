#include <bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 1e6 + 5;

int n;
int res[maxn];

void charming () {
	cin >> n;
	cout << 2 * n << endl;
	int tot = 0;
	while (n > 4) {
		res[++tot] = 4;
		n -= 4;
	}
	res[++tot] = n;
	for (int i = tot; i >= 1; --i)
	if (res[i])	cout << res[i];
	cout << endl;
}

signed main () {
	charming ();
	return 0;
}