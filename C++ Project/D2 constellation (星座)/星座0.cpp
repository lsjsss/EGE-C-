#include <iostream> 
using namespace std;

int month,day,x,y;
string constells[12][2]={0,0};

void getBirthday();
void setconstells();
void searchconstells();
int dsearch();
void showconstells();


int main(){	
setconstells();	
getBirthday();
searchconstells();
showconstells();
}

void setconstells(){
	string constells[12][2] = {	{ "摩羯座","水瓶座" },//一月	
								{ "水瓶座","双鱼座" },//二月	
								{ "双鱼座","白羊座" },//三月	
								{ "白羊座","金牛座" },//四月
								{ "金牛座","双子座" },//五月
								{ "双子座","巨蟹座" },//六月	
								{ "巨蟹座","狮子座" },//七月
								{ "狮子座","处女座" },//八月
								{ "处女座","天秤座" },//九月
								{ "天秤座","天蝎座" },//十月	
								{ "天蝎座","射手座" },//十一月	
								{ "射手座","摩羯座" },//十一月	
							};	//每个月有两个星座，数组中的值对应每个月中两个星座的分割日期
}

void getBirthday(){
	cout<<"please enter Birthday(month and day):";
	cin>>month>>day;
}

void searchconstells(){
	for(int i=0;i<12;i++){
		for(int j=0;j<2;j++){
			if(month==i&&dsearch()==j){
				x=i;y=j;
			}
		}
	}
}

int dsearch(){
	if(month==1||month==4){
		if(day<=19){return 0;}
		else{return 1;}
	}
	else if(month==2){
		if(day<=18){return 0;}
		else{return 1;}
	}
	else if(month==3||month==5){
		if(day<=20){return 0;}
		else{return 1;}
	}
	else if(month==6||month==12){
		if(day<=21){return 0;}
		else{return 1;}
	}
	else if(month==7||month==11||month==8||month==9){
		if(day<=22){return 0;}
		else{return 1;}
	}
	else if(month==10){
		if(day<=23){return 0;}
		else{return 1;}
	}
}

void showconstells(){
	cout<<constells[x][y]<<endl;
}

