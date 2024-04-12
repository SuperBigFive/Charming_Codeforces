#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int M = 30;

int t, n, q;
int pre[N][M];
pair <int, int> grade[N];

void charming () {
  cin >> n;
  vector <vector <int> > pos (M, vector <int> ());
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    grade[i] = make_pair (x, y);
    int cge = -1;
    for (int j = M - 1, bx, by; j >= 0; --j) {
      pre[i][j] = pre[i - 1][j];
      by = (y >> j) & 1, bx = (x >> j) & 1;
      if ((bx ^ by) && cge == -1) cge = j, pos[j].emplace_back (i);
      else if (by == 1 && cge > -1) pos[j].emplace_back (i);
      if (by) ++pre[i][j];
    }
  }
  cin >> q;
  for (int i = 1, l, r, k; i <= q; ++i) {
    cin >> l >> r, k = -1;
    for (int j = M - 1; j >= 0; --j) {
      int cnt = pre[r][j] - pre[l - 1][j];
      // cout << j << " " << cnt << endl;
      if (cnt > 1 && (int) pos[j].size () > 0) {
        int L = 0, R = (int) pos[j].size () - 1, id = R;
        while (L <= R) {
          int mid = L + R >> 1;
          if (pos[j][mid] >= l) {
            R = mid - 1;
            id = mid;
          }
          else L = mid + 1;
        }
        if (pos[j][id] >= l && pos[j][id] <= r) {k = j; break;}
      }
    }
    int ans = 0;
    for (int j = 0; j < M; ++j) {
      int cnt = pre[r][j] - pre[l - 1][j];
      if (j < k || cnt > 0) ans += (1 << j);
    }
    cout << ans << " \n"[i == q];
  }

}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}