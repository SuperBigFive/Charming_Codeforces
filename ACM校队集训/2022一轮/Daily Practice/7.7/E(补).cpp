#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 15;

ll n;
ll arr[maxn], b[maxn], temp[maxn], arr_deal[maxn], sum[maxn];
vector <ll> pos[maxn];

void output (__int128 x){
    if (x < 0) putchar ('-'), x = -x;
    if (x > 9) output (x / 10);
    putchar (x % 10 + '0');
	cout << endl;
}

void charming () {
	cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i],temp[i] = arr[i], b[i] = arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    sort (arr + 1, arr + 1 + n);
    sort (b + 1, b + 1 + n);
    ll len = unique (arr + 1, arr + 1 + n) - arr - 1;
    for (int i = 1; i <= n;++i) {
    	arr_deal[i] = lower_bound (arr + 1, arr + 1 + len, temp[i]) - arr;
    	pos[arr_deal[i]].push_back (i);
	}
    long double ans = 0;
	ll pre, nxt;
    for (int i = 1; i <= n; ++i) {
    	ans += 0 - sum[i] - (n - i) * temp[i] + sum[n];
    	pre = lower_bound (b + 1, b + 1 + n, temp[i] - 1) - b;
    	nxt = lower_bound (b + 1, b + 1 + n, temp[i] + 1) - b;
    	if (b[pre] == temp[i] - 1) {
    		ans += pos[arr_deal[i] - 1].size () - (lower_bound (pos[arr_deal[i] - 1].begin (), pos[arr_deal[i] - 1].end (), (ll)i) - pos[arr_deal[i] - 1].begin ());
		}
		if (b[nxt] == temp[i] + 1) {
			ans -= pos[arr_deal[i] + 1].size () - (lower_bound (pos[arr_deal[i] + 1].begin (), pos[arr_deal[i] + 1].end (), (ll)i) - pos[arr_deal[i] + 1].begin ());
		}
	}
	output (ans); 
}

int main(){
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
    return 0;
}
