#include <stdio.h>

char shortBITS()
{
	short c = 1;
        char count = 0;
        while(c != 0)
        {
                c = c << 1;
                ++ count;
        }
        return count;
}


char intBITS()
{
	int c = 1;
	char count = 0;
	while(c != 0)
	{
		c = c << 1;
		++ count;
	}
	return count;
}

char longBITS()
{
	long c = 1;
        char count = 0;
        while(c != 0)
        {
                c = c << 1;
                ++ count;
        }
        return count;
}

char floatBYTES()
{
	float a, b;
	char *ptr_a =(char *)&a;
	char *ptr_b = (char *)&b;
	return (ptr_a > ptr_b) ? (ptr_a - ptr_b) : (ptr_b - ptr_a);
}

char doubleBYTES()
{
	double a, b;
        char *ptr_a =(char *)&a;
        char *ptr_b = (char *)&b;
        return (ptr_a > ptr_b) ? (ptr_a - ptr_b) : (ptr_b - ptr_a);
}

char longdoubleBYTES()
{
	long double a, b;
        char *ptr_a =(char *)&a;
        char *ptr_b = (char *)&b;
        return (ptr_a > ptr_b) ? (ptr_a - ptr_b) : (ptr_b - ptr_a);
}

char longdoubleBYTESRAW()
{
        long double a, b;
        char *ptr_a =(char *)&a;
        char *ptr_b = (char *)&b;
        return ptr_a - ptr_b;
}

int main()
{
	printf("short BYTES %d\n", shortBITS() / 8);
	printf("int BYTES %d\n", intBITS() / 8);
	printf("long BYTES %d\n", longBITS() / 8);
	printf("float BYTES %d\n", floatBYTES());
	printf("double BYTES %d\n", doubleBYTES());
	printf("long double BYTES %d\n", longdoubleBYTES());
	printf("long double BYTES RAW %d\n", longdoubleBYTESRAW());
	return 0;
}
