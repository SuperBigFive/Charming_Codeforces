#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 30;

int n, m, tot;
string s;

void init () {}

void charming () {
  init ();
  cin >> s >> m, n = s.size (), s = '#' + s;
  map <pair <char, char>, int> mp;
  vector <array <int, M * M> > dis (N);
  vector <vector <int> > G (N);
  tot = n;
  for (int i = 1; i < n; ++i) {
    pair <char, char> p = make_pair (s[i], s[i + 1]);
    if (!mp[p]) mp[p] = ++tot;
    G[i].emplace_back (mp[p]);
    G[mp[p]].emplace_back (i);
    if (i < n - 1) {
      G[i].emplace_back (i + 1);
      G[i + 1].emplace_back (i);
    }
  }
  for (int i = n + 1, id; i <= tot; ++i) {
    queue <int> q;
    vector <int> vis (N);
    id = i - n;
    for (int v : G[i]) q.push (v), vis[v] = 1, dis[v][id] = 0;
    while (!q.empty ()) {
      int u = q.front ();
      q.pop ();
      for (int v : G[u]) {
        if (vis[v]) continue;
        else {
          vis[v] = true;
          dis[v][id] = dis[u][id] + 1;
          if (v > n) {
            for (int w : G[v]) {
              if (vis[w]) continue;
              vis[w] = true;
              dis[w][id] = dis[v][id];
              q.push (w);
            }
          }
          else q.push (v);
        }
      }
    }
  }
  for (int i = 1, f, t, ans; i <= m; ++i) {
    f = read (), t = read ();
    ans = abs (f - t);
    for (int j = n + 1, id; j <= tot; ++j) {
      id = j - n;
      ans = min (ans, dis[f][id] + dis[t][id] + 1);
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