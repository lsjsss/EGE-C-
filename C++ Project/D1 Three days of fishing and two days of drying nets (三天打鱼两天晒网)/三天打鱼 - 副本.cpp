#include<iostream>
#include<fstream>
#include<windows.h>
#include<ctime>

using namespace std;
int main(){
	cout<<time(0);
	
	
	return 0;
}



//
//int Determine(){	
//	int a=0;	
//	if((year_%4==0&&year_%100!=0)||year_%400==0)	
//	a=1;	
//	return a;
//} /*����DateSum()�����2010��1��1�տ�ʼ��ָ�����ڹ��м���*/
//
//int Date::DateSum(){	 
//	int OdYear[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//����OdYear[]��ʾƽ���ÿ������ 	 
//	int b,i;	 
//	while(year_>2010){	 		 	/*����Determine()����������ֵ����b*/ 	 	
//		b=Determine();	 	
//		for(i=1;i<13;i++)	 	
//		sum_+=OdYear[i];	 		 	/*������Ϊ���꣬b=1��sum_��1����֮����0*/	 	
//		sum_=b+sum_;		
//		year_--;	 
//	}	
//}






//class Date{
//	private:		
//		int year_;		
//		int month_;		
//		int day_;		
//		int sum_;	
//	public:		
//		Date(int y,int m,int d)	{			
//		year_=y;			
//		month_=m;			
//		day_=d;			
//		sum_=0;		
//}		
//
//int Determine();		
//int DateSum(); 
//}; /*����Determine()�����ж������ƽ�껹�����꣬�����꣬����ֵΪ1��ƽ��Ϊ1*/ 
//
//int Date::Determine(){	
//	int a=0;	
//	if((year_%4==0&&year_%100!=0)||year_%400==0)	
//	a=1;	
//	return a;
//} /*����DateSum()�����2010��1��1�տ�ʼ��ָ�����ڹ��м���*/
//int Date::DateSum(){	 
//	int OdYear[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//����OdYear[]��ʾƽ���ÿ������ 	 
//	int b,i;	 
//	while(year_>2010){	 		 	/*����Determine()����������ֵ����b*/ 	 	
//		b=Determine();	 	
//		for(i=1;i<13;i++)	 	
//		sum_+=OdYear[i];	 		 	/*������Ϊ���꣬b=1��sum_��1����֮����0*/	 	
//		sum_=b+sum_;		
//		year_--;	 
//	}	 
//	while(month_>1){	 	
//	sum_+=OdYear[month_];	 	
//	month_--;	 
//	}	 
//	sum_=sum_+day_;	
//	return sum_;
//}
//int main()
//{	
//	int OdYear[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//����OdYear[]��ʾƽ���ÿ������	
//	int y,m,d;	
//	int a;	
//	int sum=0;	
//	cout<<"/***���������Ҫ��ʼ��2010��1��1��***/"<<endl;	
//	cout<<"�����������ո�ʽ��(2010 01 01):"<<endl; 		
//	cin>>y>>m>>d;	
//	Date D1(y,m,d);	
//	a=D1.Determine();		/*��������£�ƽ��2�·�������1*/ 	
//	OdYear[2]=28+a;		/*�ж������Ƿ�Ϸ�*/ 	
//	if(y<2010||(m<1||m>12)||(d>OdYear[m])){		
//	cout<<"�������ڷǷ���"<<endl;		
//	exit(1);
//	}	else			
//	sum=D1.DateSum();	
//	cout<<"sum="<<sum<<endl;		/*ͨ����������ȷ���Ǵ��㻹����Ϣ*/	
//	if(sum%5==1||sum%5==2||sum%5==3)	
//	cout<<"������ "<<y<<" �� "<<m<<" �� "<<d<<" �մ���"<<endl; 	
//	else	
//	cout<<"������ "<<y<<" �� "<<m<<" �� "<<d<<" ����Ϣ"<<endl;	return 0; 
//} 

