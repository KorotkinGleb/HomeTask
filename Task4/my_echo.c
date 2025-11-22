#include <stdio.h>
#include <string.h>

#define NOENTER 0
#define NOTABS 1

int main(int argc, char **argv)
{
	int i;
	int flags[2];
	flags[0] = 0;
	flags[1] = 0;
	for(i = 1; i < argc; i ++){
		if(!strcmp("-n", argv[i]))
			flags[NOENTER] = 1;
		if(!strcmp("-s", argv[i]))
			flags[NOTABS] = 1;
	}
	for(i = 1 + flags[0] + flags[1]; i < argc; i ++){
		if(flags[NOTABS])
			printf("%s", argv[i]);
		else
			if(i != argc - 1)
				printf("%s ", argv[i]);
			else
				printf("%s", argv[i]);
	}
	if(!flags[NOENTER])
		printf("\n");
	return 0;
}
