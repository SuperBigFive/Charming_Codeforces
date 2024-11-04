#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int P = 2333;
const int MOD = 998244353;

typedef __int128 IL;
inline ll mul(ll a,ll b,ll md) {return (IL)a*b%md;}
inline ll power(ll a,ll b,ll md,ll rs=1) {for(;b;b>>=1,a=mul(a,a,md)) if(b&1) rs=mul(rs,a,md); return rs;}

namespace RHO {
    const int pr[]={2,3,5,7,11,13,17,19,23};
    vector <ll> vec;
    inline ll gcd(ll a,ll b) {return b ? gcd(b,a%b) : a;}
    inline ll rho(ll nn,ll c) {
        ll x=rand()%nn+1, y=x, k=2;
        for(int i=1;;i++) {
            x=(mul(x,x,nn)+c)%nn;
            ll p=gcd(abs(y-x),nn);
            if(p!=1) return p;
            if(i==k) k<<=1, y=x;
        }
    }
    inline bool mr(ll nn) {
        if(nn<=3) return true;
        if((nn%6)!=1 && (nn%6)!=5) return false;
        ll s1=nn-1, s2=0;
        while(!(s1&1)) s1>>=1, ++s2;
        for(int i=0;i<=8;i++) {
            if(nn==pr[i]) return true;
            ll p=power(pr[i],s1,nn);
            for(int j=1;j<=s2 && p!=1;++j) {
                ll t=mul(p,p,nn);
                if(t==1 && p!=nn-1 && p!=1) return false;
                p=t;
            }
            if(p!=1) return false;
        } return true;
    }
    inline void solve(ll nn) {
        if(mr(nn)) {vec.push_back(nn); return;}
        ll g=rho(nn,rand()%nn); 
        while(g==nn) g=rho(nn,rand()%nn);
        solve(nn/g); solve(g);
    }
}

ll n, m, tot;
ll a[N];

ll vecHashValue (vector <pair <ll, ll> > &vec) {
  ll ans = 0;
  for (auto [x1, x2] : vec) {
    ans = (1ll * ans * P % MOD + x2) % MOD;
  }
  return ans;
}

void charming () {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  RHO :: solve (m);
  vector <ll> fac_m = RHO :: vec;
  sort (fac_m.begin (), fac_m.end ());
  fac_m.resize (unique (fac_m.begin (), fac_m.end ()) - fac_m.begin ());
  vector <pair <ll, ll> > f, tmp_f;
  for (ll p : fac_m) {
    int cnt = 0; ll tmp_m = m;
    while (!(tmp_m % p)) tmp_m /= p, ++cnt;
    f.emplace_back (make_pair (p, cnt));
  }
  tmp_f = f;
  map <ll, int> mp;
  vector <vector <pair <ll, ll> > > all_f;

  auto DFS = [&] (auto &&self, int now) -> void {
    if (now >= (int) f.size ()) {
      mp[vecHashValue (tmp_f)] = tot++;
      all_f.emplace_back (tmp_f);
      return;
    }
      
    int cnt = f[now].second;
    for (int i = 0; i <= cnt; ++i) {
      tmp_f[now].second = i;
      self (self, now + 1);
    }
  };

  DFS (DFS, 0);
  vector <int> dp (tot), ndp (tot);
  dp[0] = 1;
  int cnt1 = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 1) {
      cnt1 += 1;
      continue;
    }
    ll tmp_ai = a[i];
    vector <pair <ll, ll> > f_ai;
    for (ll p : fac_m) {
      int cnt = 0;
      while (!(tmp_ai % p)) {
        tmp_ai /= p;
        ++cnt;
      }
      if (cnt) f_ai.emplace_back (make_pair (p, cnt));
    }
    if (tmp_ai > 1) continue;
    
    ndp = dp;
    for (int j = 0; j < tot; ++j) {
      if (dp[j] > 0) {
        vector <pair <ll, ll> > now_f = all_f[j];
        int p = 0;
        bool ok = true;
        for (auto [q, cnt] : f_ai) {
          while (p < (int) fac_m.size () && fac_m[p] != q) ++p;
          if (cnt > f[p].second) {ok = false; break;}
          else now_f[p].second = max (now_f[p].second, cnt);
        }
        if (ok) {
          ll nxt = mp[vecHashValue (now_f)];
          ndp[nxt] = (ndp[nxt] + dp[j]) % MOD;
        }
      }
    }
    dp = ndp;
  }
  int ans = dp[mp[vecHashValue (f)]];
  for (int i = 1; i <= cnt1; ++i) ans = (ans << 1) % MOD;
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}