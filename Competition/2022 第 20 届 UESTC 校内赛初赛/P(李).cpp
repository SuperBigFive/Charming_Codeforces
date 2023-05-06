#include<bits/stdc++.h>
using namespace std;
int t, n;
const int maxn = 1e4;
struct a{
	int x = -1;
	int y = -1;
	int z = -1;
}b[maxn];
int vis[maxn];
void solve() {
	for (int i = 0 ; i <= maxn/8 ; ++i) {
		for (int j = 0 ; j <= (maxn - i*8)/9 ; ++j) {
			for (int k = 0 ; k <= (maxn - i*8 - j*9)/10 ; ++k) {
				if (!vis[8*i + 9*j + 10*k]) {
					b[8*i + 9*j + 10*k].x = i;
					b[8*i + 9*j + 10*k].y = j;
					b[8*i + 9*j + 10*k].z = k;
					vis[8*i + 9*j + 10*k] = 1;
				}
			}
		}
	}
}
int main(void) {
	scanf("%d", &t);
	solve();
	while(t--) {
		scanf("%d", &n);
		if (b[n].x == -1) printf("-1\n");
		else printf("%d %d %d\n", b[n].x, b[n].y, b[n].z);
	}
	return 0;
}
