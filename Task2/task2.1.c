#include <stdio.h>

double d_abs(double a)
{
	if(a >= 0) return a;
	return -a;
}

double N_sqrt(double x, double eps)
{
	double x_prev = 1;
	double x_next = 0.5 * (x_prev + x / x_prev);
	while(d_abs(x_next - x_prev) >= eps)
	{
		x_prev = x_next;
		x_next = 0.5 * (x_prev + x / x_prev);
	}
	return x_next;
}

int main()
{
	double x, eps;
	scanf("%lf", &eps);
	while(scanf("%lf", &x) != EOF)
	{
		printf("%.10g\n", N_sqrt(x, eps));
	}
	return 0;
}
