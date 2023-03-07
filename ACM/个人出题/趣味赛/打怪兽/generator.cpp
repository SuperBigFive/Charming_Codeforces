#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;

signed main(int argc, char **argv) {
  registerGen (argc, argv, 1);
  
  int n = atoi (argv[1]);
  int mx = atoi (argv[2]);
  println (n);
  vector <int> arr (n);
  for (int i = 0; i < n; ++i) {
  	arr[i] = rnd.next (1, mx);
  }
  println (arr);
}
