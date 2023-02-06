#include<iostream>
using namespace std;

int year=1970,month=1,day=1,sum=0; 
int DateSum();
void Dateget();
int Determine();
void DateShow();

int main(){
	Dateget();
	DateShow();
	return 0;
}

int DateSum(){
	int Mday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//平年的每月天数 	 
	int b,i,y=year;
	while(y>1970){			 		 	
		b=Determine();	
		for(i=1;i<13;i++){
			sum+=Mday[i];		 	//若此年为闰年，b=1，sum加1，反之，加0	 	
			sum=b+sum;
			y--;
		}
	}
	
	while(month>1){
		sum+=Mday[month];	
		month--;
	}
	
	sum+=day;
	return sum;
}

void Dateget(){	//接收用户输入的时间 
	cout<<"please enter a date, 3days dayu, 2days shaiwang:"<<endl;
	cin>>year>>month>>day;
	
	if(year>=1970&&month>=1&&day>=1&&month<=12&&day<=31){
		if((month==4||month==6||month==9||month==11)&&day!=31){
			if(month==2&&Determine()==1&&day<=29||month==2&&Determine()==0&&day<=28){
				DateSum();
			}
		}
	}
	else{
		cout<<"please enter the right Date."<<endl;
		Dateget();
	}
}

int Determine(){	//判断当年年份 
	int a=0;
	if((year%4==0&&year%100!=0)||year%400==0){	//闰年1，平年0 
		a=1;
	}
	return a;
} 

void DateShow(){
//	cout<<"sum="<<DateSum()<<endl;

	if(sum%5==1||sum%5==2||sum%5==3){
		cout<<"此人在 "<<year<<" 年 "<<month<<" 月 "<<day<<" 日打鱼"<<endl; 			
	}
	else{
		cout<<"此人在 "<<year<<" 年 "<<month<<" 月 "<<day<<" 日休息"<<endl;	
	}
 
}

