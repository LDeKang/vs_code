#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#define hight 20  // 游戏画面尺寸
#define width 40

void startup();// 数据初始化	
void show();  // 显示画面
void updateWithoutInput();  // 与用户输入无关的更新
void updateWithInput();  // 与用户输入有关的更新
void gotoxy(int x,int y);  //光标移动到(x,y)位置
void Snake_move(void);//小蛇移动控制

int snake_x,snake_y;
int Greeny[hight][width];
int move_head;//蛇头
int foot_y,foot_x;//食物
int Score;//分数
int Mov_speed;
int main(void)
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
int i,j,k,count=0;
snake_y=hight/2;
snake_x=width/2;
Greeny[snake_y][snake_x]=1;
move_head=1;
foot_y=10;
foot_x=5;
Greeny[foot_y][foot_x]=-2;
Score=0;
Mov_speed=120;
for(i=0;i<hight;i++)

{
    for(j=0;j<width;j++)
    {
        Greeny[i][0]=-1;
        Greeny[0][j]=-1;
        Greeny[i][width-1]=-1;
        Greeny[hight-1][j]=-1;
    }
}
for(k=1;k>0;k--)
{
Greeny[snake_y][snake_x-k]=k+1;
}
 

}

void show()
{
    int i,j;
    gotoxy(0,0);
    for(i=0;i<hight;i++)
{
    for(j=0;j<width;j++)
    {
        if(Greeny[i][j]==-1)//窗口
        {
            printf("#");
        }
        else if(Greeny[i][j]==1)//蛇头
        {
             printf("@");
        }
        else if(Greeny[i][j]>1)//蛇身
        {
             printf("*");
        }
        else if(Greeny[i][j]==-2)//食物
        {
             printf("o");
        }
        else
        {
            printf(" ");
        }
        
    }
    printf("\n");
}
 printf("\n");
 printf("your Score=%d\n",Score);

Sleep(Mov_speed);
}
void Snake_move(void)
{
 int i,j,max=0;
    int oldtail_i,oldtail_j,head_i,head_j,newhead_i,newhead_j;
    //oldtail_i:标记蛇尾的值，最大值，head_i：记录蛇头，newhead_i：记录新的蛇头
 
for(i=1;i<hight-1;i++)//遍历数组，使蛇身的值+1，除去蛇尾，产生新的蛇头，达到移动的目的
{
    for(j=1;j<width-1;j++)
    {
        if(Greeny[i][j]>0)
        {
            Greeny[i][j]++;
        }

    }
}
 
 for(i=1;i<hight-1;i++)//记录最大值，旧蛇头
{
    for(j=1;j<width-1;j++)
    {
        if(Greeny[i][j]>0)
        {
        if(max<Greeny[i][j])
        {
            max=Greeny[i][j];
            oldtail_i=i;
            oldtail_j=j;
        }
        if(Greeny[i][j]==2)
        {
        head_i=i;
        head_j=j;
        }
        
        }

    }
}
 
//根据反向确定新蛇头的位置
if(move_head==1)
{
 newhead_i=head_i-1;
 newhead_j=head_j;
}
if(move_head==2)
{
 newhead_i=head_i+1;
 newhead_j=head_j;  
}
if(move_head==3)
{
 newhead_i=head_i;
 newhead_j=head_j-1; 
}
if(move_head==4)
{
 newhead_i=head_i;
 newhead_j=head_j+1;  
}
 if( Greeny[newhead_i][newhead_j]==-2)//吃到果实，新蛇头为-2，不除去最大值，正常
 {
  Greeny[foot_y][foot_x]=0;
  foot_y= rand()%(hight);
  foot_x= rand()%(width);
  Greeny[foot_y][foot_x]=-2;
  Score++;
  Mov_speed--;
 
 }
 else
 {
 Greeny[oldtail_i][oldtail_j]=0;
 }

if((Greeny[newhead_i][newhead_j]>0)||(Greeny[newhead_i][newhead_j]==-1))//游戏结束
{
    printf("Game is end,your Score=%d \n",Score);
    exit(0);
}
else //新的蛇头
{
  
   Greeny[newhead_i][newhead_j]=1;
}


}
void updateWithoutInput()
{
 
 Snake_move();
}

void updateWithInput()
{
char key;
if(kbhit())//方向控制
{
    key=getch();
    if(key=='w')
    {
      move_head=1;
    Snake_move();
    }
    if(key=='s')
    {
      move_head=2;
     Snake_move();
    }
        if(key=='a')
    {
      move_head=3;
     Snake_move();
    }
        if(key=='d')
    {
      move_head=4;
     Snake_move();
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