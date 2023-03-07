#include<bits/stdc++.h>
using namespace std;
int opr[10][10];
int find_e(int a,int b,int c,int d){
	return opr[opr[opr[opr[0][a]][b]][c]][d];
}
int check(int a,int b,int c,int d,int e){
	return opr[find_e(a,b,c,d)][e];
}
int main()
{
	int cnt=0;
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	scanf("%d",&opr[i][j]);
	for(int a=0;a<10;a++)
	for(int b=0;b<10;b++)
	for(int c=0;c<10;c++)
	for(int d=0;d<10;d++){
		int mk=1,e=find_e(a,b,c,d);
		for(int i=0;i<10&&mk;i++){
			if(i!=a&&!check(i,b,c,d,e))mk=0;
			if(i!=b&&!check(a,i,c,d,e))mk=0;
			if(i!=c&&!check(a,b,i,d,e))mk=0;
			if(i!=d&&!check(a,b,c,i,e))mk=0;
			if(i!=e&&!check(a,b,c,d,i))mk=0;
		}
		if(!mk){cnt++;continue;}
		if(a!=b&&!check(b,a,c,d,e))mk=0;
		if(b!=c&&!check(a,c,b,d,e))mk=0;
		if(c!=d&&!check(a,b,d,c,e))mk=0;
		if(d!=e&&!check(a,b,c,e,d))mk=0;
		if(!mk)cnt++;
	}
	printf("%d",cnt);
	return 0;
}