#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

void charming () {
  cin >> n;
  string arr[2];
  cin >> arr[0] >> arr[1];
  map <pair <int, int>, int> vis;
  queue <pair <int, int> > q;
  q.push (make_pair (0, 0));
  vis[make_pair (0, 0)] = 1;
  while (!q.empty ()) {
    auto [now_x, now_y] = q.front ();
    q.pop ();
    for (int i = 0, nx, ny; i < 4; ++i) {
      nx = now_x + dirx[i], ny = now_y + diry[i];
      if (nx >= 0 && nx <= 1 && ny >= 0 && ny < n - 1) {
        if (nx == 1 && ny == n - 1) {
          cout << "YES" << endl;
          return;
        }
        else {
          if (arr[nx][ny] == '>') {
            ny += 1;
          }
          else ny -= 1;
          if (!vis.count (make_pair (nx, ny))) {
            vis[make_pair (nx, ny)] = 1;
            q.push (make_pair (nx, ny));
          }
        }
      }
    }
  }
  if (vis.count (make_pair (1, n - 1))) cout << "YES" << endl;
  else cout << "NO" << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}