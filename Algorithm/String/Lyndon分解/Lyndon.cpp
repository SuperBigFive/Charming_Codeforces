#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n;

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

vector <pair <int, int> > Lyndon_duval (string &s) {
  int i = 0, n = s.size ();
  vector <pair <int, int> > ans;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j]) k = i;
      else ++k;
      ++j;
    }
    while (i <= k) {
      ans.emplace_back (make_pair (i, j - k));
      i += j - k;
    }
  }
  return ans;
}

// vector <pair <int, int> > Lyndon_duval () {
//   int i = 0;
//   vector <pair <int, int> > ans;
//   while (i < (n << 1)) {
//     int j = i + 1, k = i;
//     while (j < (n << 1) && a[k] <= a[j]) {
//       if (a[k] < a[j]) k = i;
//       else ++k;
//       ++j;
//     }
//     while (i <= k) {
//       ans.emplace_back (i, j - k);
//       i += j - k;
//     }
//   }
//   return ans;
// }

void init () {}

void charming () {
  init ();
  string s; cin >> s;
  vector <pair <int, int> > pos = Lyndon_duval (s);
  int ans = 0;
  for (auto [x, y] : pos) ans ^= x + y;
  cout << ans << endl;
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}