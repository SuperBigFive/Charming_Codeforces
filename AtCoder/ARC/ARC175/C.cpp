#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int n;
int L[N], R[N], ans[N];
vector <pair <int, int> > seq;
vector <vector <int> > idx;

void init () {}

void charming () {
  init ();
  cin >> n;
  int l = 0, r = INT_MAX;
  vector <int> nidx;
  for (int i = 1; i <= n; ++i) {
    cin >> L[i] >> R[i];
    if (R[i] < l || L[i] > r) {
      seq.emplace_back (make_pair (l, r));
      idx.emplace_back (nidx);
      l = L[i], r = R[i];
      nidx = vector <int> ();
    }
    else {
      l = max (l, L[i]), r = min (r, R[i]);
    }
    nidx.emplace_back (i);
  }
  seq.emplace_back (make_pair (l, r));
  idx.emplace_back (nidx);
  if ((int) idx.size () == 1) {
    for (int x : idx[0]) ans[x] = seq[0].first;
  }
  else {
    int siz = seq.size ();
    for (int i = 0; i < siz - 1; ++i) {
      for (int x : idx[i]) {
        if (seq[i].second < seq[i + 1].first) {
          ans[x] = seq[i].second;
        }
        else ans[x] = seq[i].first;
      }
    }
    for (int x : idx.back ()) {
      if (seq[siz - 1].first > seq[siz - 2].second) {
        ans[x] = seq[siz - 1].first;
      }
      else ans[x] = seq[siz - 1].second;
    }
    ans[0] = ans[1], ans[n + 1] = ans[n];
    for (int i = 1; i <= n; ++i) {
      if (ans[i] >= ans[i - 1] && ans[i] <= ans[i + 1]) {
        ans[i] = min ({ans[i], max (ans[i - 1], L[i]), min (ans[i + 1], R[i])});
      }
    }
    for (int i = n; i >= 1; --i) {
      if (ans[i] >= ans[i + 1] && ans[i] <= ans[i - 1]) {
        ans[i] = min ({ans[i], max (ans[i + 1], L[i]), min (ans[i - 1], R[i])});
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}