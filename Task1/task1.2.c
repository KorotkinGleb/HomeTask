#include <stdio.h>

int main()
{
	char a;
	scanf("%c", &a);
	char flag = 0;
	while(a <= 255)
	{
		++ a;
		if(a < 0)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		printf("singned char\n");
	} else
	{
		printf("unsigned char\n");
	}
	return 0;
}
