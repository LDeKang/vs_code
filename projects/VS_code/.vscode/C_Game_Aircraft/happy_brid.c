#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

void startup();// 数据初始化	
void show();  // 显示画面
void updateWithoutInput();  // 与用户输入无关的更新
void updateWithInput();  // 与用户输入有关的更新
void gotoxy(int x,int y);  //光标移动到(x,y)位置

int width,hight;//窗口
int brid_x,brid_y;//小鸟位置
int Baffle_x,Baffle_y;//挡板位置
int Rediues;//缺口半径
int on_top,under_top;//缺口各边离顶面的距离
int Score;//分数
int flag=1;//速度改变标志
int delay_v;//速度标志
int main()
{
	startup();  // 数据初始化	
	while (1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
	return 0;
}

void startup()
{
    width=30;
    hight=20;
    brid_x=10;
    brid_y=2;
    Score=0;
    Baffle_x=3*brid_x;
    Baffle_y=10;
    Rediues=4;
    on_top=Baffle_y-Rediues/2;
    under_top=Baffle_y+Rediues/2;
    delay_v=15;
}

void show()
{
    int i,j;
    gotoxy(0,0);
    for(i=0;i<hight;i++)
    {
        for(j=0;j<width;j++)
        {
            if((i==brid_y)&&(j==brid_x))
            {
                printf("O");
            }
            else if(((i<on_top)||(i>under_top))&&(j==Baffle_x))
            {
                printf("*");//显示挡板
            }
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
      printf("\n");
    printf("Score=%d\n",Score);
}

void updateWithoutInput()
{
    static int delay=15;//延时变量
    delay--;
    if(delay==0)
    {
     delay=delay_v;
     brid_y++; 
     Baffle_x--;

    }
    if(((Score%3)==0)&&(Score!=0))
    {
        if(flag==1)
        {
           delay_v=10;  
           flag==-flag;
        }
        if(flag==-1)
        {
           delay_v=3;  
           flag==-flag;
        }
        
       
    }
    if(Baffle_x<brid_x)
    {
        Baffle_x=3*brid_x;
        Baffle_y=rand()%hight;
        on_top=Baffle_y-Rediues/2;
        under_top=Baffle_y+Rediues/2;
        Score++;
    }
    if((brid_x==Baffle_x)&&((brid_y<on_top)||(brid_y>under_top)))
    { 
        printf("Game is end\n");
        exit(0);
       
    }
    else if(brid_y>hight)
    {
        printf("Game is end\n");
        exit(0);
        
    }
    

     

}

void updateWithInput()
{
    char key;
    if(kbhit())
    {
        key=getch();
        if(key=='w')
        {
            brid_y--;
        }
         if(key=='s')
        {
            brid_y++;
        }
    }


}

void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}