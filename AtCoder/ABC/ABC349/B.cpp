#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int M = 26;

string s;
int cnt1[M], cnt2[N];

void charming () {
  cin >> s;
  for (char ch : s) {
    int ch2num = ch - 'a';
    ++cnt1[ch2num];
  }
  for (int i = 0; i < M; ++i) ++cnt2[cnt1[i]];
  bool ok = true;
  for (int i = 1; i < N; ++i) {
    if (cnt2[i] != 0 && cnt2[i] != 2) {ok = false; break;}
  }
  if (ok) puts ("Yes");
  else puts ("No");
}

signed main () {
  charming ();
  return 0;
}