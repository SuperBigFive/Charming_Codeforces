#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const ll INF = 2e18;

ll xa, ya, xb, yb, xc, yc;

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

ll read () {
  ll x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

ll Move (ll x, ll y) {
  ll dis = INF;
  if (x == xb) {
    if (xa != xb) dis = abs (x - xa) + abs (y - ya);
    else if ((y > yb && ya < yb) || (y < yb) && (ya > yb)) dis = abs (y - ya) + 2;
    else dis = abs (y - ya);
  } else {
    if (ya != yb) dis = abs (x - xa) + abs (y - ya);
    else if ((x > xb && xa < xb) || (x < xb) && (xa > xb)) dis = abs (x - xa) + 2;
    else dis = abs (x - xa);
  }
  return dis;
}

void init () {}

void charming () {
  init ();
  xa = read (), ya = read ();
  xb = read (), yb = read ();
  xc = read (), yc = read ();
  ll ans, dx = (xc > xb ? -1 : 1), dy = (yc > yb ? -1 : 1);
  if (xb == xc && yb == yc) printf ("0\n");
  else if (xb == xc) {
    ans = Move (xb, yb + dy) + abs (yc - yb);
    printf ("%lld\n", ans);
  }
  else if (yb == yc) {
    ans = Move (xb + dx, yb) + abs (xc - xb);
    printf ("%lld\n", ans);
  }
  else {
    ans = min (Move (xb, yb + dy), Move (xb + dx, yb)) 
    + abs (xc - xb) + abs (yc - yb) + 2;
    printf ("%lld\n", ans); 
  }
}

signed main () {
  charming ();
  return 0;
}
