#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;

int n;

void init () {}

void charming () {
  init ();
  string s;
  cin >> s, n = s.size (), s = '#' + s;
  vector <int> nxt (n + 5);
  for (int i = n; i >= 1; --i) {
    if (i < n && s[i] == s[i + 1]) nxt[i] = nxt[i + 1];
    else nxt[i] = i;
  }
  vector <int> SecondIsSmall (n + 5);
  vector <pair <string, int> > ans (n + 5);
  for (int i = n; i >= 1; --i) {
    if ((nxt[i] - i) & 1) {
      if (!ans[nxt[i] + 1].first.size () || ans[nxt[i] + 1].first[0] < s[i]
          || (ans[nxt[i] + 1].first[0] == s[i] && SecondIsSmall[nxt[i] + 1])) {
        ans[i] = ans[nxt[i] + 1];
        SecondIsSmall[i] = SecondIsSmall[nxt[i] + 1];
      }
      else {
        ans[i].first = s.substr (i, min (10ll, nxt[i] - i + 1)) + ans[nxt[i] + 1].first;
        ans[i].second = nxt[i] - i + 1 + ans[nxt[i] + 1].second;
      }
    }
    else {
      if (!ans[nxt[i] + 1].first.size () || ans[nxt[i] + 1].first[0] < s[i]
          || (ans[nxt[i] + 1].first[0] == s[i] && SecondIsSmall[nxt[i] + 1])) {
        ans[i].first = s[i] + ans[nxt[i] + 1].first;
				ans[i].second = 1 + ans[nxt[i] + 1].second;
        SecondIsSmall[i] = 1;
      }
      else {
        ans[i].first = s.substr (i, min (10ll, nxt[i] - i + 1)) + ans[nxt[i] + 1].first;
        ans[i].second = nxt[i] - i + 1 + ans[nxt[i] + 1].second;
      }
    }
    if (ans[i].first.size () > 10) {
      int siz = ans[i].first.size ();	
      ans[i].first = ans[i].first.substr (0, 5) + "..." + ans[i].first[siz - 2] + ans[i].first[siz - 1];
    }
  }
	for (int i = 1; i <= n; ++i) {
		cout << ans[i].second << " " << ans[i].first << " " << endl;
	}
}

signed main () {
  charming ();
  return 0;
}
