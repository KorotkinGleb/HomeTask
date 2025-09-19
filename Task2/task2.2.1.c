#include <stdio.h>

int main()
{
	double x, an, bn_next = 0, bn_prev;
	int iter = 0;
	while(1)
	{
		if(scanf("%lf", &an) == EOF) break;
		switch(iter)
		{
			case 0:
				x = an;
				break;
			case 1:
				bn_next = an;
				break;
			default:
				bn_prev = bn_next;
				bn_next = an + bn_prev * x;
				break;
		}
		++ iter;
	}
	printf("%.10g\n", bn_next);
	return 0;
}
