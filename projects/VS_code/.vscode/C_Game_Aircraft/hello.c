#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

//游戏名称：限时记分飞机小游戏\
击杀目标后，记分，并生成随机位置，时间到结束游戏
int main()
{
    int i, j, X = 10, Y = 10, flag = 0, isKilled = 0, nx = 5, Score = 0, time = 600;
    //flag:按键启动标志，使未按下时目标稳定,isKilled:击杀物存在标志\
    Score:记分 time:游戏时间

    char key;
    while (1)
    {
    //-------------------------显示模块-------------------------------
        if (flag == 1)//记分开始，按下按键以后
        {
            time--;
        }
        system("cls");
        //显示记分，时间，时间结束退出循环
        printf("SCORE:%d,Game end time %d\n", Score, time);
        if (time == 0)
        {
            system("cls");
            break;
        }
        //---------------------------------------------------
        if (!isKilled)
        {

            for (i = 0; i < nx; i++)
            {
                printf(" ");             //生成随机目标

            }
            printf("+\n");

        }
        isKilled = 0;  //在未击杀时，目标不会消失
        //按键判断，按下产生激光----------------------------------------------
        if (flag == 0)
        {
            for (i = 0; i < Y; i++)
            {
                printf("\n");

            }

        }
        else
        {
            for (i = 0; i < Y; i++)
            {

                for (j = 0; j < X; j++)
                {
                    printf(" ");

                }
                printf("|\n");
            }
        }
        //------------------------------------------------------------------
        if ((nx == X))//击杀时，生成随机位置
        {
            nx = rand() % 28;
            isKilled = 1;
            Score++;
        }
        //--------------------图形生成---------------------------
        for (i = 0; i < X; i++)
        {
            printf(" ");
        }

        printf("*\n");
        for (i = 0; i < (X - 2); i++)
        {
            printf(" ");
        }
        printf("*****\n");
        for (i = 0; i < (X - 1); i++)
        {
            printf(" ");

        }
        printf("* *\n");
        //----------------按键判断-------------------------------------------------------------
        if (kbhit())
        {
            key = getch();
            if (key == 'a')
            {
                X--;
            }
            if (key == 'd')
            {
                X++;
            }
            if (key == 'w')
            {
                Y--;
            }
            if (key == 's')
            {
                Y++;
            }
            flag = 1;
        }

    }

    return 0;
}
