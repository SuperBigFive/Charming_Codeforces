#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

ll qmi(ll a, ll b, ll mod)
{
    ll res = 1 % mod;
    while(b) { if(b & 1) res = (LL)res * a % mod; a = (LL)a * a % mod; b >>= 1; }
    return res;
}

ll get_phi(ll x)
{
    ll res = x;
    for(ll i = 2; i <= x / i; i ++)
        if(x % i == 0)
        {
            res = res / i * (i - 1);
            while(x % i == 0)   x /= i;
        }
    if(x > 1)   res = res / x * (x - 1);
    return res;
}

//判断n层幂塔a是否>=phi
bool check(ll a, ll n, ll phi)
{
    if(n == 0)  return phi <= 1; //0层幂塔是1
    if(a >= phi)    return true; //底数a>=phi，那么它的幂塔一定>=phi
    return check(a, n - 1, log(phi) / log(a));//取对数，消去一层，继续判断
}

//计算n层幂塔: a^a^a^a..^a (mod m)
//其中共有n个a
ll f(ll a, ll n, ll m)
{
    if(m == 1)  return 0; //对1取模，恒为0
    if(n <= 1)  return qmi(a, n, m);
    
    ll phi = get_phi(m);
    //互质
    if(__gcd(a, m) == 1)    return qmi(a, f(a, n - 1, phi), m);
    //不互质
    if(check(a, n - 1, phi))    return qmi(a, f(a, n - 1, phi) + phi, m);//a的指数>=phi
    return qmi(a, f(a, n - 1, phi), m); //a的指数<phi, 所以改成对phi取模对答案无影响
}

int main()
{
    ll a, n, m;
    cin >> a >> n >> m;
    cout << f(a, n, m) << endl;
    return 0;
}

