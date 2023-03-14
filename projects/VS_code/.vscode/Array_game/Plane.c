#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#define hight 24  // 游戏画面尺寸
#define width 48
#define Numenemy 4

void startup();// 数据初始化	
void show();  // 显示画面
void updateWithoutInput();  // 与用户输入无关的更新
void updateWithInput();  // 与用户输入有关的更新
void gotoxy(int x,int y);  //光标移动到(x,y)位置

int plane[hight][width]={0};//窗口大小
int position_x,position_y;//飞机位置
int enemys_x[Numenemy],enemys_y[Numenemy];//敌机
int Score;//分数
int Num_bullet;//子弹数量
int enemy_speed=7;//敌机下落速度
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
    int i;
position_x=width/2;
position_y=hight/2;
plane[position_y][position_x]=1;//我方

for(i=0;i<Numenemy;i++)//多敌机
{
enemys_x[i]=rand()%width;//随机位置
enemys_y[i]=rand()%2;//0,1随机
plane[enemys_y[i]][enemys_x[i]]=3;
}
Score=0;
Num_bullet=0;
}

void show()
{
int i,j;
gotoxy(0,0);
for(i=0;i<hight;i++)
{
        for(j=0;j<width;j++)
    {
        if(plane[i][j]==0)
        {
            printf(" ");
        }
        else if(plane[i][j]==1)
        {
             printf("*");
        }
        else if(plane[i][j]==2)
        {
             printf("|");
        }
         else if(plane[i][j]==3)
        {
             printf("@");
        }
        
    }
    printf("\n");
}
 
printf("Score is %d\n",Score);
}

void updateWithoutInput()
{
    int i,j,k;
    static int delay=0;
    
for(i=0;i<hight;i++)//子弹发射轨迹
{
        for(j=0;j<width;j++)
    {
        if(plane[i][j]==2)
        {
            plane[i][j]=0;
            if(i>0)
            {
               plane[i-1][j]=2;  
            }
        }
        
    }
}
for(k=0;k<Numenemy;k++)//敌机模块 
{
if(delay<enemy_speed)//速度
{
    delay++;
}
if(delay==enemy_speed)//多敌机下落
{
    delay=0;
    plane[enemys_y[k]][enemys_x[k]]=0;
    enemys_y[k]++;
    plane[enemys_y[k]][enemys_x[k]]=3;

}
if( plane[enemys_y[k]][enemys_x[k]]!=3)//击中敌机，敌机自动消失，3背1覆盖
{
enemys_x[k]=rand()%width;//重新生成位置
enemys_y[k]=rand()%2;
plane[enemys_y[k]][enemys_x[k]]=3;
Score++;
if((Score%5==0)&&(enemy_speed>3))//分数达到一定时速度增加
{
enemy_speed--;
 

}
if((Score%5==0))//分数达到一定时子弹增加
{
Num_bullet++;
 

}
}

if(enemys_y[k]>hight)//下落越界
{
plane[enemys_y[k]][enemys_x[k]]=0;
enemys_y[k]=rand()%2;
enemys_x[k]=rand()%width;
plane[enemys_y[k]][enemys_x[k]]=3;
 
}
if((enemys_y[k]==position_y)&&(enemys_x[k]==position_x))//敌机击中我方
{
    printf("Game is end,your Score are %d ",Score);
    Sleep(50);
    exit(0);

}
 
}





}


void updateWithInput()
{
char key;
int left,k,right;//子弹范围
if(kbhit())
{
key=getch();
if(key=='a')
{
plane[position_y][position_x]=0;
position_x--;
plane[position_y][position_x]=1;
}
if(key=='d')
{
plane[position_y][position_x]=0;
position_x++;
plane[position_y][position_x]=1;
}
if(key=='s')
{
plane[position_y][position_x]=0;
position_y++;
plane[position_y][position_x]=1;
}
if(key=='w')
{
plane[position_y][position_x]=0;
position_y--;
plane[position_y][position_x]=1;
}
if(key==' ')
{
left=position_x-Num_bullet;
right=position_x+Num_bullet;
if(left<=0)
{
  left=0;  
}
if(right>=width)
{
  left=width;  
}
for(k=left;k<=right;k++)//增加子弹数量范围X(left,right)
plane[position_y-1][k]=2;
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

