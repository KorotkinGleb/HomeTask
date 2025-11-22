#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd_f, fd_t, c;
	if(strcmp(argv[1], argv[2])){
		fd_f = open(argv[1], O_RDONLY, 0644);
		fd_t = open(argv[2], O_WRONLY | O_TRUNC, 0644);
		dup2(fd_f, 0);
		dup2(fd_t, 1);
		while((c = getchar()) != EOF)
			putchar(c);
	} else
		printf("error: same files\n");
	return 0;
}
