#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>

#include<windows.h>
#include<conio.h>

using namespace std;

int map[4][4]={0};	//��ͼ 
int fen = 0;		//���� 

void sui(void);		//���������
void show(void);	 //��ӡ���� 
void input(void);	//�����û����� 
void up(void);		//������ 
void down(void);	
//void left(void);	
//void right(void);	
void gua(void);		//��̨ 

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

void sui(void){		//���������
	//���� 
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
			map[x][y]=rand()%20==4?4:2;//����4�ĸ���Ϊ1/20���ٸ��ʣ� 
			fen+=map[x][y];
			break; 
		}
	} 
}
void show(void){	 //��ӡ����
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
void input(void){	//�����û����� 
	char ch = getch();//�����û������ַ� 
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
void up(void){		//������ 
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

void down(void){	//������ 
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
//void left(void){	//������ 
//	
//}
//void right(void){	//������ 
//	
//}
//void gua(void){		//��̨ 
//
//}
