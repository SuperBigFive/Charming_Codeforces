#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
int p[maxn];
int tag1[maxn << 1], tag2[maxn << 1];
int tag3[maxn << 1], tag4[maxn << 1];
int ans1[maxn << 1], ans2[maxn << 1], ans[maxn << 1];

void init () {}

void charming () {
	cin >> n;
	int be1, be2, en1, en2;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		be1 = i > p[i] ? n - i + p[i] : p[i] - i;
		en1 = be1 + (n >> 1);
		++tag1[be1 + 1];
		--tag1[en1 + 1];
		tag3[en1 + 1] += -(en1 - be1);
		be2 = en1 + ((n + 1) >> 1);
		en2 = en1 + 1;
		++tag2[be2 - 1];
		--tag2[en2 - 1];
		tag4[en2 - 1] += -(be2 - en2);
	}
	for (int i = 0, cnt = 0; i < (n << 1); ++i) {
		cnt += tag1[i];
		ans1[i] = ans1[i - 1] + cnt + tag3[i];
	}
	for (int i = (n << 1) - 1, cnt = 0; i >= 0; --i) {
		cnt += tag2[i];
		ans2[i] = ans2[i + 1] + cnt + tag4[i];
	}
	int res = LLONG_MAX;
	for (int i = 0; i < n; ++i) {
		ans[i] = ans1[i] + ans1[i + n] + ans2[i] + ans2[i + n];
		res = min (res, ans[i]);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}