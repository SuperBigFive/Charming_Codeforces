#include <bits/stdc++.h>
#define ll long long
#define vi vector <int> 
#define pii pair <int, int> 
#define pb push_back
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 5e5 + 5;

int n, mx = -1, p = 0;
bool ok = false;
map <int, int> num;

int read () {
	int x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar ();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar ();
	}
	return x * f;
}

inl bool add (int pos) {
	if (!num[pos]) {
		++num[pos];
		mx = max (mx, pos);
	}
	else {
		int tmp = pos;
		while (num[tmp] && tmp > 0) --tmp;
		if (!tmp) {
			if (mx != pos) return false; 
			ok = true;
		}
		tmp = pos;
		while (num[pos] && pos > 0) num[pos] = 0, --pos;
		num[pos] = 1;
		if (mx == tmp) mx = pos;
	}
	return true;
}

void charming () {
	n = read ();
	int pos;
	for (int i = 1; i <= n; ++i) {
		pos = read ();
		if (ok) {
			puts ("No");
			continue;
		}
		if (!num[pos]) {
			++num[pos];
			if (p == pos - 1) {
				++p;
				while (num[p]) ++p;
				--p;
			}
			mx = max (mx, pos);
			puts ("Yes");
		}
		else {
			if (pos <= p) {
				if (pos == p && pos == mx) {
					puts ("Yes");
					ok = true;
					continue;
				}
				puts ("No");
				continue;
			}
			int tmp = pos;
			while (num[pos] && pos > 0) num[pos] = 0, --pos;
			num[pos] = 1;
			if (p == pos - 1) {
				++p;
				while (num[p]) ++p;
				--p;
			}
			if (mx == tmp) mx = pos;
			puts ("Yes");
		}
	}
}

signed main () {
	charming ();
	return 0;
}