#include<cstdio>
int t;
char a[10], b[10], vis[50];
int num1[50], num2[50];
int main(void) {
	scanf("%d", &t);
	while(t--) {
		for (int i = 1 ; i <= 40 ; ++i) vis[i] = num1[i] = num2[i] = 0;
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		for (int i = 1 ; i <= 5 ; ++i) {
			num1[a[i] - 'a' + 1]++;
			num2[b[i] - 'a' + 1]++;
		}
		for (int i = 1 ; i <= 5 ; ++i) {
			if (a[i] == b[i]) printf("g");
			else if (num1[a[i] - 'a' + 1] > num2[a[i] - 'a' + 1]) printf("x");
			else printf("y");
		}
		printf("\n");
	}
	return 0;
}
