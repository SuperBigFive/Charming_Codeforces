#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e6 + 5;
const int M = 26;

int n, last, tot;
int len[N], fail[N], in[N], cnt[N];
int nxt[N][M];
string s;

void init () {last = tot = 0, len[0] = 0, fail[0] = -1;}

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
      memcpy (nxt[clone], nxt[q], sizeof nxt[clone]);
      fail[clone] = fail[q];
      while (p != -1 && nxt[p][ch2num] == q) {
        nxt[p][ch2num] = clone;
        p = fail[p];
      }
      fail[cur] = fail[q] = clone;
    }
  }
  cnt[cur] = 1, last = cur;
}

void charming () {
  init ();
  cin >> s, n = s.size ();
  for (char ch : s) Sam_extend (ch);
  for (int i = 1; i <= tot; ++i) ++in[fail[i]];
  in[0] = 0;
  queue <int> q;
  for (int i = 1; i <= tot; ++i) if (!in[i]) {
    q.push (i);
  }
  while (!q.empty ()) {
    int cur = q.front ();
    q.pop ();
    cnt[fail[cur]] += cnt[cur];
    --in[fail[cur]];
    if (!in[fail[cur]]) q.push (fail[cur]);
  }
  ll ans = 0;
  for (int i = 1; i <= tot; ++i) if (cnt[i] > 1) {
    ans = max (ans, 1ll * cnt[i] * len[i]);
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
