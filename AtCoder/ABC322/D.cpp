#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3;
const int M = 4;

int dx[9], dy[9];
int mp[M][M];
int p[N][4][M][M];
vector <pair <int, int> > pos[N][4];

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0; char ch = 0;
  while (!isdigit (ch)) ch = getch ();
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x;
}

bool Inside (int x, int y) {return x >= 0 && x < 4 && y >= 0 && y < 4;}

void init () {}

void charming () {
  init ();
  // cout << pos[0][0].size () << endl;
  for (int i = 0; i < N; ++i) {
    for (int x = 0; x < M; ++x) {
      string s;
      cin >> s;
      for (int y = 0; y < M; ++y) {
        p[i][0][x][y] = (s[y] == '#');
      }
    }
    for (int j = 1; j < 4; ++j) {
      for (int x = 0; x < M; ++x) {
        for (int y = 0; y < M; ++y) {
          p[i][j][y][3 - x] = p[i][j - 1][x][y];
        }
      }
    }
    for (int j = 0; j < 4; ++j) {
      for (int x = 0; x < M; ++x) {
        for (int y = 0; y < M; ++y) if (p[i][j][x][y]) {
          pos[i][j].emplace_back (make_pair (x, y));
        }
      }
    }
  }
  bool ok = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        memset (mp, 0, sizeof mp);
        bool valid = true;
        for (int dxi = -4; dxi <= 4; ++dxi) {
          for (int dyi = -4; dyi <= 4; ++dyi) {
            vector <pair <int, int> > veci;
            valid = true;
            for (auto [xi, yi] : pos[0][i]) {
              xi += dxi, yi += dyi;
              if (!Inside (xi, yi)) {valid = false; break;}
              else veci.emplace_back (make_pair (xi, yi));
            }
            // cout << "ok, i" << endl;
            if (!valid) continue;
            for (int dxj = -4; dxj <= 4; ++dxj) {
              // cout << "ok, j" << endl;
              for (int dyj = -4; dyj <= 4; ++dyj) {
                vector <pair <int, int> > vecj;
                valid = true;
                for (auto [xj, yj] : pos[1][j]) {
                  xj += dxj, yj += dyj;
                  if (!Inside (xj, yj)) {valid = false; break;}
                  else vecj.emplace_back (make_pair (xj, yj));
                }
                if (!valid) continue;
                for (int dxk = -4; dxk <= 4; ++dxk) {
                  for (int dyk = -4; dyk <= 4; ++dyk) {
                    vector <pair <int, int> > veck;
                    valid = true;
                    for (auto [xk, yk] : pos[2][k]) {
                      xk += dxk, yk += dyk;
                      if (!Inside (xk, yk)) {valid = false; break;}
                      else veck.emplace_back (make_pair (xk, yk));
                    }
                    if (!valid) continue;
                    else {
                      for (auto [xi, yi] : veci) ++mp[xi][yi];
                      for (auto [xj, yj] : vecj) ++mp[xj][yj];
                      for (auto [xk, yk] : veck) ++mp[xk][yk];
                      bool chk = true;
                      for (int p = 0; p < M; ++p) {
                        for (int q = 0; q < M; ++q) {
                          if (mp[p][q] != 1) {chk = false; break;}
                        }
                        if (!chk) break;
                      }
                      if (chk) {puts ("Yes"); return;}
                      else memset (mp, 0, sizeof mp);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  puts ("No");
}

signed main () {
  charming ();
  return 0;
}