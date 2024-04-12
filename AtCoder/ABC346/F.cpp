#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int M = 26;

ll n, m1, m2;
string s, t;
vector <int> pos[M];

bool Check (ll mid) {
  ll now = 0, cnt = 1;
  for (int i = 1, ch2num, siz; i <= m2 && cnt <= n; ++i) {
    ch2num = t[i] - 'a', siz = pos[ch2num].size ();
    int l = 0, r = siz - 1, k = r;
    if (r < l) return false;
    else {
      ll remain = mid;
      if (pos[ch2num].back () <= now) now = 0, ++cnt;
      while (l <= r) {
        int mid2 = l + r >> 1;
        if (pos[ch2num][mid2] > now) r = mid2 - 1, k = mid2;
        else l = mid2 + 1;
      }
      if (siz - k >= remain) {
        now = pos[ch2num][k + remain - 1];
        continue;
      }
      else {
        remain -= siz - k;
        now = 0, ++cnt;
        cnt += remain / siz;
        if (remain % siz) {
          now = pos[ch2num][remain % siz - 1];
        }
        else {
          now = pos[ch2num].back ();
          --cnt;
        }
     }
    }
  }
  return cnt <= n;
}

void charming () {
  cin >> n >> s >> t;
  m1 = s.size (), m2 = t.size ();
  s = '#' + s, t = '#' + t;
  ll l = 1, r = 1e17, ans = 0;
  for (int i = 1, ch2num; i <= m1; ++i) {
    ch2num = s[i] - 'a';
    pos[ch2num].emplace_back (i);
  }
  while (l <= r) {
    ll mid = l + r >> 1;
    if (Check (mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  cout << ans << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}