#include <bits/stdc++.h>
#define ll __int128
using namespace std;
/*__int128类型数据的输入*/ 
__int128 read () {
  __int128 x = 0, f = 1;
  char ch = getchar ();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar ();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar ();
  }
  return x * f;
}
 
/*__int128类型数据的输出*/ 
void output (__int128 x){
  if (x < 0) putchar ('-'), x = -x;
  if (x > 9) output (x / 10);
  putchar (x % 10 + '0');
}

void charming () {
	cout << "测试" << endl;
	ll x = 114514;
	output (x);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
