#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e6 + 5;
const int M = 26;
const int P1 = 131, P2 = 2333;
const int MOD1 = 1e9 + 7, MOD2 = 998244353;

struct Hasher {
  int P, MOD;
  vector <int> POWP;

  Hasher (int P, int MOD) {
    this -> P = P, this -> MOD = MOD;
    this -> POWP = vector <int> (N);
    POWP[0] = 1;
    for (int i = 1; i < N; ++i) POWP[i] = (1ll * POWP[i - 1] * P) % MOD;
  }

  vector <int> Get_hash (string &s) {
    int siz = s.size ();
    vector <int> hval (siz + 1);
    for (int i = 1; i <= siz; ++i) {
      hval[i] = (1ll * hval[i - 1] * P + s[i - 1] - 'a') % MOD;
    }
    return hval;
  }

  int Calc_hash (vector <int> &hval, int l, int r) {
    if (l <= 0 || l > r) return -1;
    int h = (hval[r] - 1ll * hval[l - 1] * POWP[r - l + 1]) % MOD;
    h = (h + MOD) % MOD;
    return h;
  }
};

int n, m, q, tot, last;
int len[N], fail[N], cnt[N];
int nxt[N][M], fa[N][M];
vector <int> G[N];
string s, t, dt;

void init () {tot = last = len[0] = 0, fail[0] = -1;}

void Sam_extend (char ch) {
  int ch2num = ch - 'a', cur = ++tot;
  len[cur] = len[last] + 1;
  int p = last;
  while (p != -1 && !nxt[p][ch2num]) {
    nxt[p][ch2num] = cur;
    p = fail[p];
  }
  if (p == -1) fail[cur] = 0;
  else {
    int q = nxt[p][ch2num];
    if (len[q] == len[p] + 1) fail[cur] = q;
    else {
      int clone = ++tot;
      len[clone] = len[p] + 1;
      fail[clone] = fail[q];
      memcpy (nxt[clone], nxt[q], sizeof nxt[clone]);
      while (p != -1 && nxt[p][ch2num] == q) {
        nxt[p][ch2num] = clone;
        p = fail[p];
      }
      fail[cur] = fail[q] = clone;
    }
  }
  cnt[cur] = 1, last = cur;
}

void DFS (int f, int u) {
  fa[u][0] = f;
  for (int i = 1; i < M; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : G[u]) {
    DFS (u, v);
    cnt[u] += cnt[v];
  }
}

void charming () {
  init ();
  cin >> s, n = s.size ();
  for (char ch : s) Sam_extend (ch);
  for (int i = 1; i <= tot; ++i) G[fail[i]].emplace_back (i);
  DFS (0, 0);
  Hasher hash1 (P1, MOD1), hash2 (P2, MOD2);
  cin >> q;
  for (int i = 0, cur, k, ch2num, ans; i < q; ++i) {
    cin >> t, m = t.size (), cur = k = ans = 0;
    dt = t + t;
    vector <int> hval1 = hash1.Get_hash (dt);
    vector <int> hval2 = hash2.Get_hash (dt);

    set <pair <int, int> > vis;
    vis.insert (make_pair (-1, -1));
    for (int j = 0; j < 2 * m - 1; ++j) {
      ch2num = t[j % m] - 'a';
      if (nxt[cur][ch2num]) cur = nxt[cur][ch2num], ++k;
      else {
        if (k) {
          for (int i = M - 1; i >= 0; --i) if (len[fa[cur][i]] >= k) {
            cur = fa[cur][i];
          }
          cur = fa[cur][0];
        }
        while (cur && !nxt[cur][ch2num]) cur = fail[cur];
        k = len[cur];
        if (nxt[cur][ch2num]) cur = nxt[cur][ch2num], ++k;
      }
      
      int h1 = hash1.Calc_hash (hval1, j - m + 2, j + 1);
      int h2 = hash2.Calc_hash (hval2, j - m + 2, j + 1);
      if (k >= m) {
        while (len[fail[cur]] >= m) cur = fail[cur];
        if (!vis.count (make_pair (h1, h2))) ans += cnt[cur];
        k = m;
      }
      vis.insert (make_pair (h1, h2));
    }
    cout << ans << endl;
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}
