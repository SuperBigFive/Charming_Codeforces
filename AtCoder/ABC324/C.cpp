#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;

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

int n, m;
string t, s;

void init () {}

void charming () {
  init ();
  cin >> n >> t, m = t.size ();

  auto Check1 = [&] (string &s) -> bool {
    int cnt = 0;
    for (int i = 0; i < m; ++i) if (t[i] != s[i]) ++cnt;
    return cnt <= 1;
  };

  auto Check2 = [&] (string &s) -> bool {
    bool flag = false;
    for (int i = 0, j = 0; i < m && j < m - 1;) {
      if (t[i] != s[j]) {
        if (flag) return false;
        else flag = true, ++i;
      }
      else ++i, ++j;
    }
    return true;
  };

  auto Check3 = [&] (string &s) -> bool {
    bool flag = false;
    for (int i = 0, j = 0; i < m && j < m + 1;) {
      if (t[i] != s[j]) {
        if (flag) return false;
        else flag = true, ++j;
      }
      else ++i, ++j;
    }    
    return true;
  };

  vector <int> ans;
  for (int i = 1, siz; i <= n; ++i) {
    cin >> s, siz = s.size ();
    if (siz == m && Check1 (s)) ans.emplace_back (i);
    else if (siz == m - 1 && Check2 (s)) ans.emplace_back (i);
    else if (siz == m + 1 && Check3 (s)) ans.emplace_back (i); 
  }
  cout << (int) ans.size () << endl;
  for (int x : ans) cout << x << " \n"[x == ans.back ()];
}

signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
  return 0;
}