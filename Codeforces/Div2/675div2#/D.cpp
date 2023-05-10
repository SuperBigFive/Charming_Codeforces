#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Dijkstra {
  int n, s;
  vector <int> vis, dis;
  vector <vector <pair <int, int> > > G;
  
  Dijkstra (int n, int s, vector <vector <pair <int, int> > > &G) {
    this -> n = n, this -> s = s;
    vis = dis = vector <int> (n + 5, INT_MAX);
    this -> G = G;
  }

  int Get_Dis (int id) {
    priority_queue <pair <int, int>, vector <
    pair <int, int> >, greater <pair <int, int> > > pq;
    pq.push (make_pair (0, s));
    dis[s] = 0;
    while (!pq.empty ()) {
      auto [udis, u] = pq.top ();
      pq.pop ();
      if (vis[u] == 1) continue;
      vis[u] = 1;
      for (auto &[v, w] : G[u]) {
        //cout << u << " " << v << " " << w << " " << dis[u] << " " << dis[v] << endl;
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          pq.push (make_pair (dis[v], v));
        }
      }
    }
    //for (int i = 1; i <= id; ++i) cout << dis[i] << endl;
    return dis[id];
  }
};

int n, m;

void init () {}

void charming () {
  init ();
  cin >> n >> m;
  int sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  vector <array <int, 3> > pos;
  for (int i = 2, x, y; i <= m + 1; ++i) {
    cin >> x >> y;
    pos.emplace_back ((array <int, 3>) {x, y, i});
  }
  vector <vector <pair <int, int> > > G (m + 5);
  for (int d = 0; d <= 1; ++d) {
    sort (pos.begin (), pos.end (), [&] (array <int, 3> &x,
    array <int, 3> &y) {return x[d] < y[d];});
    for (int i = 0; i < m; ++i) {
      if (i > 0) {
        G[pos[i][2]].emplace_back (make_pair (pos[i - 1][2], pos[i][d] - pos[i - 1][d]));
      }
      if (i < m - 1) {
        G[pos[i][2]].emplace_back (make_pair (pos[i + 1][2], pos[i + 1][d] - pos[i][d]));
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    G[1].emplace_back (make_pair (pos[i][2], min (abs (sx - pos[i][0]), abs (sy - pos[i][1]))));
    G[pos[i][2]].emplace_back (make_pair (m + 2, abs (fx - pos[i][0]) + abs (fy - pos[i][1])));
  }
  cout << min (abs (sx - fx) + abs (sy - fy), Dijkstra (m + 2, 1, G).Get_Dis (m + 2)) << endl;
}

signed main () {
  charming ();
  return 0;
}
