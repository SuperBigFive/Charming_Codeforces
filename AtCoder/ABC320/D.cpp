#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll M = 1e15 + 5;

int n, m;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

void init () {}

void charming () {
  init ();
  n = read (), m = read ();
  vector <vector <array <int, 3> > > G (n);
  vector <pair <ll, ll> > pos (n, make_pair (M, M));
  pos[0] = make_pair (0, 0);
  for (int i = 0, u, v, dx, dy; i < m; ++i) {
    u = read () - 1, v = read () - 1, dx = read (), dy = read ();
    G[u].emplace_back ((array <int, 3>) {v, dx, dy});
    G[v].emplace_back ((array <int, 3>) {u, -dx, -dy});
  }
  queue <int> q;
  q.push (0);
  while (!q.empty ()) {
    int u = q.front ();
    q.pop ();
    for (auto [v, dx, dy] : G[u]) {
      if (pos[v].first < M) continue;
      else {
        pos[v].first = pos[u].first + dx;
        pos[v].second = pos[u].second + dy;
        q.push (v); 
      } 
    }
  }
  for (int i = 0; i < n; ++i) {
    if (pos[i].first >= M) cout << "undecidable" << endl;
    else cout << pos[i].first << " " << pos[i].second << endl;
  }
}

signed main () {
  charming ();
  return 0;
}