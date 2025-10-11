#include <stdio.h>

long fibo(int n)
{
        if(n == 1 || n == 2)
        {
                return 1;
        }
        return fibo(n - 2) + fibo(n - 1);
}

long fibo_iter(int n)
{
	if(n == 1 || n == 2)
	{
		return 1;
	}
	long n_1 = 1;
	long n_2 = 1;
	long n_f = n_1 + n_2;
	for(int i = 3; i <= n; i ++)
	{
		n_f = n_1 + n_2;
		n_1 = n_2;
		n_2 = n_f;
	}
	return n_f;
}

int main()
{
        int n;
        while(scanf("%d", &n) != EOF)
	{
		printf("%ld\n", fibo_iter(n));
		printf("%ld\n", fibo(n));
	}
        return 0;
}

