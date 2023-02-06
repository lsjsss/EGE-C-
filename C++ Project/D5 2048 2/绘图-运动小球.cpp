#include <graphics.h>
int main()
{

		setinitmode(0);//去掉广告 
		
        initgraph(600, 400);//*创建窗口 
		

		setcaption("窗口");//设置窗口标题 
		setbkcolor(EGERGB(240,1,1));//设置背景颜色
		
		
//				 PIMAGE img = newimage();
//getimage(img, "C:\\Users\\307\\Desktop");
//putimage(0, 0, img);
//delimage(img);
//PIMAGE img = newimage();
//getimage(img, 0, 0, 100, 100);
//putimage(200, 200, img);


		int x=10,y=10;//小球坐标点 
		int dx=1,dy=1;//小球运动方向 
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
		 
        getch();//*接收键盘输入一个字符（阻塞） 
        closegraph();//*关闭窗口
 
        return 0;
}
