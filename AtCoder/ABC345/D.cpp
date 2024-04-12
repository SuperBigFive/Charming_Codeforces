#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10;

int n, h, w;
int a[N], b[N];

void charming () {
  cin >> n >> h >> w;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  vector <vector <vector <int> > > choose (n + 1);
  for (int i = 1, area; i < (1 << n); ++i) {
    vector <int> idx; area = 0;
    for (int j = 0; j < n; ++j) if ((i >> j) & 1) {
      idx.emplace_back (j);
      area += a[j] * b[j];
    }
    if (area == h * w) choose[(int) idx.size ()].emplace_back (idx);
  }
  for (int i = 1; i <= n; ++i) {
    for (auto idx : choose[i]) {
      for (int j = 0; j < (1 << i); ++j) {
        vector <pair <int, int> > tile;
        for (int k = 0; k < i; ++k) {
          if ((j >> k) & 1) tile.emplace_back (make_pair (b[idx[k]], a[idx[k]]));
          else tile.emplace_back (make_pair (a[idx[k]], b[idx[k]]));
        }
        vector <int> p (i);
        iota (p.begin (), p.end (), 1);
        do {
          bool ok = true;
          int id = 0;
          vector <vector <int> > vis (h, vector <int> (w));
          for (int x = 0; x < h; ++x) {
            for (int y = 0; y < w; ++y) {
              if (vis[x][y]) continue;
              else {
                int tile_h = tile[p[id] - 1].first, tile_w = tile[p[id] - 1].second;
                if (x + tile_h - 1 >= h || y + tile_w - 1 >= w) {
                  ok = false;
                  break;
                }
                else {
                  for (int px = x; px < x + tile_h; ++px) {
                    for (int py = y; py < y + tile_w; ++py) {
                      if (vis[px][py]) {ok = false; break;}
                      else vis[px][py] = 1;
                    }
                    if (!ok) break;
                  }
                }
              }
              id += 1;
            }
            if (!ok) break;
          }
          if (ok) return void (cout << "Yes" << endl);
        } while (next_permutation (p.begin (), p.end ()));
      }
    }
  }
  cout << "No" << endl;
}

signed main () {
  charming ();
  return 0;
}