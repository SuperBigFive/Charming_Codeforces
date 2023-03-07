#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;

signed main(int argc, char **argv) {
  registerGen (argc, argv, 1);
  
  vector <int> d (3);
  d[0] = atoi (argv[1]);
  d[1] = atoi (argv[2]);
  int mx = atoi (argv[3]);
  d[2] = 0;
  vector <vector <char> > arr (d[0]);
  for (int i = 0; i < d[0]; ++i) {
  	for (int j = 0; j < d[1]; ++j) {
  		int r = rnd.next (1, mx);
  		if (r <= 1) arr[i].emplace_back ('1'), ++d[2];
  		else arr[i].emplace_back ('0'); 
  	}
  }
  println (d);
  for (int i = 0; i < d[0]; ++i) {
  	for (int j = 0; j < d[1]; ++j) {
  		printf ("%c", arr[i][j]);
  	}
  	printf ("\n");
  }
}
