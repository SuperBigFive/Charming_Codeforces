//正规构造版(汪)
#include<bits/stdc++.h>
#define INF 2147483647
#define N 500100
#define M 500100
const int mod=1e9+7;
using namespace std;
typedef long long ll;
int a[N];
char s5[6]={"10001"};
char s6[7]={"011001"};
char s7[8]={"0101001"};
char s8[9]={"10011001"};
char s9[10]={"100110001"};
void Print(int which)
{
    if(which==5)
        printf("%s",s5);
    if(which==6)
        printf("%s",s6);
    if(which==7)
        printf("%s",s7);
    if(which==8)
        printf("%s",s8);
    if(which==9)
        printf("%s",s9);
}
void solve()
{
    int n;
    scanf("%d",&n);
    if(n==2)
    {
        puts("10");
        return;
    }
    if(n==3)
    {
        puts("Unlucky");
        return;
    }
    if(n==4)
    {
        puts("1000");
        return;
    }
    int r=n%5+5;
    int t=(n-r)/5;
    Print(r);
    for(int i=1;i<=t;i++)
        Print(5);
}
int main()
{
    solve();
    return 0;
}


/*暴力打表版(铭)
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 1e4 + 5;

int n, tot;
bool ok, flag;
int num[maxn], tmp_num[maxn], last_num[maxn], small[maxn][maxn];

bool check () {
	tot = 0;
	ok = false;
	for (int i = 1; i <= n; ++i) {
		tmp_num[i] = num[i];
		if (num[i]) ok = true;
	}
	if (!ok) return false;
	for (int i = 1; i <= n; ++i) {
		last_num[i] = tmp_num[i];
	}
	while (tot < 2) {
		++tot;
		for (int i = 1; i <= n; ++i) {
			if (last_num[i + 1] == 1 && last_num[i - 1] != 1 && last_num[i] != 1) {
				tmp_num[i] = 1;
			}
			else if (last_num[i - 1] == 1 && last_num[i + 1] != 1 && last_num[i] != 1) {
				tmp_num[i] = 1;
			}
			else tmp_num[i] = 0;
		}
		ok = true;
		for (int i = 1; i <= n; ++i) {
			if (tmp_num[i] != num[i]) {
				ok = false;
				break;
			}
		}
		for (int i = 1; i <= n; ++i) {
			last_num[i] = tmp_num[i];
		}
		if (ok) return true;
	}
	return false;
}

void dfs (int now) {
	if (flag) return;
	if (now > n) {
		if (check ()) {
			for (int i = 1; i <= n; ++i) {
				small[n][i] = num[i];
			}
			small[n][0] = 2;
			flag = true;
			//exit (0);
		}
		return;
	}
	num[now] = 1;
	dfs (now + 1);
	if (flag) return;
	num[now] = 0;
	dfs (now + 1);
}

void init () {
	memset (num, 0, sizeof num);
	memset (last_num, 0, sizeof last_num);
	memset (tmp_num, 0, sizeof tmp_num);
}

void charming () {
	int com;
	for (int i = 4; i <= 30; ++i) {
		n = i;
		com = 0;
		if (i > 8) {
			for (int j = 1; j <= maxn; ++j) {
				if (small[i - 1][j] == small[i - 2][j]) ++com;
				else break;
			}
		}
		flag = false;
		dfs (max ((ll)1, com - 1));
		if (!small[0]) {
			cout << i << ':' << "Unlucky" << endl;
			continue;
		}
		cout << i << ':' << 2 << ' ';
		for (int j = 1; j <= n; ++j) {
			cout << small[n][j];
		}
		cout << endl;
	}
}

signed main () {
	//freopen ("output.out", "w", stdout);
	charming ();
	return 0;
}
*/