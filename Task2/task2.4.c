#include <stdio.h>
#include <string.h>

#define SIZE_S 100

enum STATE {INTEGER, FRACTION, EXPONENT};

double get_pow10(int pow, char sign)
{
	double value = 1.0;
	if(sign == '+' || sign == ' ' || sign == 'F' || sign == 'f' )
	{
		while(pow)
		{
			value *= 10;
			-- pow;
		}
	} else 
	{
		while(pow)
		{
			value /= 10;
			-- pow;
		}
	}
	return value;
}

int get_digit_number(int value)
{
	int count = 0;
	while(value)
	{
		value /= 10;
		++ count;
	}
	return count;
}

double get_double(int integer, int fraction, int exponent, char sign)
{
	return (integer + (double)fraction / get_pow10(get_digit_number(fraction), '+')) * get_pow10(exponent, sign);
}

void update_state(char symbol, enum STATE *state)
{
	if(symbol == '.')
	{
		*state = FRACTION;		
	} else if(symbol == 'E' || symbol == 'e')
	{
		*state = EXPONENT;
	}
	return;
}

void update_sign(char symbol, char *sign)
{
	if(symbol == '+' || symbol == '-' || symbol == 'F' || symbol == 'f')
	{
		*sign = symbol;
	}
	return;
}

void update_value(char symbol, int *value)
{
	if(symbol >= '0' && symbol <= '9')
	{
		*value = (*value) * 10 + symbol - '0';
	}
	return;
}

double str2double_opt(char string[])
{
	int size_string = strlen(string), integer = 0, fraction = 0, exponent = 0, i = 0;
	char sign = ' ';
	int sign_value = 1;
	char prefix = ' ';
	enum STATE state = INTEGER;
	if(string[0] == '-' || string[0] == '+')
	{
		i ++;
		if(string[0] == '-') sign_value = -1;
	}
	for(; i < size_string; i ++)
	{
		switch(state)
		{
			case INTEGER:
				update_value(string[i], &integer);
				update_sign(string[i], &sign);
				update_sign(string[i], &prefix);
				update_state(string[i], &state);
				break;
			case FRACTION:
				update_value(string[i], &fraction);
				update_sign(string[i], &sign);
				update_sign(string[i], &prefix);
				update_state(string[i], &state);
				break;
			case EXPONENT:
				update_value(string[i], &exponent);
				update_sign(string[i], &sign);
				update_sign(string[i], &prefix);
				update_state(string[i], &state);
				break;
		}
	}
	return sign_value * get_double(integer, fraction, exponent, sign);
}

int main()
{
	char s[SIZE_S];
	while(scanf("%s", s) != EOF)
	{
		printf("%.10g\n", str2double_opt(s));
	}
	return 0;
}
