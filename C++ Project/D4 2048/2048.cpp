#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>

#include<windows.h>
#include<conio.h>

using namespace std;

int map[4][4]={0};	//地图 
int fen = 0;		//分数 

void sui(void);		//差生随机数
void show(void);	 //打印界面 
void input(void);	//接受用户输入 
void up(void);		//向上走 
void down(void);	
//void left(void);	
//void right(void);	
void gua(void);		//后台 

int main(){
	srand(time(0));
	sui();
	sui();
	show();
	
	while(1){
		input();
		sui();
		show();
	}
	
	return 0;
}

void sui(void){		//差生随机数
	//判满 
//	for(int x = 0; x < 3; x++){
//		for(int y = 0; y < 3; y++){
//			if((map[x][y] != map[x+1][y]) || (map[x][y] != map[x][y+1]))
//			{
//				printf("die!");
//				system("exit");
//			}
//		}
//	}
		
	while(1){
		int x = rand() % 4;
		int y = rand() % 4;
		if(map[x][y] == 0){
			map[x][y]=rand()%20==4?4:2;//控制4的概率为1/20（假概率） 
			fen+=map[x][y];
			break; 
		}
	} 
}
void show(void){	 //打印界面
	system("cls");
	printf("*******************\n");
	printf("*******2048********\n");
	printf("*******************\n");
	for(int x = 0; x < 4; x++){
		printf("*");
		for(int y = 0; y < 4; y++){
			printf("%4d",map[x][y]);
		}
		printf("*\n");
	}
	printf("*******************\n");
	printf("****fenshu:%-9d*\n",fen);
	printf("*******************\n");
}
void input(void){	//接受用户输入 
	char ch = getch();//接收用户输入字符 
	if(ch=='w' || ch=='W' ){
		up();	
	}
	else if(ch=='a' || ch == 'A' ){
		//left();
	}
	else if(ch == 's' || ch == 'S' ){
		//right(); 
	}
	else if(ch == 'd' || ch == 'D' ){
		down();
	}
	else if(ch == 'z' || ch == 'Z'){
		//gua()	
	}
	
}
void up(void){		//向上走 
	for()

	for(int x = 1; x < 4; x++){
		for(int y = 0; y < 4; y++){
			if(map[x-1][y] == 0 && map [x][y] != 0){
				map[x-1][y] = map[x][y];
				map[x][y] == 0;
			}
			if(map[x-1][y] != 0 && map [x][y] == map[x-1][y]){
				map[x-1][y] *= 2;
				map[x][y] == 0;
			}
		}
	}
	
}

void down(void){	//向下走 
	for(int x = 2; x > 0; x--){
		for(int y = 0; y < 4; y++){
			if(map[x+1][y] == 0 && map [x][y] != 0){
				map[x+1][y] = map[x][y];
				map[x][y] == 0;
			}
			if(map[x+1][y] != 0 && map [x][y] == map[x+1][y]){
				map[x+1][y] *= 2;
				map[x][y] == 0;
			}
		}
	}
}
//void left(void){	//向左走 
//	
//}
//void right(void){	//向右走 
//	
//}
//void gua(void){		//后台 
//
//}
