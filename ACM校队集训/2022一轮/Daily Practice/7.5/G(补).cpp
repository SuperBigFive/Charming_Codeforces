#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;
template <typename T> void read(T & x){
	x = 0;
	ll f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar ()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar ()) x = x * 10 + ch - '0';
	x *= f;
}

int n, m;
ll arr[maxn];

void charming () {
	read (n), read (m);
	for (int i = 1; i <= n; ++i) read (arr[i]);
	if (n > m) {
		cout << "0" << endl;
		return;
	}
	ll ans = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans = (ans * (abs (arr[i] - arr[j]) % m)) % m;
		}
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
}
