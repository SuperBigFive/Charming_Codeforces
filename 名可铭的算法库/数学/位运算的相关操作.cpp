#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

bool isPowerOf2 (int num) {
	//判断一个数是否是2的非负整数次幂 
	return (num > 0) && !(num & (num - 1));
}

bool modPowerOf2 (int num, int mod) {
	//对2的非负整数次幂取模 
	return num & (mod - 1);
} 

bool Abs (int num) {
	//可能会比三目更快 
	return (num ^ (num >> 31) - (num >> 31));
}

bool isSameSign (int x, int y) {
	//可能会比三目更快 
	return (x ^ y) >= 0;
} 

int Bigger (int a, int b) {
	//可能会比三目更快 
	return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
}

int Smaller (int a, int b) {
	//可能会比三目更快
	return a & ((a - b) >> 31) + b & (~(a - b) >> 31);
} 

int getBit (int num, int digit) {
	//获取 num 的第 digit 数位 
	return (num >> (digit - 1)) & 1;
}

int set0 (int num, int digit) {
	//把 num 的第 digit 数位设置为0 
	return num & ~(1 << (digit - 1)); 
}

int set1 (int num, int digit) {
	//把 num 的第 digit 数位设置为1 
	return num | (1 << (digit - 1));
} 

int flapBit (int num, int digit) {
	//把 num 的第 digit 数位取反
	return num ^ (1 << (digit - 1)); 
} 

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cout << ~0 << endl;
	return 0;
}
