#include <graphics.h>
int main(){
	initgraph(600,400);
	
	//2���û�ͼ��ɫ��GREEN����ɫ��������ϸ���Բ�graphics.h�������Ķ����ֵ
    setcolor(WHITE);
    //��һֱ�ߣ���(100,100)��(500,200)
    //�ر�ע����Ƕ˵㣬(100,100)�����ᱻ������ɫ����(500,200)���ử����ɫ
    //�������еľ��Σ�����˵���㣩������ʽ������ǰһ����ȡ�õ�������һ����ȡ����
    line(0, 0, 600, 400);

	
        //3���û�ͼ��ɫ��ʹ��RGB�꣬��������ֵ�ķ�Χ��Ϊ0 - 255 (0xFF)
        //�ֱ��ʾ��ɫ���ȣ���ɫ���ȣ���ɫ����
        //EGERGB(0xFF, 0x0, 0x0) (����ɫ) �ȼ���0xFF0000
        setcolor(EGERGB(0xFF, 0x0, 0x0));
    //��һԲ��Բ����(200,200)���뾶100
  	  circle(200, 200, 100);

	
    //4���������ɫ��һ��Ϊͼ���ڲ���ɫ
  	  setfillcolor(EGERGB(0xFF, 0x0, 0x80));
 	   //��һʵ�ľ��Σ���ΧΪ��x�����50-300��y�����100-200
	    bar(50, 100, 300, 200);
    

     //5���û�ͼ��ɫ��һ�����ڱ߽�
        setcolor(EGERGB(0xFF, 0xFF, 0x0));
        //���������ɫ��һ��Ϊͼ���ڲ���ɫ
        setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        //��һ��������Բ
        fillellipse(200, 200, 150, 100);
        //��һ������Բ
        circle(500, 300, 100);
        //�ٴ����������ɫ�����ھ�����һ����������ɫ
        setfillcolor(EGERGB(0x80, 0x0, 0xFF));
        //�ֹ����
        //x,y�ǿ�ʼ�������꣬���������������ı߽���ɫ������˵�������ɫ��Ϊ�߽�
        //�������߽粻��գ���ô�ᵼ��������Ļ���������ɫ
        floodfill(500, 300, EGERGB(0xFF, 0xFF, 0x0));
	
	
	//6��һ�����ñ���ɫ
        setbkcolor(EGERGB(0x0, 0x40, 0x0)); //ǳ��ɫ
        setcolor(EGERGB(0xFF, 0xFF, 0x0));
        setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        //������������
        sector(200, 200, 45, 135, 150, 100);
        getch();
        //����һ��������ٴθı䱳��ɫ
        setbkcolor(EGERGB(0x0, 0x0, 0x40)); //ǳ��ɫ
        
        
    //7�Ȼ�һ�����Σ��Ա��ڿ�������ɫ������
        setfillcolor(EGERGB(0x0, 0x80, 0x80));
        bar(50, 50, 500, 200);
        //������ɫ
        setcolor(EGERGB(0x0, 0xFF, 0x0));
        //���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
        setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
        //�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
        //����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
        setfont(12, 0, "����");
        //д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
        //Ҫʹ�������ʽ���ַ�����outtextrect
        outtextxy(100, 100, "Hello EGE Graphics");
        outtextrect(100, 120, 200, 100, "\tHello EGE Graphics\nHere is the next line.");
        //�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
        setbkmode(TRANSPARENT);
        outtextxy(100, 150, "Hello EGE Graphics, ����Ҳ��֧�ֵ�");
        
        
    //8�����ӿھ�������Ϊ(200,100) - (330, 130)
        //���һ������Ϊ1��ʾ������������ͼ�λᱻ�ü�
        //�������滭��ͼ�ε�ԭ������(0,0)����ӳ�䵽(200,100)
        setviewport(200, 100, 330, 130, 1);
        //��һЩ���֣�ע�����ֻ������򱻲ü���Ч��
        setcolor(EGERGB(0x0, 0xFF, 0x0));
        setfontbkcolor(RGB(0x80, 0x00, 0x80));
        setfont(18, 0, "����");
        outtextxy(0, 0, "Hello EGE Graphics");

        setbkmode(TRANSPARENT);
        outtextxy(0, 20, "Hello EGE Graphics");

        //��ԭ�ӿ�
        setviewport(0, 0, getwidth(), getheight(), 1);
        outtextxy(0, 0, "Hello EGE Graphics");
        
        
        //9����һ��imgͼƬ����
        PIMAGE img;
 
        initgraph(640, 480);
 
        //����㻭һЩ����
        setcolor(EGERGB(0xFF, 0xFF, 0x0));
        setfillcolor(EGERGB(0xFF, 0x0, 0x80));
        fillellipse(50, 50, 50, 50);
 
        //��newimage��initgraph�󴴽�������󡣵��ǵ�Ҫ�ڲ�ʹ�õ�ʱ��delimage
        img = newimage();
 
        //����Ļ�Ͻ�ȡ(0, 0) - (80, 60)�ⲿ����Ϊimg�����img��СΪ80*60
        //img�ĳߴ�����裬��С�ɵ������ĸ���������
        //ע�⣬(0,0)���ᱻ������img���(80, 60)������
        getimage(img, 0, 0, 80, 60);
 
        //��img�������ɫΪ��ɫ
        setfillcolor(EGERGB(0x0, 0x70, 0x0), img);
 
        //��img��ʵ�ľ���
        bar(40, 20, 70, 50, img);
 
        int x, y;
        //��imgƽ������Ļ�ϣ�ʹ��һ������ѭ��
        for (y = 0; y < 8; ++y)
        {
                for (x = 0; x < 8; ++x)
                {
                        //��img����������ָ���������ϣ����ϽǶ����������
                        putimage(x * 80, y * 60, img);
                }
        }
 
        getch();
 
        delimage(img);
        
        
        
        
        
        
	getch();
	closegraph();
	return 0;
}
