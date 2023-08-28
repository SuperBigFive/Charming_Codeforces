#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 26;

int n, m;
pair <int, int> qry[N];
string s, t;

struct AC {
  int tot;
  int fail[N], id[N], in[N], fa[N];
  int nxt[N][M];
  vector <int> G[N];

  void init () {
    tot = 0;
    memset (id, -1, sizeof id); 
  }

  void Insert (string &t, int tid) {
    int cur = 0, ch2num;
    for (char ch : t) {
      ch2num = ch - 'a';
      if (!nxt[cur][ch2num]) nxt[cur][ch2num] = ++tot;
      cur = nxt[cur][ch2num];
    }
    id[cur] = tid;
  }

  void BFS () {
    queue <int> q;
    for (int i = 0; i < M; ++i) if (nxt[0][i]) {
      q.push (nxt[0][i]);
    }
    while (!q.empty ()) {
      int cur = q.front ();
      q.pop ();
      ++in[fail[cur]], G[fail[cur]].emplace_back (cur);
      for (int j = 0; j < M; ++j) {
        if (nxt[cur][j]) {
          fail[nxt[cur][j]] = nxt[fail[cur]][j];
          q.push (nxt[cur][j]);
        }
        else nxt[cur][j] = nxt[fail[cur]][j];
      }
    }
  }

  void DFS (int f, int u, int last) {
    fa[u] = last;
    if (id[u] != -1) last = u;
    for (int v : G[u]) DFS (u, v, last);
  }

  vector <vector <int> > Match (string &s) {
    vector <vector <int> > pos (N);
    int cur = 0, ch2num, cnt = 0;
    for (char ch : s) {
      ch2num = ch - 'a';
      cur = nxt[cur][ch2num];
      int tmp = cur;
      while (tmp) {
        if (id[tmp] > -1) pos[id[tmp]].emplace_back (cnt);
        tmp = fa[tmp];
      }
      cnt++;
    }
    return pos;
  }

} ac;

void init () {}

void charming () {
  init ();
  cin >> s >> n;
  ac.init ();
  for (int i = 0, k; i < n; ++i) {
    cin >> k >> t, qry[i].first = k, qry[i].second = t.size ();
    ac.Insert (t, i);
  }
  ac.BFS ();
  ac.DFS (0, 0, 0);
  // for (int i = 1; i <= 5; ++i) cout << ac.fa[i] << " \n"[i == 5];
  vector <vector <int> > pos = ac.Match (s);
  for (int i = 0, k; i < n; ++i) {
    k = qry[i].first;
    if ((int) pos[i].size () < k) cout << -1 << endl;
    else {
      int mn = N;
      for (int j = 0, siz = pos[i].size (); j + k - 1 < siz; ++j) {
        mn = min (pos[i][j + k - 1] - pos[i][j], mn);
      }
      cout << mn + qry[i].second << endl;
    }
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}

// AC_求所有模式串的匹配位置