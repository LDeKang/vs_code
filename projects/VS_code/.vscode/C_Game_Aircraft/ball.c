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

int width,hight;
int ball_x,ball_y;//小球坐标
int ball_vx,ball_vy;//小球速度
int baord_x,baord_y;//板子中心坐标
int redius;  //板子的半径
int nera,fars;//板子离左边界的距离(近和远)
int Score;//得分


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



void startup()// 数据初始化
{
width=24;
hight=15;
ball_x=width/2;
ball_y=hight/2;
ball_vx=1;
ball_vy=1;
baord_x=width/2;
baord_y=hight-1;
redius=5;
nera=baord_x-redius;
fars=baord_x+redius;
Score=0;
}	
void show()// 显示画面
{
int i,j;
gotoxy(0,0);
printf("SCORE=%d\n",Score);
for(i=0;i<hight+1;i++) //采用横向扫描的方式，扫描到特定坐标后，输出相应符号
{
    for(j=0;j<width+1;j++)
    {
        if((i==ball_y)&&(j==ball_x))
        {
            printf("O");
        }
        else if(i==hight)
        {
            printf("-");
        }
        else if(j==width)
        {
            printf("|");
        }
        else if((i==baord_y)&&((j>=nera)&&(j<=fars)))
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        
    }
    printf("\n");
}

}  
void updateWithoutInput() // 与用户输入无关的更新
{
    ball_y+=ball_vy;  //小球运动
    ball_x+=ball_vx;
    if((ball_x==width)||(ball_x==0))//反弹
    {
        ball_vx=-ball_vx;           
    }
    if((ball_y==0))//反弹
    {
        ball_vy=-ball_vy;           
    }
    Sleep(70);
    if((ball_y==hight-1)&&((ball_x>=nera)&&(ball_x<=fars)))//反弹
    {
         ball_vx=-ball_vx;
         ball_vy=-ball_vy;   
         Score++;
    }
    else if(ball_y==hight) //没有碰到板子
    {
     printf("Game is fail");
     exit(0);
    }
   
    
     
    

} 
void updateWithInput()// 与用户输入有关的更新
{
    char key;
if(kbhit())
{
     key = getch();
//-----------------板子移动-------------
     if(key=='a')
     {
         baord_x--;
         nera=baord_x-redius;
         fars=baord_x+redius;
     }
     if(key=='d')
     {
         baord_x++;
         nera=baord_x-redius;
         fars=baord_x+redius;
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


