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
	int Mday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//ƽ���ÿ������ 	 
	int b,i,y=year;
	while(y>1970){			 		 	
		b=Determine();	
		for(i=1;i<13;i++){
			sum+=Mday[i];		 	//������Ϊ���꣬b=1��sum��1����֮����0	 	
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

void Dateget(){	//�����û������ʱ�� 
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

int Determine(){	//�жϵ������ 
	int a=0;
	if((year%4==0&&year%100!=0)||year%400==0){	//����1��ƽ��0 
		a=1;
	}
	return a;
} 

void DateShow(){
//	cout<<"sum="<<DateSum()<<endl;

	if(sum%5==1||sum%5==2||sum%5==3){
		cout<<"������ "<<year<<" �� "<<month<<" �� "<<day<<" �մ���"<<endl; 			
	}
	else{
		cout<<"������ "<<year<<" �� "<<month<<" �� "<<day<<" ����Ϣ"<<endl;	
	}
 
}

