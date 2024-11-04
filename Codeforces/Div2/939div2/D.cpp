#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
const int N = 20;

int n;
int a[N], dp[N], pre[N];
vector <pair <int, int> > ans;

void construct (int l, int r, int x) {
  // a[l] = a[l + 1] = ... = a[r] = 0
  // make a[r] = x
  for (int i = l; i <= r; ++i) if (a[i]) {
    ans.emplace_back (make_pair (i, i));
    a[i] = 0;
  }
  if (!x) return;
  else if (x == 1) {
    ans.emplace_back (r, r);
    a[r] = 1;
    return;
  }
  int now = x - 1;
  for (int i = r; now > 0; --i) {
    construct (l, i, now--);
  }
  ans.emplace_back (make_pair (r - (x - 1), r));
  for (int i = r - (x - 1); i <= r; ++i) a[i] = x;
}

void makeSame (int l, int r) {
  if (l == r) {
    if (a[l] == 0) ans.emplace_back (l, l), a[l] = 1;
    return;
  }
  for (int i = r; i >= l; --i) {
    construct (l, i, i - l);
  }
  ans.emplace_back (make_pair (l, r));
}

int calcSum (int l, int r) {
  if (l == r) return max (1ll, a[l]);
  else return (r - l + 1) * (r - l + 1);
}

void charming () {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int mx_sum = 0, mx_st = -1;
  for (int st = 0; st < (1 << n); ++st) {
    int l = 0;
    vector <pair <int, int> > seq;
    for (int i = 0, chk; i < n; ++i) {
      chk = (st >> i) & 1;
      if (chk == 1) {
        seq.emplace_back (make_pair (l + 1, i + 1));
        l = i + 1;
      }
    }
    if (l < n) seq.emplace_back (make_pair (l + 1, n));
    int cur_sum = 0;
    for (auto [l, r] : seq) cur_sum += calcSum (l, r);
    if (cur_sum > mx_sum) {
      mx_sum = cur_sum;
      mx_st = st;
    }
  }
  int l = 0;
  for (int i = 0, chk, r; i < n; ++i) {
    chk = (mx_st >> i) & 1;
    if (chk == 1) {
      r = i;
      makeSame (l + 1, r + 1);
      l = i + 1;
    }
  }
  if (l < n) makeSame (l + 1, n);
  cout << mx_sum << " " << ans.size () << endl;
  // for (auto [l, r] : ans) cout << l << " " << r << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}

/*
18
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/