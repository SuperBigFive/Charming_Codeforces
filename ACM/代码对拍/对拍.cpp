#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;  

void init () {}

void charming () {
	int t = 10000;  
  while (t--) {  
  	int tim = clock ();
    system ("data.exe > data.txt");  
    system ("accode.exe < data.txt > accode.txt");  
    system ("mycode.exe < data.txt > mycode.txt");  
    cout << clock () - tim << "ms" << endl;
		if(system ("fc accode.txt mycode.txt")) break;  
  }  
  if (t < 0) cout << "no error" << endl;  
  else cout << "error" << endl;  
	system("pause");  
}

signed main () {
	charming ();
	return 0;
}
 