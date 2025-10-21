#include <stdio.h>

int main()
{
	int n;
	double x, an, p = 0, dp = 0, sp = 0;
	scanf("%d", &n);
	scanf("%lf", &x);
	n += 1;
	while(scanf("%lf", &an) != EOF)
	{
		sp = x * (sp + an / n);
		n -= 1;
		dp = dp * x + p;
		p = p * x + an;
	}
	printf("%.10g\n", p);
	printf("%.10g\n", dp);
	printf("%.10g\n", sp);
	return 0;
}
