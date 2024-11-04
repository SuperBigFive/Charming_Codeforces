#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
  init ();
  cin >> n >> m;
  vector <int> tim;
  map <int, pair <int, int> > nod;
  map <ll, vector <int> > ret;
  for (int i = 0, T, W, S; i < m; ++i) {
    cin >> T >> W >> S;
    nod[T] = make_pair (W, S);
    tim.emplace_back (T);
    tim.emplace_back (T + S);
  }
  sort (tim.begin (), tim.end ());
  tim.resize (unique (tim.begin (), tim.end ()) - tim.begin ());
  vector <ll> ans (n);
  set <int> q;
  for (int i = 0; i < n; ++i) q.insert (i);
  for (int now : tim) {
    for (int id : ret[now]) q.insert (id);
    if (nod.count (now)) {
      if (!q.empty ()) {
        int id = *q.begin ();
        q.erase (id);
        ans[id] += nod[now].first;
        ret[now + nod[now].second].emplace_back (id);
      }
    }
  }
  for (int i = 0; i < n; ++i) printf ("%lld\n", ans[i]);
}

signed main () {
  charming ();
  return 0;
}