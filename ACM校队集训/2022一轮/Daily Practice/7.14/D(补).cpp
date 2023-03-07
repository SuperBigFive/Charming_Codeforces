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
const int maxn = 1e5 + 5;

ll n, tot = 1;
char res[maxn];


void dfs (int now, int cnt0, int cnt1, int state) {
	if (cnt0 > (n + 2) / 2 || cnt1 > (n + 2) / 2 || tot > 100) return;
	if (now >= n) {
		printf ("%s\n", res);
		++tot;
		return;
	}
	res[now] = 'b';
	dfs (now + 1, cnt0 + (state ^ 1), cnt1 + state, state);
	res[now] = 'r';
	state ^= 1;
	dfs (now + 1, cnt0 + (state ^ 1), cnt1 + state, state);
}

void charming () {
	cin >> n;
	ll ans = (n + 1) / 2 * ((n + 2) / 2);
	cout << ans << endl;
	dfs (0, 1, 0, 0);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}