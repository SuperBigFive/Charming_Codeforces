#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
#define pi  3.1415926
using namespace std;
const int maxn = 1e6 + 5;

int tt, k;
int mu[maxn];
ll prime[maxn], sum_mu[maxn];
bool vis[maxn];

void init () {
	
}

ll get_sum (int n) {
	return sum_mu[n];
}

void get_mu () {
	mu[1] = 1;
	int tot = 0;
	for (int i = 2; i < maxn; ++i) {
		if (!vis[i]) mu[i] = -1, prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] < maxn; ++j) {
			vis[i * prime[j]] = true;
			if (!(i % prime[j])) break;
			mu[i * prime[j]] = -mu[i];
		}
	}
	sum_mu[0] = 0;
	for (int i = 1; i < maxn; ++i) {
		sum_mu[i] = sum_mu[i - 1] + mu[i];
	}
}

ll get_res (int n, int m) {
	ll res = 0;
	int i, j, j1, j2, tmp;
	for (i = 1; i <= min (n, m); i = j + 1) {
		tmp = n / i;
		j1 = n / tmp;
		tmp = m / i;
		j2 = m / tmp;
		j = min (j1, j2);
		res += (get_sum (j) - get_sum (i - 1)) * (n / i) * (m / i);
	}
	return res;
}

ll get_ans (int a, int b, int c, int d, int r) {
	ll ans = 0;
	ans += get_res (b, d);
	ans -= get_res (a - 1, d) + get_res (b, c - 1);
	ans += get_res (a - 1, c - 1);
	return ans;
}


void charming (int tot) {
	init ();
	int a, b, c, d;
	scanf ("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);
	if (!k) {
		printf("Case %lld: 0\n", tot);
		return;
	}
	a /= k, b /= k, c /= k, d /= k;
	ll ans, t;
	ans = get_ans (a, b, c, d, 1);
	if(a + b > c + d){
    swap(a,c);
    swap(b,d);
  }
  if(b >c && d >= b && c >= a){
    if(k < c || k > b){
      t = get_ans(c,b,c,b,k);
      ans = ans - t / 2;
    }
    else
    {
        t= get_ans(c,b,c,b,k)-1;
        ans=ans-t/2;
    }
  }
  if(b>c && b>d && c>=a)
  {
      if(k<c || k>d)
      {
          t=get_ans(c,d,c,d,k);
          ans=ans-t/2;
      }
      else
      {
          t=get_ans(c,d,c,d,k)-1;
          ans=ans-t/2;
      }
  }
  if(b>c && a>c && d>=b)
  {
      if(k<a || k>b)
      {
          t=get_ans(a,b,a,b,k);
          ans=ans-t/2;
      }
      else
      {
          t=get_ans(a,b,a,b,k)-1;
          ans=ans-t/2;
      }
  }
  printf("Case %lld: %lld\n", tot, ans);
}

signed main () {
	get_mu ();
	scanf ("%lld", &tt);
	int tmp_t = tt;
	while (tt--) charming (tmp_t - tt);
	return 0;
}