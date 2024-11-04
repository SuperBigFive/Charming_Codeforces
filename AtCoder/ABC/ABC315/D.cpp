#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 26;

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

int h, w;

void init () {}

void charming () {
  init ();
  cin >> h >> w;
  vector <string> col (h);
  for (int i = 0; i < h; ++i) cin >> col[i];
  vector <int> rsiz (h), csiz (w), rsum (h), csum (w), rvis (h), cvis (w);
  vector <vector <bool> > remove (h, vector <bool> (w));
  vector <array <int, M> > rcnt (h), ccnt (w);
  for (int i = 0; i < h; ++i) {
    rsum[i] = w;
    for (int j = 0, ch2num; j < w; ++j) {
      ch2num = col[i][j] - 'a';
      ++rcnt[i][ch2num];
    }
    for (int k = 0; k < M; ++k) if (rcnt[i][k]) ++rsiz[i];
  }
  for (int j = 0; j < w; ++j) {
    csum[j] = h;
    for (int i = 0, ch2num; i < h; ++i) {
      ch2num = col[i][j] - 'a';
      ++ccnt[j][ch2num];
    }
    for (int k = 0; k < M; ++k) if (ccnt[j][k]) ++csiz[j];
  }
  queue <pair <int, int> > q;
  for (int i = 0; i < h; ++i) if (rsiz[i] == 1) q.push (make_pair (0, i));
  for (int j = 0; j < w; ++j) if (csiz[j] == 1) q.push (make_pair (1, j));
  while (!q.empty ()) {
    auto [type, id] = q.front ();
    // cout << type << " " << id << endl;
    q.pop ();
    if (type == 0) {
      if (rvis[id]) continue;
      rvis[id] = 1;
      for (int j = 0, ch2num; j < w; ++j) {
        if (remove[id][j]) continue;
        ch2num = col[id][j] - 'a';
        remove[id][j] = 1;
        --ccnt[j][ch2num], --csum[j];
        if (!ccnt[j][ch2num]) --csiz[j];
        if (csiz[j] == 1 && csum[j] > 1) q.push (make_pair (1, j));
      }
    }
    else {
      if (cvis[id]) continue;
      cvis[id] = 1;
      for (int i = 0, ch2num; i < h; ++i) {
        if (remove[i][id]) continue;
        ch2num = col[i][id] - 'a';
        remove[i][id] = 1;
        --rcnt[i][ch2num], --rsum[i];
        if (!rcnt[i][ch2num]) --rsiz[i];
        if (rsiz[i] == 1 && rsum[i] > 1) q.push (make_pair (0, i));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) ans += (remove[i][j] ^ 1);
  cout << ans << endl;
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}