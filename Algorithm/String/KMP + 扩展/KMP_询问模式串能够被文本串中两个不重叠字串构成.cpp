#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e5 + 5;

struct KMP {
  int n;
  string t;
  vector <int> fail;

  KMP () {}
  KMP (string &t) {
    this -> n = t.size (), this -> t = '#' + t;
    this -> fail = vector <int> (n + 1);
    Get_fail ();
  }

  void Get_fail () {
    for (int i = 2, j; i <= n; ++i) {
      j = fail[i - 1];
      while (j && t[j + 1] != t[i]) j = fail[j];
      if (t[j + 1] == t[i]) ++j;
      fail[i] = j;
    }
  }

  vector <int> Match (string &s) {
    int siz = s.size ();
    vector <int> ans (siz);
    for (int i = 0, j = 0; i < siz; ++i) {
      while (j && s[i] != t[j + 1]) j = fail[j];
      if (s[i] == t[j + 1]) ++j;
      ans[i] = j; 
      if (j >= n) j = fail[j];
    }
    return ans;
  }
};

int n, m;
string s, t;

void init () {}

void charming () {
  init ();
  cin >> s, n = s.size ();
  cin >> m;
  KMP kmp;
  int ans = 0;
  for (int i = 0, siz; i < m; ++i) {
    cin >> t, siz = t.size ();
    if (siz == 1) continue;
    kmp = KMP (t);
    vector <int> pre = kmp.Match (s);
    reverse (t.begin (), t.end ());
    kmp = KMP (t);
    reverse (s.begin (), s.end ());
    vector <int> suf = kmp.Match (s);
    reverse (suf.begin (), suf.end ());
    reverse (s.begin (), s.end ());

    for (int i = 1; i < n; ++i) pre[i] = max (pre[i - 1], pre[i]);
    for (int i = n - 2; i >= 0; --i) suf[i] = max (suf[i + 1], suf[i]);
    bool ok = (pre[n - 1] >= siz || suf[0] >= siz);
    for (int i = 0; i < n - 1; ++i) {
      if (pre[i] + suf[i + 1] >= siz) {ok = true; break;}
    }
    if (ok) ++ans;
  }
  cout << ans << endl;
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}
