#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"enter hang:";
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			cout<<" ";
		} 
		for(int j=1;j<=2*i-1;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
		
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < i + 1; j++){       // 下半层从上往下 空格个数越来越多 循环次数也就跟着增多
			cout << " ";
		}
		for(int j = 0; j < 2 * ( n - 1 ) - (1 + 2 * i); j++){	//下半层从上往下 星星个数依次递减 循环次数也就跟着减少		
			cout << "*";		// 星星的个数是 2*n-1  2*n-3 .....2*n-（1+2*i） 等差数列递减   // 因为是下半层从n-1开始的 所以这里的N=n-1
		}
		cout << endl;
	}
} 
