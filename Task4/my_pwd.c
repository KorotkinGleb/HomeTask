#include <stdio.h>
#include <unistd.h>

#define MAXLEN 256

int main()
{
	char cur_dir[256];
	getcwd(cur_dir, MAXLEN);
	printf("%s\n", cur_dir);
	return 0;
}
