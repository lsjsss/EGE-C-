#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<windows.h>

using namespace std;
int main()
{
	char buf[128]={0};
	while(1)
	{
		Sleep(500);
		sprintf(buf,"color %d%d",rand()%10,rand()%10);
		system(buf);
	}
	return 0;
 } 
