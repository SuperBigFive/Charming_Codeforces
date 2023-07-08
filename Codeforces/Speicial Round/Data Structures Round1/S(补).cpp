#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = sqrt (N);

int n, m;
int tag[N], be[N], ans[N];
int c[M][M];
pair <int, int> xy[N];

void init () {}

void block_update (int id, int cur, int val) {
	int period = xy[id].first + xy[id].second;
	int l = (cur + xy[id].first) % period, r = (cur - 1) % period;
	if (l <= r) for (int i = l; i <= r; ++i) c[period][i] += val;
	else {
		for (int i = 0; i <= r; ++i) c[period][i] += val;
		for (int i = l; i < period; ++i) c[period][i] += val;
	}
}

int block_query (int cur) {
	int res = 0;
	for (int i = 2; i < M; ++i)
	res += c[i][cur % i];
	return res;
}

void charming () {
	init ();
	scanf ("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf ("%d%d", &xy[i].first, &xy[i].second);
	}
	for (int i = 1, opt, k, period; i <= m; ++i) {
		scanf ("%d %d", &opt, &k);
		period = xy[k].first + xy[k].second;
		if (opt == 1) {
			if (period >= M) {
				for (int j = i + xy[k].first; j <= m; j += period) {
					++tag[j], --tag[min (m + 1, j + xy[k].second)];
				}
			}
			else block_update (k, i, 1);
			be[k] = i;
		}
		else {
			if (period >= M) {
				for (int j = be[k] + xy[k].first; j <= m; j += period) {
					if (j <= i && j + xy[k].second > i) {
						--tag[i], ++tag[min (m + 1, j + xy[k].second)];
					}
					else if (j > i) --tag[j], ++tag[min (m + 1, j + xy[k].second)];
				}
			}
			else block_update (k, be[k], -1);
		}
		ans[i] = block_query (i);
	}
	for (int i = 1, remain = 0; i <= m; ++i) {
		remain += tag[i];
		printf ("%d\n", remain + ans[i]);
	}
}

signed main () {
	charming ();
	return 0;
}