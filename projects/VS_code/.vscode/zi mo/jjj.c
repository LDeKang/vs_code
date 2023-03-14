#include<stdio.h>

int main(void)
{
	int  j=0,flag=0;
	char String_A[]="sfdsffds";
	char String_B[] = "123";

	for (int i = 0; String_A[i] != '\0';i++)
	{
		if (String_B[j] == String_A[i])
		{
			if (String_B[j] == '\0')
			{
				flag = 1;
				break;
				
			}
			j++;
		}

	}
	if (flag==1)
	{
		printf("匹配成功");
	}
	else
	{
		printf("匹配失败");
	}

}