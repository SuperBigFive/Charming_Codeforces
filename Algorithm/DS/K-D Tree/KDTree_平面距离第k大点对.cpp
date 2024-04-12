#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

struct Point {
  int x, y;

  Point () {}
  Point (int x, int y) : x (x), y (y) {}

  ll getDis (Point other) {
    ll dx = x - other.x, dy = y - other.y;
    return dx * dx + dy * dy;
  }

}point[N];

priority_queue <ll, vector <ll>, greater <ll> > pq;

struct KDTree {
  int ls[N], rs[N];
  int minx[N], maxx[N], miny[N], maxy[N];

  KDTree () {minx[0] = miny[0] = (1ll << 31) - 1;}

  void Maintain (int u) {
    minx[u] = min ({point[u].x, minx[ls[u]], minx[rs[u]]});
    maxx[u] = max ({point[u].x, maxx[ls[u]], maxx[rs[u]]});
    miny[u] = min ({point[u].y, miny[ls[u]], miny[rs[u]]});
    maxy[u] = max ({point[u].y, maxy[ls[u]], maxy[rs[u]]});
  }

  ll getMaxDis (int id1, int id2) {
    ll x1 = point[id1].x, y1 = point[id1].y;
    ll dx = max (abs (x1 - minx[id2]), abs (x1 - maxx[id2]));
    ll dy = max (abs (y1 - miny[id2]), abs (y1 - maxy[id2]));
    return dx * dx + dy * dy;
  }

  int Build (int l, int r, int st) {
    int mid = l + r >> 1;
    if (st) {
      nth_element (point + l, point + mid, point + r + 1, 
      [] (Point p1, Point p2) {return p1.x < p2.x;});
    }
    else {
      nth_element (point + l, point + mid, point + r + 1,
      [] (Point p1, Point p2) {return p1.y < p2.y;});
    }
    if (l <= mid - 1) ls[mid] = Build (l, mid - 1, st ^ 1);
    if (r >= mid + 1) rs[mid] = Build (mid + 1, r, st ^ 1);
    Maintain (mid);
    return mid;
  }

  void Query (int l, int r, int u) {
    int mid = l + r >> 1;
    if (getMaxDis (u, mid) < pq.top ()) return;
    ll dis = point[u].getDis (point[mid]);
    if (dis > pq.top ()) pq.pop (), pq.push (dis);
    ll ldis = -1, rdis = -1;
    if (l <= mid - 1) Query (l, mid - 1, u);
    if (r >= mid + 1) Query (mid + 1, r, u);
  }
} tree;

int n, k;

void charming () {
  cin >> n >> k;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    point[i] = Point (x, y);
  }
  tree.Build (1, n, 0);
  for (int i = 0; i < (k << 1); ++i) pq.push (0);
  for (int i = 1; i <= n; ++i) tree.Query (1, n, i);
  cout << pq.top () << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}