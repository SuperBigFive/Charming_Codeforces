#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e3 + 5;

int h, w;

void init () {}

void charming () {
  init ();
  cin >> h >> w;
  vector <vector <int> > mp (h + 5, vector <int> (w + 5, -1));
  string s;
  pair <int, int> st, en;
  for (int i = 0; i < h; ++i) {
    cin >> s;
    for (int j = 0; j < w; ++j) {
      if (s[j] == '.') mp[i + 1][j + 1] = 0;
      else if (s[j] == '#') mp[i + 1][j + 1] = -1;
      else if (s[j] == '^') mp[i + 1][j + 1] = 1;
      else if (s[j] == '>') mp[i + 1][j + 1] = 2;
      else if (s[j] == 'v') mp[i + 1][j + 1] = 3;
      else if (s[j] == '<') mp[i + 1][j + 1] = 4;
      else if (s[j] == 'S') mp[i + 1][j + 1] = 0, st = make_pair (i + 1, j + 1);
      else mp[i + 1][j + 1] = 0, en = make_pair (i + 1, j + 1);
    }
  }

  vector <vector <int> > up (h + 5, vector <int> (w + 5));
  vector <vector <int> > rig (h + 5, vector <int> (w + 5));
  vector <vector <int> > down (h + 5, vector <int> (w + 5));
  vector <vector <int> > lef (h + 5, vector <int> (w + 5));
  vector <vector <int> > tag_c (h + 5, vector <int> (w + 5));
  vector <vector <int> > tag_r (h + 5, vector <int> (w + 5));
  for (int j = 1; j <= w; ++j) {
    for (int i = 1; i <= h; ++i) {
      if (mp[i - 1][j] != 0) up[i][j] = max (1, i - 1);
      else up[i][j] = up[i - 1][j];
    }
  }
  for (int i = 1; i <= h; ++i) {
    for (int j = w; j >= 1; --j) {
      if (mp[i][j + 1] != 0) rig[i][j] = min (w, j + 1);
      else rig[i][j] = rig[i][j + 1];
    }
  }
  for (int j = 1; j <= w; ++j) {
    for (int i = h; i >= 1; --i) {
      if (mp[i + 1][j] != 0) down[i][j] = min (h, i + 1);
      else down[i][j] = down[i + 1][j];
    }
  }
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (mp[i][j - 1] != 0) lef[i][j] = max (1, j - 1);
      else lef[i][j] = lef[i][j - 1];
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (mp[i][j] == 1) {
        ++tag_c[up[i][j]][j], --tag_c[i + 1][j];
      }
      else if (mp[i][j] == 2) {
        ++tag_r[i][j], --tag_r[i][rig[i][j] + 1];
      }
      else if (mp[i][j] == 3) {
        ++tag_c[i][j], --tag_c[down[i][j] + 1][j];
      }
      else if (mp[i][j] == 4) {
        ++tag_r[i][lef[i][j]], --tag_r[i][j + 1];
      }
    }
  }

  vector <vector <bool> > ban (h + 5, vector <bool> (w + 5));
  for (int i = 1, sum; i <= h; ++i) {
    sum = 0;
    for (int j = 1; j <= w; ++j) {
      sum += tag_r[i][j];
      if (sum > 0) ban[i][j] = true;
    }
  }
  for (int j = 1, sum; j <= w; ++j) {
    sum = 0;
    for (int i = 1; i <= h; ++i) {
      sum += tag_c[i][j];
      if (sum > 0) ban[i][j] = true;
    }
  }
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (mp[i][j] != 0) ban[i][j] = true;
    }
  }
  
  queue <pair <int, int> > q;
  vector <vector <int> > dis (h + 5, vector <int> (w + 5, -1));
  q.push (st), dis[st.first][st.second] = 0;
  array <int, 4> dx {0, 0, 1, -1}, dy {1, -1, 0, 0};
  while (!q.empty ()) {
    auto [x, y] = q.front ();
    // cout << x << " " << y << endl;
    q.pop ();
    for (int i = 0, nx, ny; i < 4; ++i) {
      nx = x + dx[i], ny = y + dy[i];
      if (nx >= 1 && nx <= h && ny >= 1 && ny <= w
      && !ban[nx][ny] && dis[nx][ny] == -1) {
        dis[nx][ny] = dis[x][y] + 1;
        q.push (make_pair (nx, ny));
      }
    }
  }
  printf ("%d\n", dis[en.first][en.second]);
  // for (int i = 1; i <= h; ++i) {
  //   for (int j = 1; j <= w; ++j) cout << ban[i][j] << " \n"[j == w];
  // }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  charming ();
  return 0;
}
