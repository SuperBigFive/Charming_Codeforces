#include <bits/stdc++.h>
#define ll __int128
using namespace std;
const int maxn = 1e6 + 5;
const ll g = 42;

int n;

ll slow_mul (ll pow, ll num, ll mod) {
	ll res = 0;
	num = num % mod;
	while (pow) {
		if (pow & 1) res = (res + num) % mod;
		pow >>= 1;
		num = (num + num) % mod; 
	}
	return res;
}

ll binpow (ll pow, ll num, ll mod) {
	ll res = 1;
	while (pow) {
		if (pow & 1) res = res * num % mod;
		pow >>= 1;
		num = num * num % mod;
	}
	return res % mod;
}


void print(__int128 x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);//注意这里是x>9不是x>10 (2019.10 wa哭了回来标记一下)
    putchar(x%10+'0');
}

void charming () {
	int n;
	cin >> n;
	ll ans;
	int start;
	if (n < 114514) ans = 439843862690187971, start = 114514;
	else if (n < 300300) ans = 263358264583736303, start = 300300;
	else ans = 300, start = 1000000;
	ll M = 1000000000000000031;
	for (int i = start; i > n; --i) {
		ans = binpow (ans, g, M);
	}
	//printf ("%ld", ans);
	print (ans);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
}
