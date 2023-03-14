#include <iostream>
#include <stdio.h>
using namespace std;
int num_str_fun(int num);
int num_fun(int n);
int main(void)
{
    int num;
    cout <<"Please enter your number:"<< endl;
     std::cin >> num;
    // cout <<"string:"<< endl;
    // num_str_fun(num);
   //printf("%d",num_fun(4));
    cout<<num_fun(num)<<endl;
    return 0;
}

int num_fun(int n)
{
    if(n==1)
    {
        return 1;
    }
   
   return n*n+num_fun(n-1);
}

int num_str_fun(int num)
{
    if(num==0)
    {
        return 0;
    }

    num_str_fun(num/10);
    cout.put(num%10+0x30);
    //printf("%c",(num%10+0x30));
}

