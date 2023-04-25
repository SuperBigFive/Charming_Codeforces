#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int t, n, k, now, tot1, tot2;
int i, j;
int tmp, a, used;
bool flag;
int num[maxn];
int nnum[maxn];
int arr[maxn], b[maxn], next[maxn], mex_k[maxn];

void init () {
	now = used = tot1 = tot2 = a = 0;
	flag = false;
}

void check () {}

void solve () {
	cin >> n >> k;
	init ();
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	sort (arr + 1, arr + 1 + n);
	int tmp;
	i = 1;
	if (arr[1] != 0) {
		tmp = 0;
		while (tmp < arr[1]) {
			nnum[tot2++] = tmp;
		}
		flag = true;
	}
	for (i = 2; i <= n && tot2 <= k; ++i) {
		if (arr[i] - arr[i-1] > 1) {
			tmp = arr[i-1] + 1;
			while (tmp < arr[i]) {
				nnum[tot2++] = tmp; 
				++ tmp;
			}
			flag = true;
		}
	}
	if (!flag) nnum[k] = arr[n] + 1;
	int up = lower_bound (arr + 1, arr + 1 + n, nnum[k]) - arr - 1;
	for (i = 1; i <= n; ++i) {
		j = i;
		while (arr[j+1] == arr[i]) ++j;
		if (i >= up) ++num[j-i+1];
		i = j;
		++tot1;
	}
	j = 1;
	while (used < k) {
		if (k - used >= num[j]) {
			tot1 -= num[j];
			++j;
			used += num[j];
			continue;
		}
		else {
			tot1 -= (k - used)/j;
			break;
		}
	} 
	if (tot1 - nnum[k] < 0) cout << 0 << endl;
	else cout << tot1 - nnum[k] << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) solve ();
}
