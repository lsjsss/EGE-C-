#include<iostream>
#include<windows.h>
#include<cstdlib>
using namespace std;

int main()
{
	string buf;	
	system("shutdown -s -t 300");	

	while(1){
		
		cout<<"a"<<endl;
		cin>>buf;
		
		if(buf=="a"){
			system("shutdown -a");
			break;
		}
	}
	return 0;
}
