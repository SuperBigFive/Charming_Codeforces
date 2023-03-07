#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;

namespace math{
	/*—————gcd && lcm——————*/ 
	ll gcd (ll x, ll y) {
		return y ? gcd (y, x % y) : x;
	}
	
	ll lcm (ll x, ll y) {
		return x / gcd (x, y) * y;
	}
	//————————————————//
	
	/*——————Slow_mul——————
		防止取模运算时 
		就算开 ll 也会溢出的情况*/
	ll Slow_mul (ll x, ll k, ll mod) {
		ll res = 0;
		while (k) {
			if (k & 1) res = (res + x) % mod;
			k >>= 1;
			x = (x + x) % mod; 
		}
		return res;
	}
	//————————————————//
	
	/*———ex_gcd &线性同余方程———
		【线性同余方程】 
		a*x = c mod b <=> a*x + b*y = c
		前置条件：c能够整除 gcd (a, b)
		由贝祖定理：a*x + b*y = gcd (a, b)
		c整除 gcd (a, b)
		相当于上式同时乘以一个整数*/
	ll ex_gcd (ll a, ll b, ll &x, ll &y) {
		if (!b) {
			x = 1, y = 0;
			return a;
		}
		ll GCD = ex_gcd (b, a % b, x, y);
		ll tmp = y;
		y = x - (a / b) * y;
		x = tmp;
		return GCD;
	}
	
	bool liEu (ll a, ll b, ll c, ll &x,ll &y) {
		ll GCD = ex_gcd (a, b, x, y);
		if (c % GCD) return false;
		ll k = c / GCD, t = b / GCD;
		x = Slow_mul (x, k, b);
		x = (x % t + t) % t;
		return true;
	} 
	//————————————————// 
	
	/*————中国剩余定理CRT————
		通过构造求解线性同余方程组
		x = a1 mod m1 
		x = a2 mod m2
		…………………
		x = an mod mn			 
		局限性较大，必须要求
		任意i, j (1 <= i, j <= m)
		满足 mi 与 mj 互质*/
	ll CRT (ll n, ll (&a)[maxn], ll (&m)[maxn]) {
		ll M = 1, res = 0;
		for (int i = 1; i <= n; ++i) M *= m[i];
		for (int i = 1; i <= n; ++i) {
			ll _m = M / m[i], m_, y;
			liEu (_m, m[i], 1, m_, y);
			res = (res + a[i] * _m * m_) % M;
		}
		return res;
	}
	//————————————————//
	 
	/*———扩展CRT,模数不互质———
		将线性方程组两两合并
		x = a1 mod m1 => x = m1 * p + a1 
		x = a2 mod m2 => x = m2 * q + a2
		=> m1 * p + m2 * (-q) = a2 - a1
		转化成 a*x + b*y = c
		a2 - a1 必须是 gcd (m1, m2)的整数倍
		利用线性同余解出 p
		带入原方程
		合并为:x = A mod M
		A = M(旧) * p + A
		M = lcm (M, m2)*/
	ll ex_CRT (int n, ll (&a)[maxn], ll (&m)[maxn]) {
		ll A = a[1], M = m[1], p, q, c, GCD;
		for (int i = 2; i <= n; ++i) {
			c = ((a[i] - A) % m[i] + m[i]) % m[i]; 
			liEu (M, m[i], c, p, q);
			A = M * p + A;
			M = lcm (M, m[i]);
			A = (A % M + M) % M;
		}
		return A;
	}
	//————————————————// 
};

int t, n;
ll a[maxn], m[maxn];

void charming () {
	/*解线性同余方程*/
	ll a, m, c, x, y;
	std::cin >> a >> c >> m;
	if (math::liEu (a, m, c, x, y)) cout << x << endl;
	else cout << "No Solution!" << endl;
	/*解中国剩余定理
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> m[i] >> a[i];
	cout << math::CRT (n, a, m) << endl;*/
	/*解线性同余方程组
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> m[i] >> a[i];
	cout << math::ex_CRT (n, a, m) << endl;*/
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming (); 
	return 0;
}
