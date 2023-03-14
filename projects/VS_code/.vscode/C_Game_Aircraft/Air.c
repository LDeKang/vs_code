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

int width; //窗口宽
int hight; //窗口高
int position_x; //飞机x坐标
int position_y; //飞机y坐标
int bullet_x; //子弹x坐标
int bullet_y; //子弹y坐标
int enemy_x,enemy_y; //敌机位置
int delay; //延时变量
int Score;  //分数
int End_flag=0; //结束标志
int seep;//速增加
int main(void)
{
     
	startup();  // 数据初始化	
	while (1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
      if(End_flag==1)
      {
        break;
      }
	}
	return 0;

}

void startup(void)// 数据初始化	
{
  width=40;
  hight=20;
  position_x=width/2;
  position_y=hight/2;
  bullet_x =position_x;
  bullet_y = -2;
  enemy_x=width/2;
  enemy_y=0;
  delay=5;
  Score=0;
   seep=7;
}

void show(void)
{
int i,j;
 
gotoxy(0,0); //刷新
printf("Score==%d\n",Score);  //记分

for(i=0;i<hight;i++) //采用横向扫描的方式，扫描到特定坐标后，输出相应符号
{
    for(j=0;j<width;j++)
    {
 
      if((i==position_y)&&(j==position_x))
      {
          printf("*");
      }
       if((i==(position_y+1))&&(j==position_x-1))
      {
          printf("***");
      }
         if((i==(position_y+2))&&(j==position_x-1))
      {
          printf("***");
      }
      else if((i==bullet_y)&&(j==bullet_x))
      {
          printf("|");
      }
      else if((i==enemy_y)&&(j==enemy_x))
      {
          printf("@");
      }
      else
      {
          printf(" ");
      }
    }
    printf("\n");
}


}

void updateWithoutInput(void)
{
if(bullet_y>=-1)
{
 bullet_y--;//子弹移动   
}

delay--;  //延时变量
if(delay==0)//控制敌机下落速度
{
delay=seep;
enemy_y++;
}
if((position_x==0)||(position_x==width))//边界处理
{
position_x=rand()%width;
}

 if(enemy_y>hight) //敌机的位置变化
 {
 enemy_y=0;
 enemy_x=rand()%width;

 }
 if((enemy_y==bullet_y)&&(enemy_x==bullet_x)) //击杀时更新
 {
 enemy_y=-1;
 enemy_x=rand()%width;
 Score++;
 bullet_y = -2;          // 子弹无效
 }

 if((enemy_y==position_y)&&(enemy_x==position_x))//被击杀
 {
  printf("Game is end,your score==%d\n",Score);
  sleep(10);
  End_flag=1;
 }
 if(Score%5==0)
 {
 seep=5;
 }
 

}

void updateWithInput(void)
{
    char key;
if (kbhit())
        {
            key = getch();
            if (key == 'a')
           {
                position_x--;
            }
            if (key == 'd')
            {
                position_x++;
            }
            if (key == 'w')
            {
                position_y--;
            }
            if (key == 's')
            {
                position_y++;
            }
             if (key == ' ')
            {
             bullet_x = position_x;  // 发射子弹的初始位置在飞机的正上方
			 bullet_y = position_y-1;
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
