#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 15, maxm = 1e6 + 15;

int tot, ans;
int i, j, k;
int len1, len2;
char str1[maxn], str2[maxm];
int nex[maxn];

void init () {
	ans = 0;
	len1 = len2 = 1;
}

bool check () {
	if (str1[i] == str2[j+1]) j++;
	if (j == len2 - 1) {
		j = nex[j];
		return true;
	}
	return false;
}

void build_nex () {
	for (i = 2, j = 0; i < len2; ++i) {
		while (j && (str2[i] != str2[j + 1])) j = nex[j];
		if (str2[i] == str2[j + 1]) j++;
		nex[i] = j;
	}
}

void solve () {
	cin >> str1 + 1 >> str2 + 1;
	init ();
	while (str1[len1] != '\0') ++ len1;
	while (str2[len2] != '\0') ++ len2;
	build_nex ();
	for (i = 1, j = 0; i < len1; ++i) {
		while (j && str1[i] != str2[j+1]) j = nex[j];
		if (check ()) ++ans;
	}
	cout << ans << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	solve (); 
}
/*int main() {
	scanf("%s",s+1);
	scanf("%s",p+1);
	int lens=1,lenp=1;
	while(s[lens]!='\0') ++lens;
	while(p[lenp]!='\0') ++lenp;
	--lens,--lenp;
	for (int i = 2, j = 0; i <=lenp; i++) {
		while (j && p[i] != p[j + 1])j = ne[j];
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}

	for (int i = 1, j = 0; i <= lens; i++) {
		while (j && s[i] != p[j + 1])j = ne[j];
		if (s[i] == p[j + 1])j++;
		if (j == lenp) {
			pos[++tot]=i-lenp+1;
			j = ne[j];
		}
	}
	for(int i=1;i<=tot;++i) printf("%d\n",pos[i]);
	for(int i=1;i<=lenp;++i) printf("%d ",ne[i]);
	return 0;
}*/
