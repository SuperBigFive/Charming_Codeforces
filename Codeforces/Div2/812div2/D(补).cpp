#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;
const int zero = 0;

int t, n, tot;
int flag;
int now_q[maxn], nxt_q[maxn];

void ask (int a, int b) {
	printf ("? %lld %lld\n", a, b);
	fflush (stdout);
}

void ans (int pos) {
	printf ("! %lld\n", pos);
	fflush (stdout);
}

void init () {
	
}

ll get_max (int l, int r) {
	ask (l, l + 2);
	scanf ("%lld", &flag);
	if (flag == 0) {
		ask (l + 1, l + 3);
		scanf ("%lld", &flag);
		if (flag == 1) return l + 1;
		else return l + 3;
	}
	else if (flag == 1) {
		ask (l, l + 3);
		scanf ("%lld", &flag);
		if (flag == 1) return l;
		else return l + 3;
	}
	else {
		ask (l + 1, l + 2);
		scanf ("%lld", &flag);
		if (flag == 1) return l + 1;
		else return l + 2;
	}
}

void charming () {
	scanf ("%lld", &n);
	for (int i = 1; i <= (1 << n); ++i) {
		now_q[i] = i;
	}
	while (n) {
		if (n == 1) {
			ask (now_q[1], now_q[2]);
			scanf ("%lld", &flag);
			if (flag == 2) now_q[1] = now_q[2];
			break;
		}
		tot = 0;
		for (int i = 1; i < (1 << n); i += 4) {
			ask (now_q[i], now_q[i + 3]);
			scanf ("%lld", &flag);
			if (flag == 0) {
				ask (now_q[i + 1], now_q[i + 2]);
				scanf ("%lld", &flag);
				if (flag == 1) nxt_q[++tot] = now_q[i + 1];
				else nxt_q[++tot] = now_q[i + 2];
			}
			else if (flag == 1) {
				ask (now_q[i], now_q[i + 2]);
				scanf ("%lld", &flag);
				if (flag == 1) nxt_q[++tot] = now_q[i];
				else nxt_q[++tot] = now_q[i + 2];
			}
			else {
				ask (now_q[i + 1], now_q[i + 3]);
				scanf ("%lld", &flag);
				if (flag == 1) nxt_q[++tot] = now_q[i + 1];
				else nxt_q[++tot] = now_q[i + 3];
			}
		}
		n -= 2;
		for (int i = 1; i <= tot; ++i) now_q[i] = nxt_q[i];
	}
	ans (now_q[1]);
}

signed main () {
	scanf ("%lld", &t);
	while (t--) charming ();
	return 0;
}