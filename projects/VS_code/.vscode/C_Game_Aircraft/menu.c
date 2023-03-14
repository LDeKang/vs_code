#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

void Main_Mune(void);  // 显示画面
void Sub_Mune1(void);
void Sub_Mune2(void);
void Sub_Mune3(void);

void Sub_Mune1_1(void);
void Sub_Mune1_2(void);
void Sub_Mune1_3(void);

void Sub_Mune2_1(void);
void Sub_Mune2_2(void);

void Sub_Mune3_1(void);
void Sub_Mune3_2(void);

char Key_Scan(void);
void gotoxy(int x,int y);  //光标移动到(x,y)位置

int Index_Value=0;
int Index_Offest=0;
typedef struct Mune_St
{
  int Sub_Top_Offest;
  int Sub_Boon_Offest;
  void (*Fun_Ptr)();
}MUNE_ST;

MUNE_ST Mune_List[15]=
{
    {1,0,Main_Mune},
    {3,1,Sub_Mune1},
    {5,2,Sub_Mune2},
    {6,3,Sub_Mune3},
    {0,3,Sub_Mune1_1},
    {0,4,Sub_Mune1_2},
    {0,5,Sub_Mune1_3},

    {0,5,Sub_Mune2_1},
    {0,6,Sub_Mune2_2},

    {0,6,Sub_Mune3_1},
    {0,6,Sub_Mune3_2},
};

int main()
{
    char Key_Value;
    Index_Offest=Mune_List[Index_Value].Sub_Top_Offest;
    Mune_List->Fun_Ptr();

	while (1) //  游戏循环执行
	{
        gotoxy(0,0);
        Key_Value=Key_Scan();

        switch (Key_Value)
        {
        case'1':
             Index_Value=+Index_Offest;
             Index_Value+=0;

            break;
        case'2':
             Index_Value=+Index_Offest;
             Index_Value+=1;

            break;
        case'3':
             Index_Value=+Index_Offest;
             Index_Value+=2;

            break;
        case'0':
           //  Index_Value-=Index_Offest;

            break;
        default:
            break;
        }
        Mune_List[Index_Value].Fun_Ptr();
	}
	return 0;
}

char Key_Scan(void)
{
    char ch;
    if (_kbhit() != 0) //如果键盘被敲击
    {
        ch = _getch(); //获取键值
    }

    return ch;
}
void Main_Mune()// 显示画面
{
    gotoxy(0,0);
    printf("------ Main_Mune------\n");
    printf("\n");
    printf("       Sub_Mune1       \n");
    printf("\n");
    printf("       Sub_Mune2       \n");
    printf("\n");
    printf("       Sub_Mune3       \n");

}  
void Sub_Mune1()// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune1------\n");
    printf("\n");
    printf("       Sub_Mune1_1      \n");
    printf("\n");
    printf("       Sub_Mune1_2      \n");
    printf("\n");
    printf("       Sub_Mune1_3      \n");
    Index_Offest=Mune_List[Index_Value].Sub_Top_Offest;
}  
 
void Sub_Mune2(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune2------\n");
    printf("\n");
    printf("       Sub_Mune2_1    \n");
    printf("\n");
    printf("       Sub_Mune2_2    \n");
    printf("\n");
    printf("                         \n");
    Index_Offest=Mune_List[Index_Value].Sub_Top_Offest;
} 
void Sub_Mune3(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune3------\n");
    printf("\n");
    printf("       Sub_Mune3_1       \n");
    printf("\n");
    printf("       Sub_Mune3_2       \n");
    printf("\n");
    printf("                         \n");
    Index_Offest=Mune_List[Index_Value].Sub_Top_Offest;
} 
void Sub_Mune1_1(void) 
{
    gotoxy(0,0);
    printf("------ Sub_Mune1_1------\n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");

} 

void Sub_Mune1_2(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune1_2------\n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");

} 

void Sub_Mune1_3(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune1_3------\n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");

} 

void Sub_Mune2_1(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune2_1------\n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");

} 

void Sub_Mune2_2(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune2_2------\n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");

} 

void Sub_Mune3_1(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune3_1------\n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");

} 

void Sub_Mune3_2(void)// 显示画面
{
    gotoxy(0,0);
    printf("------ Sub_Mune3_2------\n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");
    printf("\n");
    printf("                         \n");

} 
void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}


