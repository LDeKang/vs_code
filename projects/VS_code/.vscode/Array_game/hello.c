#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
double price=200.0;
void test01()
{
printf("%2f\n",price);
}
void test02()
{
double price=250.0;
printf("%2f\n",price);

}

int main()
{
double price=208.0;
printf("mian=%2f\n",price); 
  test01();
  test02();
  test01();
 printf("mian=%2f\n",price); 
}
