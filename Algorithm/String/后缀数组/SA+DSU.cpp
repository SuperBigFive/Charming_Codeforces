#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e6 + 5;
const int MOD = 1e9 + 7;

int n, mn;
string s, s1, s2, s3;

struct SA {
  int n, m, w, tot;
  vector <int> sa, rk, het;
  vector <int> id, old_rk, cnt;

  void Get (string &s) {
    n = (int) s.size () - 1, m = 300, tot = 0;
    sa = rk = het = id = old_rk = vector <int> (n << 1 | 1);
    cnt = vector <int> (N);
    for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

    auto Key2Sort = [&] () {
      tot = 0;
      for (int i = 1; i <= m; ++i) cnt[i] = 0;
      for (int i = n; i >= n - w + 1; --i) id[++tot] = i;
      for (int i = 1; i <= n; ++i) {
        if (sa[i] - w >= 1) id[++tot] = sa[i] - w;
      }
    };

    auto Key1Sort = [&] () {
      for (int i = 1; i <= n; ++i) ++cnt[rk[i]];
      for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
      for (int i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];
    };

    auto Update = [&] () {
      tot = 0;
      for (int i = 1; i <= n; ++i) old_rk[i] = rk[i];
      for (int i = 1; i <= n; ++i) {
        if (old_rk[sa[i]] == old_rk[sa[i - 1]] &&
        old_rk[sa[i] + w] == old_rk[sa[i - 1] + w]) rk[sa[i]] = tot;
        else rk[sa[i]] = ++tot;
      }
    };
    
    for (w = 1; w < n && tot < n; w <<= 1, m = tot) {
      Key2Sort ();
      Key1Sort ();
      Update ();
    }

    for (int i = 1, k = 0; i <= n; ++i) {
      if (rk[i] == 1) continue;
      else if (k) --k;
      while (sa[rk[i]] + k <= n && sa[rk[i] - 1] + k <= n &&
      s[sa[rk[i]] + k] == s[sa[rk[i] - 1] + k]) ++k;
      het[rk[i]] = k;
    }
  }
};

void init () {}

void charming () {
  init ();
  cin >> s1 >> s2 >> s3;
  s = '#', n = s1.size () + s2.size () + s3.size () + 3;
  vector <int> bel (n + 1);
  for (int i = 0, siz = s1.size (); i < siz; ++i) {
    bel[s.size ()] = 1, s += s1[i];
  }
  s += '1';
  for (int i = 0, siz = s2.size (); i < siz; ++i) {
    bel[s.size ()] = 2, s += s2[i];
  }
  s += '2';
  for (int i = 0, siz = s3.size (); i < siz; ++i) {
    bel[s.size ()] = 3, s += s3[i];
  }
  s += '3';
  vector <array <int, 3> > sum (n + 1, (array <int, 3>) {0, 0, 0});
  for (int i = 1; i <= n; ++i) {
    if (bel[i] == 1) ++sum[i][0];
    else if (bel[i] == 2) ++sum[i][1];
    else if (bel[i] == 3) ++sum[i][2];
  }
  mn = min ({s1.size (), s2.size (), s3.size ()});

  SA sa;
  sa.Get (s);

  vector <int> p (n), pre (n + 1), het (n + 1, 1);
  iota (p.begin (), p.end (), 1);
  iota (pre.begin (), pre.end (), 0);
  sort (p.begin (), p.end (), [&] (int x, int y) {
    return sa.het[x] > sa.het[y];
  });

  auto Find = [&] (auto && me, int x) -> int {
    if (x == pre[x]) return x;
    return pre[x] = me (me, pre[x]);
  };

  auto Calc = [&] (int id) -> int {
    int ans = (1ll * sum[id][0] * sum[id][1] * sum[id][2]) % MOD;
    return ans;
  };

  vector <int> ans (mn + 1);
  int id = 0, nans = 0;
  for (int len = mn, u, v, fu, fv; len >= 1; --len) {
    while (id < n && sa.het[p[id]] >= len) {
      u = sa.sa[p[id] - 1], v = sa.sa[p[id]];
      fu = Find (Find, u), fv = Find (Find, v);
      if (het[fu] < het[fv]) swap (fu, fv);
      nans = (nans - Calc (fu)) % MOD;
      nans = (nans - Calc (fv)) % MOD;
      sum[fu][0] += sum[fv][0], sum[fu][1] += sum[fv][1], sum[fu][2] += sum[fv][2];
      pre[fv] = fu, het[fu] += (het[fu] == het[fv]);
      nans = (nans + Calc (fu)) % MOD;
      ++id;
    }
    nans = ((nans % MOD) + MOD) % MOD;
    ans[len] = nans;
  }
  for (int i = 1; i <= mn; ++i) cout << ans[i] << " \n"[i == mn];
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}
