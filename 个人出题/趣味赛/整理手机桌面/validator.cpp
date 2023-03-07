#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main (int argc, char* argv[]) {
  registerValidation (argc, argv);
  int n = inf.readInt (1, 2'000, "n");
  inf.readSpace ();
  int m = inf.readInt (1, 2'000, "m");
  inf.readSpace ();
  int k = inf.readInt (0, n * m, "k");
  inf.readEoln ();
  int kk = 0;
  for (int i = 0; i < n; ++i) {
  	for (int j = 0; j < m; ++j) {
  		char ch = inf.readChar ();
  		if (ch != '0' && ch != '1') return -1;
  		if (ch == '1') ++kk;
  	}
  	inf.readEoln ();
  }
  if (kk != k) return -1;
  inf.readEof();
}
