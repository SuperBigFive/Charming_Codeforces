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
const int maxn = 5e6 + 5;

int n, q;
ll high;
ll arr[maxn], cnt[maxn];
ll digit[maxn];
vector <ll> v;

void init () {
	
}

void diff (ll num) {
	int now = num;
	if (digit[now]) {
		digit[now] = 0;
		if (now == high) {
			int j = now;
			while (!digit[j] && j >= 1) --j;
			high = j;
		}
		return;
	}
	while (!digit[now]) {
		digit[now] = 1;
		++now;
	}
	digit[now] = 0;
	digit[num] = 1;
	if (now == high) --high;
}

void add (ll num) {
	int now = num;
	if (!digit[now]) {
		digit[now] = 1;
		if (now > high) high = now;
		return;
	}
	while (digit[now]) {
		digit[now] = 0;
		++now;
	}
	digit[now] = 1;
	if (now > high) high = now;
}

ll get_digit () {
	return high;
}

void charming () {
	init ();
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	
	for (int i = 1; i <= n; ++i) {
		++cnt[arr[i]];
	}
	ll carry = 0;
	for (int i = 1; i <= 1e6; ++i) {
		cnt[i] += carry;
		carry = cnt[i] / 2;
		digit[i] = cnt[i] % 2;
		if (digit[i]) high = i;
	}
	ll k, l;
	for (int i = 1; i <= q; ++i) {
		cin >> k >> l;
		diff (arr[k]);
		add (l);
		arr[k] = l;
		cout << high << endl;
	}
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}