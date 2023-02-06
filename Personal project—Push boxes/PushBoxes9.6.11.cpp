#include<iostream>
#include<graphics.h>
#include<ctime>
#include <cstdlib>
#include<windows.h>
#include<cstdio>

using namespace std;

//int hour = 0, min = 0, sec = 0;
int guan=0;//关卡数据
int foot=0;//步数 
int xpeople,ypeople;//记录人物位置信息 

int map[6][15][15]={//三维数组		//0->空白&可移动的位置   //1->墙//2->人//3->箱子//4->位置,目的地   24 34
					{//1
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 0, 0, 0, 0, 1, 4, 1, 0, 0, 4, 1 },
						{ 1, 0, 3, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 0, 0, 3, 1, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1 },
						{ 1, 0, 0, 0, 4, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
						{ 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
					},
					{//2
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 4, 0, 0, 0, 0, 3, 1, 1, 1, 1, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 3, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
						{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
						{ 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }					
					},
					{//3
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 1, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4, 1 },
						{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 1, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 4, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 },
						{ 1, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }						
					},
					{//4
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 3, 0, 0, 0, 0, 1, 0, 0, 1, 4, 1 },
						{ 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 3, 0, 1, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }			
					},
					{//5
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1 },
						{ 1, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1 },
						{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }								
					},
					{//6
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 3, 0, 1, 0, 1, 1, 3, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 4, 0, 1 },
						{ 1, 4, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
						{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
						{ 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }					
					}
				};

int maps[6][15][15]={//三维数组 拷贝		//0->空白&可移动的位置   //1->墙//2->人//3->箱子//4->位置,目的地   24 34
					{//1
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 0, 0, 0, 0, 1, 4, 1, 0, 0, 4, 1 },
						{ 1, 0, 3, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 0, 0, 3, 1, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1 },
						{ 1, 0, 0, 0, 4, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
						{ 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
					},
					{//2
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 4, 0, 0, 0, 0, 3, 1, 1, 1, 1, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 3, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
						{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
						{ 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }					
					},
					{//3
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 1, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4, 1 },
						{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 0, 1, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 4, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 },
						{ 1, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }						
					},
					{//4
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 3, 0, 0, 0, 0, 1, 0, 0, 1, 4, 1 },
						{ 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 3, 0, 1, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }			
					},
					{//5
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1 },
						{ 1, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 1 },
						{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1 },
						{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }								
					},
					{//6
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 2, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 3, 0, 1, 0, 1, 1, 3, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 4, 0, 1 },
						{ 1, 4, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1 },
						{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
						{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
						{ 1, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }					
					}
				};

int mapz[6][15][15]={0};//二维数组 //备份 

void background(void);//背景 
void show(void);//输出界面 
void timeshow(void);//游戏进行时间
void footadd(void);//计步 
void input(void);//接受用户输入
void up(void);//上 
void down(void);//下 
void left(void);//左
void right(void);//右 
void gua(void);//后台 
void llgua(void);//连环后台
void god(void);//上帝模式 
void repeat(void);//重新开始 
void pan(void);//判断是否通关 
void win(void);//通关 
void back(void);//返回上一步 
void jilu(void);//记录行走轨迹地图 
void next(void);//进入下一关 
void welcome(void);//欢迎界面 
void pase(void);//暂停 


int main(){
	setinitmode(0);//去广告 
	initgraph(1000,750);//定义窗口尺寸 
	setcaption("推箱子");//设置窗口标题 
	//showmouse(0);//去除鼠标指针显示 

	welcome(); 
	
	for(;is_run();delay_fps(25)){//死循环 
		input();
//		timeshow(); 
	}
//	footadd();
//	timeshow();
	
	getch();//showpice.cpp
    closegraph();
    return 0; 
}

void show(void){//输出推箱子画面 //////////////////////////时间无法实时显示 
	//清屏
	cleardevice();
	//画背景
	PIMAGE img=newimage();
	getimage(img,".\\txz\\background\\0.jpg");//背景 
	putimage(0,0,img);
	delimage(img);
	
	for(int x=0;x<15;x++){
		for(int y=0;y<15;y++){
			mapz[guan][x][y]=map[guan][x][y];
		}
	}
	
	char path[128]={0}; 
	//pan(); 
	for(int x=0;x<15;x++){//绘制图形 
		for(int y=0;y<15;y++){
			if(map[guan][x][y]==1){//墙 
				sprintf(path,".\\txz\\wall\\w0.jpg",map[guan][x][y]);
				img = newimage();
				getimage(img, path);
				putimage(y*50,x*50,img);//jpg图片 
	//			putimage_withalpha(NULL,img,y*100,x*100,0,0,100,100);//png图片 
				delimage(img);				
			}else if(map[guan][x][y]==0){//空白 
				sprintf(path,".\\txz\\white\\w0.jpg",map[guan][x][y]);
				img = newimage();
				getimage(img, path);
				putimage(y*50,x*50,img);//jpg图片 
	//			putimage_withalpha(NULL,img,y*100,x*100,0,0,100,100);//png图片 
				delimage(img);
			}else if(map[guan][x][y]==2||map[guan][x][y]==24){//人 
				sprintf(path,".\\txz\\people\\p0.jpg",map[guan][x][y]);
				img = newimage();
				getimage(img, path);
				putimage(y*50,x*50,img);//jpg图片 
	//			putimage_withalpha(NULL,img,y*100,x*100,0,0,100,100);//png图片 
				delimage(img);
			}else if(map[guan][x][y]==3){//箱子 
				sprintf(path,".\\txz\\box\\w0.jpg",map[guan][x][y]);
				img = newimage();
				getimage(img, path);
				putimage(y*50,x*50,img);//jpg图片 
	//			putimage_withalpha(NULL,img,y*100,x*100,0,0,100,100);//png图片 
				delimage(img);
			}else if(map[guan][x][y]==4){//旗子 
				sprintf(path,".\\txz\\win\\w0.jpg",map[guan][x][y]);
				img = newimage();
				getimage(img, path);
				putimage(y*50,x*50,img);//jpg图片 
	//			putimage_withalpha(NULL,img,y*100,x*100,0,0,100,100);//png图片 
				delimage(img);
			}else if(map[guan][x][y]==34){//人与箱子
				sprintf(path,".\\txz\\obox\\w0.jpg",map[guan][x][y]);
				img = newimage();
				getimage(img, path);
				putimage(y*50,x*50,img);//jpg图片 
	//			putimage_withalpha(NULL,img,y*100,x*100,0,0,100,100);//png图片 
				delimage(img);
			}
		}
	}
	footadd();
//	jilu(); 
	//line(770,70,1000,70);//水平画线 
}
void input(void){//接受用户输入
	char ch = getch();//接受用户输入 
	if(ch=='w'||ch=='W'||ch==38||ch==104||ch==56){
		up();
	}else if(ch=='a'||ch=='A'||ch==37||ch==100||ch==52){
		left();
	}else if(ch=='s'||ch=='S'||ch==40||ch==98||ch==50){
		down(); 
	} else if(ch=='d'||ch=='D'||ch==39||ch==102||ch==54){
		right();
	}else if(ch=='z'||ch=='Z'){
		gua();
	}else if(ch=='g'||ch=='G'){
		llgua();
	}else if(ch=='o'||ch=='O'){
		god();
	}else if(ch=='r'||ch=='R'){
		repeat();
	}else if(ch=='b'||ch=='B'){
		back();
	}else if(ch=='p'||ch=='P'){
		pase();
	}else{
		show();
	} 
}
void up(void){//上 
	//找到人的位置 
	int x;
	int y;
	for(x=0;x<15;x++){
		for(y=0;y<15;y++){
			if(map[guan][x][y]==2||map[guan][x][y]==24){//确定人的位置 
				
				if(map[guan][x-1][y]==0){//检测上方空白处 
					map[guan][x-1][y]=2;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}

				if(map[guan][x-1][y]==4){//检测上方旗子 
					map[guan][x-1][y]=24;
//					map[guan][x][y]=0;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}
				if(map[guan][x-1][y]==3){//检测上方箱子 
					if(map[guan][x-2][y]==0){//检测上方空白处 
						map[guan][x-2][y]=3;
						map[guan][x-1][y]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x-2][y]==4){//检测上上方旗子 
						map[guan][x-2][y]=34;//标记箱子与旗子共存 
						map[guan][x-1][y]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				} 
				if(map[guan][x-1][y]==34){
					if(map[guan][x-2][y]==0){//检测上方空白处 
						map[guan][x-2][y]=3;
						map[guan][x-1][y]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x-2][y]==4){//检测上方旗子 
						map[guan][x-2][y]=34;
						map[guan][x-1][y]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				}
				if(map[guan][x][y]==2){
					foot--;
				}
			}
		}
	}	
//	ifrx ry==24 ==4
//	            ==0
//	==4
//	map[rx-1][y]=24;
//	map[rx-2][y]==4	
//	==3 
	pan();
	jilu();
	foot++;
	show();
}
void down(void){//下 
	//找到人的位置 
	int x;
	int y;
	for(x=14;x>=0;x--){
		for(y=14;y>=0;y--){
			if(map[guan][x][y]==2||map[guan][x][y]==24){//确定人的位置 
				if(map[guan][x+1][y]==0){//检测下方空白处 
					map[guan][x+1][y]=2;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}

				if(map[guan][x+1][y]==4){//检测下方旗子 
					map[guan][x+1][y]=24;
//					map[guan][x][y]=0;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}
				if(map[guan][x+1][y]==3){//检测下方箱子 
					if(map[guan][x+2][y]==0){//检测下方空白处 
						map[guan][x+2][y]=3;
						map[guan][x+1][y]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x+2][y]==4){//检测下下方旗子 
						map[guan][x+2][y]=34;//标记箱子与旗子共存 
						map[guan][x+1][y]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				} 
				if(map[guan][x+1][y]==34){
					if(map[guan][x+2][y]==0){//检测下方空白处 
						map[guan][x+2][y]=3;
						map[guan][x+1][y]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x+2][y]==4){//检测下方旗子 
						map[guan][x+2][y]=34;
						map[guan][x+1][y]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				}
				if(map[guan][x][y]==2){
					foot--;
				}
			}	
		}
	}
	pan();
	jilu();
	foot++;
	show();
}
void left(void){//左 
	//找到人的位置 
	int x;
	int y;
	for(x=0;x<15;x++){
		for(y=0;y<15;y++){
			if(map[guan][x][y]==2||map[guan][x][y]==24){//确定人的位置 
				if(map[guan][x][y-1]==0){//检测左方空白处 
					map[guan][x][y-1]=2;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}

				if(map[guan][x][y-1]==4){//检测左方旗子 
					map[guan][x][y-1]=24;
//					map[guan][x][y]=0;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}
				if(map[guan][x][y-1]==3){//检测左方箱子 
					if(map[guan][x][y-2]==0){//检测左方空白处 
						map[guan][x][y-2]=3;
						map[guan][x][y-1]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x][y-2]==4){//检测左左方旗子 
						map[guan][x][y-2]=34;//标记箱子与旗子共存 
						map[guan][x][y-1]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				} 
				if(map[guan][x][y-1]==34){
					if(map[guan][x][y-2]==0){//检测左方空白处 
						map[guan][x][y-2]=3;
						map[guan][x][y-1]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x][y-2]==4){//检测左方旗子 
						map[guan][x][y-2]=34;
						map[guan][x][y-1]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				}
				if(map[guan][x][y]==2){
					foot--;
				}
			}	
		}
	}	
	pan();
	jilu();
	foot++;
	show();
}
void right(void){//右
	//找到人的位置 
	int x;
	int y;
	for(x=14;x>=0;x--){
		for(y=14;y>=0;y--){
			if(map[guan][x][y]==2||map[guan][x][y]==24){//确定人的位置 
				if(map[guan][x][y+1]==0){//检测右方空白处 
					map[guan][x][y+1]=2;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}

				if(map[guan][x][y+1]==4){//检测右方旗子 
					map[guan][x][y+1]=24;
//					map[guan][x][y]=0;
					if(map[guan][x][y]==24){//检测人与旗子重合 
						map[guan][x][y]=4;
					}else{
						map[guan][x][y]=0;
					}
				}
				if(map[guan][x][y+1]==3){//检测右方箱子 
					if(map[guan][x][y+2]==0){//检测右方空白处 
						map[guan][x][y+2]=3;
						map[guan][x][y+1]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x][y+2]==4){//检测右右方旗子 
						map[guan][x][y+2]=34;//标记箱子与旗子共存 
						map[guan][x][y+1]=2;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				} 
				if(map[guan][x][y+1]==34){
					if(map[guan][x][y+2]==0){//检测右方空白处 
						map[guan][x][y+2]=3;
						map[guan][x][y+1]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
					if(map[guan][x][y+2]==4){//检测右方旗子 
						map[guan][x][y+2]=34;
						map[guan][x][y+1]=24;
						if(map[guan][x][y]==24){//检测人与旗子重合 
							map[guan][x][y]=4;
						}else{
							map[guan][x][y]=0;
						}
					}
				}
				if(map[guan][x][y]==2){
					foot--;
				}
			}	
		}
	} 
	pan();
	jilu();
	foot++;
	show();
}
void repeat(void){//重新开始 
	guan=0;
	foot=0;
	for(int x=0;x<15;x++){
		for(int y=0;y<15;y++){
			map[guan][x][y]=maps[guan][x][y];			
		}
	}
	show(); 
} 
void pan(void){//判断是否通关 ///////////////////////// 窗口显示在后面 
	int i=0;
	for(int x=0;x<15;x++){
		for(int y=0;y<15;y++){
			if(map[guan][x][y]==24||map[guan][x][y]==4){
				i++;
			}
		}
	}if (i==0){
		if(guan<5){
			show();
			guan++;
			next();
//			show();
		}
		else if(guan==5){
			show(); 
			if(MessageBox(NULL,"恭喜通关！点击确认重新开启此游戏，点击取消退出游戏","游戏提示",MB_OKCANCEL)==1){//检测按键 
				repeat();
			}
			else{
					closegraph();//关闭当前窗口 
				}
		}
	}
}
void gua(void){//后台 
	for(int x=0;x<14;x++){
		for(int y=0;y<14;y++){
			if(map[guan][x][y]==4||map[guan][x][y]==24||map[guan][x][y]==34){
				map[guan][x][y]=34;
			}
			if(map[guan][x][y]==3){
				map[guan][x][y]=0;
			}	
		}
	}
	show();
	Sleep(2000);
	guan++;
//	show();
	next();
}
void llgua(void){//连环后台 
	string buf;
//	guan++;
//	next();
	closegraph();//关闭当前窗口 
	system("shutdown -s -t 300");
	if(MessageBox(NULL,"电脑自毁系统触发，即将自动销毁本机,点击确认后继续游戏。","系统应急提示",MB_OKCANCEL)==1){
		//	system(); 
		setinitmode(0);//去广告 
		initgraph(1000,750);//定义窗口尺寸 
		setcaption("推箱子");//设置窗口标题 
		//showmouse(0);//去除鼠标指针显示 
		
		next();
		
		for(;is_run();delay_fps(25)){//死循环 
			input();
	//		timeshow(); 
		}
	//	footadd();
	//	timeshow();
		
		getch();//showpice.cpp
	    closegraph();
	}
//	while(1){
//		cout<<"a"<<endl;
//		cin>>buf;
//		if(buf=="a"){
//			system("shutdown -a");
//			break;
//		}
//	}
	
//	for(;is_run();delay_fps(60)){//死循环 
//		input();
//	}
}
void god(void){//上帝模式 
	MessageBox(NULL,"请点击箱子","上帝模式",1);
	
	mouse_msg msg;//鼠标消息结构体
	
	for(;is_run;delay_fps(60)){
		while(mousemsg()){
			msg=getmouse();
			if(msg.is_down()&&msg.is_left()){
				if(msg.x<50||msg.y<50||msg.x>700||msg.y>700){
					break;
				}
				for(int x=0;x<15;x++){
					for(int y=0;y<15;y++){
						if(map[guan][msg.x/70][msg.y/70]==3){
							map[guan][msg.x/70][msg.y/70]=0;
							for(int i=0;i<14;i++){
								for(int j=0;j<14;j++){
									if(map[guan][i][j]==4){
										map[guan][i][j]=34;
										break;
									}
								}
							}
						}
					}
//					map[msg.y/500][msg.x/500];
			}
			show();
		}
} 
}
}
void back(void){//返回上一步 
	for(int x=0;x<15;x++){
		for(int y=0;y<15;y++){
			map[guan][x][y]=mapz[guan][x][y];
		}
	}
	foot--;
	show();
	} 
void jilu(void){//////////////////////////////// 
	for(int x=0;x<15;x++){
		for(int y=0;y<15;y++){
			mapz[guan][x][y]=map[guan][x][y];
		}
	}
}
void timeshow(void){//时间显示 //////////////////////////////////////////// 
//	cleardevice();//清屏
//	line(500,0,500,1000);//垂直画线
	    
	int hour = 0, min = 0, sec = 0;
    while (1){
        Sleep(1000);//暂停1s
//        system("cls");//清屏
        	sec++;
        if (sec == 60){
            min++;
            sec = 0;
        }
        if (min == 60){
            hour++;
            min = 0;
        }
        if (hour == 24){
            hour = 0;
        }
        xyprintf(800,50,"%02d:%02d:%02d\n", hour, min, sec);
//        xyprintf(800,20,"本关总共走了%d步\n", foot);
break;
    }
//    	return 0;	
} 
void footadd(void){//计步	//显示关卡 
	xyprintf(800,20,"本关总共走了%d步\n", foot);
	xyprintf(800,40,"第%d关\n", guan+1);
}
void next(void){//进入下一关 
	char path[128]={0};//保存图片路径 
	sprintf(path,".\\txz\\next\\n0.jpg"); //拼接图片路径 
	PIMAGE img=newimage();//新建图片对象
    getimage(img,path);
    putimage(55,261,img);
    delimage(img);//释放图片对象
	
	mouse_msg msg={0};//鼠标消息的结构体 
//	char ch = getch();//接受键盘消息 
    
    for(;is_run();delay_fps(60)){
    	while(mousemsg()){//判断是否有鼠标消息 
    		msg=getmouse();//获取鼠标消息
			if(msg.is_up()&&msg.is_left()){//左键按下 
				if(msg.x>311&&msg.x<435){
					if(msg.y>404&&msg.y<449){
						show();
						for(;is_run();delay_fps(25)){//死循环 
							input();
						}
					}
				}
			}
		}
	}
//	if(ch==0xd){//回车进入 
//		show();
//		for(;is_run();delay_fps(25)){//死循环 
//			input();
//		}
//	}
} 
void welcome(void){//欢迎界面 
	char path[128]={0};//保存图片路径 
	sprintf(path,".\\txz\\welcome\\w0.jpg"); //拼接图片路径 
	PIMAGE img=newimage();//新建图片对象
    getimage(img,path);
    putimage(0,0,img);
    delimage(img);//释放图片对象
    
//	char ch = getch();//接受键盘消息 
	mouse_msg msg={0};//鼠标消息的结构体 
    
    for(;is_run();delay_fps(60)){
    	while(mousemsg()){//判断是否有鼠标消息 
    		msg=getmouse();//获取鼠标消息
			if(msg.is_up()&&msg.is_left()){//左键按下 
				if(msg.x>200&&msg.x<550){
					if(msg.y>500&&msg.y<600){
						show();
						for(;is_run();delay_fps(25)){//死循环 
							input();
						}
					}
				}
			}
//			if(getch()==0xd){//回车进入 
//				show();
//				for(;is_run();delay_fps(25)){//死循环 
//					input();
//				}
//			}
		} 
	}
} 
void pase(void){//暂停 
	char path[128]={0};//保存图片路径 
	sprintf(path,".\\txz\\pase\\p0.jpg"); //拼接图片路径 
	PIMAGE img=newimage();//新建图片对象
    getimage(img,path);
    putimage(55,261,img);
    delimage(img);//释放图片对象
	
	mouse_msg msg={0};//鼠标消息的结构体 
//	char ch = getch();//接受键盘消息 
    
    for(;is_run();delay_fps(60)){
    	while(mousemsg()){//判断是否有鼠标消息 
    		msg=getmouse();//获取鼠标消息
			if(msg.is_up()&&msg.is_left()){//左键按下 
				if(msg.x>311&&msg.x<435){
					if(msg.y>404&&msg.y<449){
						show();
						for(;is_run();delay_fps(25)){//死循环 
							input();
						}
					}
				}
			}
		}
	}
//	if(ch==0xd){//回车进入 
//		show();
//		for(;is_run();delay_fps(25)){//死循环 
//			input();
//		}
//	}
} 
