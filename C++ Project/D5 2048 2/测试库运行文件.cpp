#include <graphics.h>
int main(){
	initgraph(600,400);
	
	//2设置画图颜色，GREEN是颜色常数，详细可以查graphics.h对这个宏的定义的值
    setcolor(WHITE);
    //画一直线，从(100,100)到(500,200)
    //特别注意的是端点，(100,100)这个点会被画上颜色，但(500,200)不会画上颜色
    //以下所有的矩形（或者说两点）描述方式，总是前一个点取得到，但后一个点取不到
    line(0, 0, 600, 400);

	
        //3设置画图颜色，使用RGB宏，三个参数值的范围均为0 - 255 (0xFF)
        //分别表示红色亮度，绿色亮度，蓝色亮度
        //EGERGB(0xFF, 0x0, 0x0) (纯红色) 等价于0xFF0000
        setcolor(EGERGB(0xFF, 0x0, 0x0));
    //画一圆，圆心在(200,200)，半径100
  	  circle(200, 200, 100);

	
    //4设置填充颜色，一般为图形内部颜色
  	  setfillcolor(EGERGB(0xFF, 0x0, 0x80));
 	   //画一实心矩形，范围为：x坐标从50-300，y坐标从100-200
	    bar(50, 100, 300, 200);
    

     //5设置绘图颜色，一般用于边界
        setcolor(EGERGB(0xFF, 0xFF, 0x0));
        //设置填充颜色，一般为图形内部颜色
        setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        //画一带填充的椭圆
        fillellipse(200, 200, 150, 100);
        //画一个空心圆
        circle(500, 300, 100);
        //再次设置填充颜色，用于决定下一函数填充的颜色
        setfillcolor(EGERGB(0x80, 0x0, 0xFF));
        //手工填充
        //x,y是开始填充的坐标，第三个参数是填充的边界颜色，或者说以这个颜色作为边界
        //如果这个边界不封闭，那么会导致整个屏幕都是这个颜色
        floodfill(500, 300, EGERGB(0xFF, 0xFF, 0x0));
	
	
	//6第一次设置背景色
        setbkcolor(EGERGB(0x0, 0x40, 0x0)); //浅绿色
        setcolor(EGERGB(0xFF, 0xFF, 0x0));
        setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        //画带填充的扇形
        sector(200, 200, 45, 135, 150, 100);
        getch();
        //按下一任意键后，再次改变背景色
        setbkcolor(EGERGB(0x0, 0x0, 0x40)); //浅蓝色
        
        
    //7先画一个矩形，以便于看出背景色的问题
        setfillcolor(EGERGB(0x0, 0x80, 0x80));
        bar(50, 50, 500, 200);
        //文字颜色
        setcolor(EGERGB(0x0, 0xFF, 0x0));
        //文字背景色（注意setbkcolor函数也会同时改变文字背景色）
        setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
        //设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
        //如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
        setfont(12, 0, "宋体");
        //写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
        //要使用特殊格式化字符请用outtextrect
        outtextxy(100, 100, "Hello EGE Graphics");
        outtextrect(100, 120, 200, 100, "\tHello EGE Graphics\nHere is the next line.");
        //设置文字背景填充方式为透明，默认为OPAQUE不透明
        setbkmode(TRANSPARENT);
        outtextxy(100, 150, "Hello EGE Graphics, 中文也是支持的");
        
        
    //8设置视口矩形区域为(200,100) - (330, 130)
        //最后一个参数为1表示出了这个区域的图形会被裁剪
        //后面所绘画的图形的原点坐标(0,0)，会映射到(200,100)
        setviewport(200, 100, 330, 130, 1);
        //画一些文字，注意文字会因区域被裁剪的效果
        setcolor(EGERGB(0x0, 0xFF, 0x0));
        setfontbkcolor(RGB(0x80, 0x00, 0x80));
        setfont(18, 0, "宋体");
        outtextxy(0, 0, "Hello EGE Graphics");

        setbkmode(TRANSPARENT);
        outtextxy(0, 20, "Hello EGE Graphics");

        //还原视口
        setviewport(0, 0, getwidth(), getheight(), 1);
        outtextxy(0, 0, "Hello EGE Graphics");
        
        
        //9声明一个img图片对象
        PIMAGE img;
 
        initgraph(640, 480);
 
        //先随便画一些东西
        setcolor(EGERGB(0xFF, 0xFF, 0x0));
        setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        fillellipse(50, 50, 50, 50);
 
        //用newimage在initgraph后创建这个对象。但记得要在不使用的时候delimage
        img = newimage();
 
        //从屏幕上截取(0, 0) - (80, 60)这部分作为img，这个img大小为80*60
        //img的尺寸会重设，大小由第三第四个参数决定
        //注意，(0,0)这点会被包含在img里，但(80, 60)不包含
        getimage(img, 0, 0, 80, 60);
 
        //对img设置填充色为绿色
        setfillcolor(EGERGB(0x0, 0x70, 0x0), img);
 
        //对img画实心矩形
        bar(40, 20, 70, 50, img);
 
        int x, y;
        //把img平铺在屏幕上，使用一个二重循环
        for (y = 0; y < 8; ++y)
        {
                for (x = 0; x < 8; ++x)
                {
                        //把img整个，画在指定的坐标上，左上角对齐这个坐标
                        putimage(x * 80, y * 60, img);
                }
        }
 
        getch();
 
        delimage(img);
        
        
        
        
        
        
	getch();
	closegraph();
	return 0;
}
