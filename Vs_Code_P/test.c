#include <stdio.h>
#include <string.h>
#include "test.h"
#include "soure.h"
//int *UU;
//extern int UU[];

int /*fdf*/ v;
#  /*fdf*/   define  /*fdf*/  df /*fdf*/   N
char *s="dfdfk //dddf";
#define SUM(x) ((x)+(x))
#define DIV(x) ((x)*(x)-(x))
#define ENG_PATH_1 E:\English\listen_to_this\listen to_this_3
#define ENG_PATH_2 "E:\English\listen_to_this\listen to_this_3"

#define N 8
#define pchar char*
typedef char* pchar1;
#define u int[10]//直接定义 u大小为10个int数据空间
typedef int arr[10];//没有替换 arr=int[10] arr p;==int p[10]
 
void fun1(char b[30]);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(int c);
int fun6(void);
void fun7(void);
int* fun9(void);
void fun10(void);
void fun11(void);

struct TestStruct1
{
  short i; //000000 
  char j;  //000002
  char k;  //000003 
  int l;  //000004  
  char x;  //000008
  short y;  //00000A 
}UUU_St;

struct TestStruct2
{  
  char j;  //000000
  short i; //000001 
  char k;  //000003 
  int l;  //000004  
 
};

struct TestStruct3
{
  int l;
  int y;
  int x;
}*Ptest;

struct TestStruct4
{
  int y;
  int x;
  int a[0];
}Small;

struct TestStruct5
{

}Void_St;

enum Enum_Name
{
ENUME_VAR1=1,
ENUME_VAR2,
ENUME_VAR3
}Enum_Variable;

const int*c;
//int const*c;
//int* const c;
//const int* const c;
int Value;

int main(void)
{
 // pchar c1,c2;
 register int a;
 
  pchar1 c1,c2; 
  int *ptr;
  
  arr b;  
  arr *ptrf;  
   ptr=fun9();

  NULL;
  b[4]=ENUME_VAR1;
  ptr=(int *)malloc(sizeof(u));
  ptr[5]=SUM (4);
  

  printf("%d",sizeof(b));
  printf("%d\n",sizeof(Enum_Variable));
// fun1(&a);
// fun2();
 //fun3();
 //fun4();
 //fun5(9);
 // a=fun6();
 // fun7();
  //fun10();
  fun11();
}
//64位的系统 地址大小为8个字节
void fun1(char b[30])
{
  int Value=8;
  char a[100];
  int *p;
  int q=0;
  p=&q;
  printf("%d\n",sizeof(*p));//4 指向的变量大小
  printf("%d\n",sizeof(p));//8 32位系统下指针大小为4个字节
  printf("%d\n",sizeof(a));//100 
  printf("%d\n",sizeof(&a));//8 64位系统地址大小
  printf("%d\n",sizeof(&a[0]));//8 64位系统 地址大小
  printf("%d\n",sizeof(a[0]));//4 

  printf("%d\n",sizeof(*b));//1
  printf("%d\n",sizeof(b));//8 32位系统下指针大小为4个字节
  printf("%d\n",sizeof(*c));//4 指向的变量大小
  printf("%d\n",sizeof(Void_St));//0 空的结构体
}

void fun2(void)
{
  int *p;
  int i=10,j,k;
  p=&i;
  *p=20;

  j=i;
  k=i;
  printf("%d\n",j);
  printf("%d\n",k);


}

void fun3(void)
{
  int a[6]={1,2,3,9,7,6};
  int *Ptr1= (&a+1);
  int *Ptr2=(int *)((int)a+1);
  printf("%x\n",Ptr1[-2]);
  printf("%d,%d",sizeof(struct TestStruct1),sizeof(struct TestStruct2));
  Ptest=(struct TestStruct3*)(0x100000);
  printf("%d,%d",sizeof(Ptest),sizeof(struct TestStruct2));
}


void fun4(void)
{
 int c;
 int arr[3][2]={(0,1),(2,3),(4,5)};
 //int arr[3][2]={{0,1},{2,3},{4,5}};
 //int arr[3][2]={0,1,2,3,4,5};
 int *ptr;
 ptr=arr[0];
 
 //c=getchar();
 //printf("%c\n",c);

 Small.x=1;
 if(Small.y==1)
 {
   printf("大端");
 }
 else
 {
   printf("小端");
 }

}


void fun5(int c)
{
int i;
i=5;
 
printf("%d\n",i);
}

int fun6(void)
{
unsigned int i=9;
const int Vale=9;
//for(i=9;i>=0;i--)
///{

  //printf("%u\n",i);
//}

switch(i)
{

case 9:   break;
case -N:   break;
case 'c':   break;
case N+5:   break;

default: break;

}

return;
}

void fun7(void)
{
 int i;
 int hhh;

 for(i=0,printf("Frist=%d",i);printf("Second=%d",i),i<10;i++,printf("Third=%d",i))
 {
   printf("Fourth=%d",i);

 }
 i=3;
 ++i+ ++i+ ++i;
 i=2/-2;//q*b+r==a;
 i=3%-2;
 i=-3%2;
 i=-3%-2;
 i=1,2,3;
  printf("fiveth=%d",i);

}

static void fun8(void)
{
  static int i=0;
  long  h;
  short k;
  printf("%d\n",sizeof(h));
  printf("%d\n",sizeof(k));
  i++;

}

int* fun9(void)
{
  int *p;
  int a[100];
  p=&a;

  return p;
  
}



void fun10(void)
{
  int i,m;
 

 printf("c1=%d c2=%d c3=%d c4=%d,c5=%d c6=%d",
 (unsigned int)(void*)&UUU_St.i- (unsigned int)(void*)&UUU_St,
 (unsigned int)(void*)&UUU_St.j-(unsigned int)(void*)&UUU_St,
 (unsigned int)(void*)&UUU_St.k-(unsigned int)(void*)&UUU_St,
 (unsigned int)(void*)&UUU_St.l-(unsigned int)(void*)&UUU_St,
 (unsigned int)(void*)&UUU_St.x-(unsigned int)(void*)&UUU_St,
 (unsigned int)(void*)&UUU_St.y-(unsigned int)(void*)&UUU_St);
}

 
void fun11(void)
{
  
 int i=8;
 char j=8;
 int a[5]={'a','b','c','d'};
 int arr[4][2]={0,1,2,3,4,5};
 int *ptr;
 *(a+1)='1';
 char (*p)[4]=a;

 int (*q)[2]=&arr;//q+1=q+5*sizeof(普通类型)

 printf("%x\n",arr[0]);//4 
 printf("%x\n",q[0]);//4 
 printf("%x\n",q[1]);//4 
 printf("%x\n",&arr[1][0]);//4 
}
 