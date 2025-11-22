#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open(".", O_RDONLY, 0644);
	char data[20];
	read(fd, data, 10);
	printf("%s\n", data);
	close(fd);
}
