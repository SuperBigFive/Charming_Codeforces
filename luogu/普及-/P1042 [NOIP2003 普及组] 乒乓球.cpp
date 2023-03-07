#include<stdio.h>
void sorce_eleven(int rule,char* str1);

int main() {
	char str[62501];
	str[0] = 0;
	for (int i = 1; str[i - 1] != 'E'; ++i)
		scanf_s("%c", &str[i]);
	sorce_eleven(11,str);
	printf_s("\n");
	sorce_eleven(21, str);
	return 0;
}

void sorce_eleven(int rule,char* str1) {
	int i = 0, win = 0, lose = 0;;
	do{
		++i;
		if (str1[i] == 'W')
			++win;
		if(str1[i]=='L')
			++lose;
		if ((win >= rule||lose >= rule)&&(win-lose>=2||win-lose<=-2)) {
			printf_s("%d:%d\n", win, lose);
			win = 0; lose = 0;
		}
	} while (str1[i] != 'E');
	printf_s("%d:%d\n", win, lose);
}