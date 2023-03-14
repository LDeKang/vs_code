#include <iostream>
#include <stdio.h>
using namespace std;

void hannuota(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("%c->%c\n\r", A, C);
    }
    else
    {
        hannuota(n - 1, A, C, B);
        printf("%c->%c\n\r", A, C);
        hannuota(n - 1, B, A, C);
    }
}

int main()
{
    int nb=2;
    char A = 'A';
    char B = 'B'; 
    char C = 'C';

    cout <<"Please enter your number:"<< endl;
    std::cin >> nb;
    hannuota(nb,A,B,C);
    return 0;
}