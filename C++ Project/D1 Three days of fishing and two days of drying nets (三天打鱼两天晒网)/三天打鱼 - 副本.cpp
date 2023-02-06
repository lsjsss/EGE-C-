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
//} /*函数DateSum()计算从2010年1月1日开始至指定日期共有几天*/
//
//int Date::DateSum(){	 
//	int OdYear[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//数组OdYear[]表示平年的每月天数 	 
//	int b,i;	 
//	while(year_>2010){	 		 	/*调用Determine()，并将返回值赋予b*/ 	 	
//		b=Determine();	 	
//		for(i=1;i<13;i++)	 	
//		sum_+=OdYear[i];	 		 	/*若此年为闰年，b=1，sum_加1，反之，加0*/	 	
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
//}; /*函数Determine()用于判定年份是平年还是闰年，若闰年，返回值为1，平年为1*/ 
//
//int Date::Determine(){	
//	int a=0;	
//	if((year_%4==0&&year_%100!=0)||year_%400==0)	
//	a=1;	
//	return a;
//} /*函数DateSum()计算从2010年1月1日开始至指定日期共有几天*/
//int Date::DateSum(){	 
//	int OdYear[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//数组OdYear[]表示平年的每月天数 	 
//	int b,i;	 
//	while(year_>2010){	 		 	/*调用Determine()，并将返回值赋予b*/ 	 	
//		b=Determine();	 	
//		for(i=1;i<13;i++)	 	
//		sum_+=OdYear[i];	 		 	/*若此年为闰年，b=1，sum_加1，反之，加0*/	 	
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
//	int OdYear[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//数组OdYear[]表示平年的每月天数	
//	int y,m,d;	
//	int a;	
//	int sum=0;	
//	cout<<"/***输入的日期要求始于2010年1月1日***/"<<endl;	
//	cout<<"请输入年月日格式如(2010 01 01):"<<endl; 		
//	cin>>y>>m>>d;	
//	Date D1(y,m,d);	
//	a=D1.Determine();		/*闰年情况下，平年2月份天数加1*/ 	
//	OdYear[2]=28+a;		/*判断日期是否合法*/ 	
//	if(y<2010||(m<1||m>12)||(d>OdYear[m])){		
//	cout<<"输入日期非法！"<<endl;		
//	exit(1);
//	}	else			
//	sum=D1.DateSum();	
//	cout<<"sum="<<sum<<endl;		/*通过余数计算确定是打鱼还是休息*/	
//	if(sum%5==1||sum%5==2||sum%5==3)	
//	cout<<"此人在 "<<y<<" 年 "<<m<<" 月 "<<d<<" 日打鱼"<<endl; 	
//	else	
//	cout<<"此人在 "<<y<<" 年 "<<m<<" 月 "<<d<<" 日休息"<<endl;	return 0; 
//} 

