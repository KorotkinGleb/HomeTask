#include <stdio.h>
int main()
{
	double x, an, p = 0, dp = 0;
	scanf("%lf", &x);
	while((scanf("%lf", &an) != EOF))
	{
		dp = dp * x + p; 
		p = p * x + an;
	}
	printf("%.10g\n", p);
	printf("%.10g\n", dp);
	return 0;
}
