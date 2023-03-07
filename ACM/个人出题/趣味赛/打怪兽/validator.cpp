#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main (int argc, char* argv[]) {
  registerValidation (argc, argv);
  int n = inf.readInt (1, 100'000, "n");
  inf.readEoln ();
  for (int i = 1; i <= n; ++i) {
  	int h = inf.readInt (1, 10'000, "h");
  	if (i < n) inf.readSpace ();
  	else inf.readEoln ();
  }
  inf.readEof();
}
