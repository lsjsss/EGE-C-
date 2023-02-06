#include "stdafx.h"
#include "iostream"
#include "string" 
using namespace std;

int main(){	/*定义生日变量*/	
int  value_birth_month;	
int  value_birth_date;	/*星座*/	
string value_constell;	
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
int constell_dates[]{ 20,19,21,20,21,22,23,23,23,24,23,22 };	
cout << "请输入月份：";	
cin >> value_birth_month;	
cout << "请输入日期：";	
cin >> value_birth_date; 	/*第一维输出月份，第二维由生日的日期/每个月对应的分割日期（constell_dates）,	   为0就表示一个月中的前一个星座，否则为后一个星座，	比如生日为5月6号，则对应输出 constells[4][0] 对应金牛座*/	
cout << constells[value_birth_month - 1][value_birth_date / constell_dates[value_birth_month]] << endl;	
return 0;
}

