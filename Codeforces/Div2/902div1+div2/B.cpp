#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, p;
pair <int, int> people[N];

char getch () {
  static char buf[100000], *s1, *s2;
  return (s1 == s2) && (s2 = (s1 = buf) +
  fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++;
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {if (ch == '-') w = -1; ch = getch ();}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

void init () {}

void charming () {
  init ();
  n = read (), p = read ();
  for (int i = 1; i <= n; ++i) {
    people[i].first = read ();
  }
  for (int i = 1; i <= n; ++i) {
    people[i].second = read ();
  }
  sort (people + 1, people + 1 + n, [] (pair <int, int> x,
  pair <int, int> y) {return x.second < y.second;});
  int ans = p, remain = n - 1;
  for (int i = 1; i <= n; ++i) {
    if (people[i].second >= p) break;
    else {
      if (people[i].first >= remain) {
        ans += people[i].second * remain; 
        remain = 0; break;
      }
      else ans += people[i].first * people[i].second, remain -= people[i].first;
    }
  }
  ans += remain * p;
  printf ("%lld\n", ans);
}

signed main () {
  t = read ();
  while (t--) charming ();
  return 0;
}
