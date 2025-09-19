#include <stdio.h>

int main()
{
	char a = 127;
	++ a;
	if(a == -128)
	{
		printf("signed char\n");
	} else if(a == 128)
	{
		printf("unsigned char\n");
	}
	return 0;
}
