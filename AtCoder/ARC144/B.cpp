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
const int maxn = 3e5 + 5;

int n, a, b;
int arr[maxn], tmp[maxn];

bool check (int num) {
	memcpy (tmp, arr, sizeof arr);
	int p_low = 1, p_high = 1, tmp_diff1, tmp_diff2;
	while (p_low <= n && p_high <= n) {
		while (tmp[p_low] >= num && p_low <= n) ++p_low;
		while (tmp[p_low] < num && p_high <= n) {
			if (tmp[p_high] >= num) {
				tmp_diff1 = (tmp[p_high] - num) / b;
				tmp_diff2 = (num - tmp[p_low] - 1) / a + 1;
				if (tmp_diff1 <= tmp_diff2) {
					tmp[p_low] += tmp_diff1 * a;
					tmp[p_high] -= b * tmp_diff1;
					++p_high;
				}
				else {
					tmp[p_low] += tmp_diff2 * a;
					tmp[p_high] -= b * tmp_diff2;
				}
			}
			else ++p_high;
		}
	}
	while (tmp[p_low] >= num && p_low <= n) ++p_low;
	return p_low > n;
}

void charming () {
	cin >> n >> a >> b;
	int l = INT_MAX, r = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (l > arr[i]) l = arr[i];
		if (r < arr[i]) r = arr[i];
	}
	int mid;
	while (l < r - 1) {
		mid = (l + r) / 2;
		if (check (mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;
}

signed main () {
	charming ();
	return 0;
}