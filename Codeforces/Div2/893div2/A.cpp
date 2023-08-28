#include <bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N = 2e5 + 5;

char getch () { 
	static char buf[100000], *s1, *s2; 
	return (s1 == s2) && (s2 = (s1 = buf) + 
	fread (buf, 1, 100000, stdin)), s1 == s2 ? EOF : *s1++; 
}

int read () {
  int x = 0, w = 1; char ch = 0;
  while (!isdigit (ch)) {ch = getch (); if (ch == '-') w = -1;}
  while (isdigit (ch)) x = x * 10 + ch - '0', ch = getch ();
  return x * w;
}

int t, a, b, c;

void init () {}

void charming () {
	init ();
	a = read (), b = read (), c = read ();
  a += (c + 1) / 2, b += c / 2;
  if (a <= b) puts ("Second");
  else puts ("First");
}

signed main () {
	t = read ();
  while (t--) charming ();
	return 0;
}