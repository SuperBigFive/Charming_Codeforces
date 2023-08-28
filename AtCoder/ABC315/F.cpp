#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 32;

int n;

void init () {}

void charming () {
  init ();
  cin >> n;
  vector <int> POW2 (M);
  vector <pair <int, int> > p (n);
  vector <double> dis (n);
  POW2[0] = 1;
  for (int i = 1; i < M; ++i) POW2[i] = POW2[i - 1] * 2;
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

  auto Calc = [&] (int id1, int id2) -> double {
    double ans = 1.0 * sqrt (1.0 * (p[id1].first - p[id2].first) * (p[id1].first - p[id2].first)
    + 1.0 * (p[id1].second - p[id2].second) * (p[id1].second - p[id2].second));
    // cout << "!" << (p[id1].first - p[id2].first) << " " << 
    // (p[id1].second - p[id2].second) << " " << ans << endl;
    return ans;
  };

  double ans = INT_MAX;
  for (int cnt = 0; cnt < M; ++cnt) {
    vector <vector <double> > f (n, vector <double> (cnt + 1, INT_MAX));
    f[n - 1][0] = 0;
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0, nxt; j <= cnt; ++j) {
        nxt = i + j + 1;
        if (nxt >= n) break;
        for (int k = 0; j + k <= cnt; ++k) {
          f[i][j + k] = min (f[i][j + k], Calc (i, nxt) + f[nxt][k]);
        }
      }
    }
    if (f[0][cnt] >= INT_MAX) continue;
    else if (cnt == 0) ans = min (ans, f[0][cnt]);
    else ans = min (ans, f[0][cnt] + 1.0 * POW2[cnt - 1]);
    // cout << cnt << " " << f[0][cnt] << endl;
  }
  // for (int i = n - 2; i >= 0; --i) {
  //   dis[i] = Calc (i, i + 1) + dis[i + 1];
  //   for (int j = i + 2, skip; j < n; ++j) {
  //     skip = j - i - 1;
  //     if (skip >= M) break;
  //     dis[i] = min (dis[i], dis[j] + POW2[skip - 1] + Calc (i, j));
  //   }
  //   cout << i << " " << dis[i] << endl;
  // }
  
  cout << fixed << setprecision (15);
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}