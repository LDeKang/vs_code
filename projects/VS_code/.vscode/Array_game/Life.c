#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#define hight 25  // 游戏画面尺寸
#define width 50

void startup();// 数据初始化	
void show();  // 显示画面
void updateWithoutInput();  // 与用户输入无关的更新
void updateWithInput();  // 与用户输入有关的更新
void gotoxy(int x,int y);  //光标移动到(x,y)位置

int Life[hight][width];
 
 
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

void startup() //细胞初始化
{
    int i,j;
     
    for(i=0;i<hight;i++)
    {
        for(j=0;j<width;j++)
    {
        Life[i][j]=1;
    }
 
    }

}

void show()//显示细胞
{
    int i,j;
    gotoxy(0,0);
    for(i=1;i<=hight-1;i++)
    {
        for(j=1;j<=width-1;j++)
    {
        if(Life[i][j]==1)
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
   Sleep(50);

}

void updateWithoutInput()
{
     int New_Life[hight][width];//暂存最新数据数组
     int i,j,number;

    for(i=1;i<=hight-1;i++)
    {
        for(j=1;j<=width-1;j++)
        {
            number = Life[i-1][j-1] + Life[i-1][j] + Life[i-1][j+1]
				+ Life[i][j-1] + Life[i][j+1] + Life[i+1][j-1] + Life[i+1][j] + Life[i+1][j+1];
            if(number==3)
            {
                New_Life[i][j]=1;
            }
             else if(number==2)
            {
                New_Life[i][j]= Life[i][j];
            }
            else
            {
                New_Life[i][j]=0;
            }
            
        }
    
    }
     for(i=1;i<=hight-1;i++)
    {
        for(j=1;j<=width-1;j++)
        {
            Life[i][j]=New_Life[i][j];//复制给源数组
        }

    }

}
void updateWithInput()
{

}

void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}