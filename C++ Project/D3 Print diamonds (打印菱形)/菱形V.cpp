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
		for (int j = 0; j < i + 1; j++){       // �°��������� �ո����Խ��Խ�� ѭ������Ҳ�͸�������
			cout << " ";
		}
		for(int j = 0; j < 2 * ( n - 1 ) - (1 + 2 * i); j++){	//�°��������� ���Ǹ������εݼ� ѭ������Ҳ�͸��ż���		
			cout << "*";		// ���ǵĸ����� 2*n-1  2*n-3 .....2*n-��1+2*i�� �Ȳ����еݼ�   // ��Ϊ���°���n-1��ʼ�� ���������N=n-1
		}
		cout << endl;
	}
} 
