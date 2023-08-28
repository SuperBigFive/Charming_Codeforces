#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 1e6 + 1;
// const int M = 20951410;
const int M = 20700000;
const int K = 1e3 + 1;

int q, tot;
int root[N], sum[M], ls[M], rs[M];
int fa1[N], fa2[N];

void Modify (int &rt, int pre, int l, int r, int p) {
  rt = ++tot, ls[rt] = ls[pre], rs[rt] = rs[pre];
  if (l == r) {
    if (!sum[rt]) sum[rt] = 1;
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid) Modify (ls[rt], ls[pre], l, mid, p);
  else Modify (rs[rt], rs[pre], mid + 1, r, p);
  sum[rt] = sum[ls[rt]] + sum[rs[rt]];
}

int Query (int rt) {return sum[rt];}

void init () {}

void charming () {
  init ();
  cin >> q;
  char opt;
  vector <int> stk (1, 0);
  for (int i = 0, cur = 0, cnt = 0, x, k; i < q; ++i) {
    cin >> opt;
    if (opt == '+') {
      cin >> x;
      Modify (root[++cnt], root[cur], 1, N, x);
      fa1[cnt] = cur, cur = cnt;
      int tmp = cur;
      for (int j = 0; j < K && tmp; ++j) tmp = fa1[tmp];
      fa2[cur] = tmp;
      stk.emplace_back (cur);
    }
    else if (opt == '-') {
      cin >> k;
      while (k > K) cur = fa2[cur], k -= K;
      while (k--) cur = fa1[cur];
      stk.emplace_back (cur);
    }
    else if (opt == '!') {
      stk.pop_back ();
      cur = stk.back ();
    }
    else {
      if (cnt >= q - 1) cout << q - 1 << endl;
      else cout << Query (root[cur]) << endl;
      fflush (stdout);
    }
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}