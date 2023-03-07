#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int t;
ll n, x;
int ans = 99999999;
bool flag, flag1;
void init () {
	flag1 = false;
	flag = false;
}


int get_digit (ll num, int (&arr)[20]) {
	int tot = 0;
	while (num) {
		arr[++tot] = num % 10;
		num /= 10;
	}
	return tot;
}

void dfs (ll xx, int oper) {
	if (flag) return;
	int arr[20];
	int tot = get_digit (xx, arr);
    if(n -   tot + 1 >  ans-oper) return;
	if (tot == n) {
		flag1 = true;
		ans = min (ans, oper);
		return;
	}
	if (tot > n || oper > ans) return;
	sort (arr + 1, arr + 1 + tot);
	int tmp[20], mmax = -1,max_idx;
	int tot1;
	for (int i = tot; i >= 1; --i) {
		if(arr[i] == 1) break;
		if(arr[i] == arr[i-1] && i != tot) continue;
		dfs(xx*arr[i], oper+1);
    }
	if (flag) return;
}
void solve () {
	cin >> n >> x;
	init ();
	dfs (x, 0);
	//t = clock ();
	if (!flag1) cout << -1 << endl;
	else cout << ans << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	solve ();
}
