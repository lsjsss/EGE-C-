#include <graphics.h>
int main()
{

		setinitmode(0);//ȥ����� 
		
        initgraph(600, 400);//*�������� 
		

		setcaption("����");//���ô��ڱ��� 
		setbkcolor(EGERGB(240,1,1));//���ñ�����ɫ
		
		
//				 PIMAGE img = newimage();
//getimage(img, "C:\\Users\\307\\Desktop");
//putimage(0, 0, img);
//delimage(img);
//PIMAGE img = newimage();
//getimage(img, 0, 0, 100, 100);
//putimage(200, 200, img);


		int x=10,y=10;//С������� 
		int dx=1,dy=1;//С���˶����� 
		for(;is_run();delay_fps(60)){
			setfillcolor(BLUE);
//			cleardevice();
			circle(x,y,10);
			x+=dx;y+=dy;
			if(x>590)dx=-1;
			else if(x<10)dx=1;
			if(y>390)dy=-1;
			else if(y<10)dy=1;
			api_sleep(0.001);
		}
		 
		 


delimage(img);
		 
        getch();//*���ռ�������һ���ַ��������� 
        closegraph();//*�رմ���
 
        return 0;
}
