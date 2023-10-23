#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int n, q;
string s;
int mx0[N << 2], mx1[N << 2], rev[N << 2], len[N << 2];
int l0[N << 2], r0[N << 2], l1[N << 2], r1[N << 2];

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

void PushUp (int rt) {
  mx0[rt] = max ({mx0[rt << 1], mx0[rt << 1 | 1], 
  r0[rt << 1] + l0[rt << 1 | 1]});
  mx1[rt] = max ({mx1[rt << 1], mx1[rt << 1 | 1],
  r1[rt << 1] + l1[rt << 1 | 1]});

  l0[rt] = (mx0[rt << 1] == len[rt << 1] ? 
  len[rt << 1] + l0[rt << 1 | 1] : l0[rt << 1]);
  l1[rt] = (mx1[rt << 1] == len[rt << 1] ? 
  len[rt << 1] + l1[rt << 1 | 1] : l1[rt << 1]);

  r0[rt] = (mx0[rt << 1 | 1] == len[rt << 1 | 1] ? 
  len[rt << 1 | 1] + r0[rt << 1] : r0[rt << 1 | 1]);
  r1[rt] = (mx1[rt << 1 | 1] == len[rt << 1 | 1] ? 
  len[rt << 1 | 1] + r1[rt << 1] : r1[rt << 1 | 1]);
}

void PushRev (int rt) {
  swap (l0[rt], l1[rt]);
  swap (r0[rt], r1[rt]);
  swap (mx0[rt], mx1[rt]);
  rev[rt] ^= 1;
}

void PushDown (int rt) {
  if (!rev[rt]) return;
  PushRev (rt << 1), PushRev (rt << 1 | 1);
  rev[rt] = 0; 
}

void Build (int rt, int l, int r) {
  len[rt] = r - l + 1;
  if (l == r) {
    if (s[l - 1] == '1') l1[rt] = r1[rt] = mx1[rt] = 1;
    else l0[rt] = r0[rt] = mx0[rt] = 1;
    return;
  }
  int mid = l + r >> 1;
  Build (rt << 1, l, mid);
  Build (rt << 1 | 1, mid + 1, r);
  PushUp (rt);
}

void Reverse (int rt, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) {
    PushRev (rt);
    return;
  }
  PushDown (rt);
  int mid = l + r >> 1;
  if (ql <= mid) Reverse (rt << 1, l, mid, ql, qr);
  if (qr > mid) Reverse (rt << 1 | 1, mid + 1, r, ql, qr);
  PushUp (rt);
}

array <int, 3> Query (int rt, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return (array <int, 3>) {l1[rt], mx1[rt], r1[rt]};
  PushDown (rt);
  int mid = l + r >> 1;
  if (ql <= mid && qr > mid) {
    array <int, 3> ansl = Query (rt << 1, l, mid, ql, qr);
    array <int, 3> ansr = Query (rt << 1 | 1, mid + 1, r, ql, qr);
    array <int, 3> ans;
    ans[0] = (ansl[1] == len[rt << 1] ? len[rt << 1] + ansr[0] : ansl[0]);
    ans[1] = max ({ansl[1], ansr[1], ansl[2] + ansr[0]});
    ans[2] = (ansr[1] == len[rt << 1 | 1] ? len[rt << 1 | 1] + ansl[2] : ansr[2]);
    return ans;
  }
  else if (ql <= mid) {
    return Query (rt << 1, l, mid, ql, qr);
  }
  else {
    return Query (rt << 1 | 1, mid + 1, r, ql, qr);
  }
}

void init () {}

void charming () {
  init ();
  cin >> n >> q;
  cin >> s;
  Build (1, 1, n);
  for (int i = 1, c, l, r; i <= q; ++i) {
    cin >> c >> l >> r;
    if (c == 1) Reverse (1, 1, n, l, r);
    else cout << Query (1, 1, n, l, r)[1] << endl;
  }
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}