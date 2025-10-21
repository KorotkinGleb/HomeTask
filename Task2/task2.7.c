#include <stdio.h>
#include <setjmp.h>

jmp_buf begin;
char curlex;
void getlex(void);
int expr(void);
int add(void);
int mult(void);
void error(void);
int mypow(int x, int y);
int mainexpr(void);

int main()
{
	int result;
	setjmp(begin);
	printf("==>");
	getlex();
	result = mainexpr();
	if(curlex != '\n') error();
	printf("\n%d\n", result);
	return 0;
}

void getlex()
{
	while((curlex = getchar()) == ' ');
}

void error()
{
	printf("\nОШИБКА!\n");
	while((curlex = getchar()) != '\n');
	longjmp(begin, 1);
}

int mainexpr()
{
	int e = expr();
	while(curlex == '^')
	{
		getlex();
		int k = expr();
		if(k < 0) error();
		e = mypow(e, k);
	}
	return e;
}

int expr()
{
	int e = add();
	while(curlex == '+' || curlex == '-')
	{
		if(curlex == '+')
		{
			getlex();
			e += add();
		} else
		{
			getlex();
			e -= add();
		}
	}
	return e;
}

int add()
{
	int a = mult();
	while(curlex == '*' ||  curlex == '/')
	{
		if(curlex == '*')
		{
			getlex();
			a *= mult();
		} else
		{
			getlex();
			a /= mult();
		}
	}
	return a;
}

int mult()
{
	int m;
	switch(curlex){
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': m = curlex  - '0'; break;
		case '(': getlex(); m = expr();
			if(curlex == ')') break;
		default: error();
	}
	getlex();
	return m;
}

int mypow(int x, int y)
{
	int z = 1;
	while(y --) z *= x;
	return z;
}
