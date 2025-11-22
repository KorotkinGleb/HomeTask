#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int count_strs()
{
	int c, count = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
			count ++;
	}
	return count;
}

int main(int argc, char **argv)
{
	int count, fd, c, n = 10, sign = 0;
	if(argc == 2){
		fd = open(argv[1], O_RDONLY, 0644);
	} else if(argc == 3)
	{
		fd = open(argv[2], O_RDONLY, 0644);
		n = atoi(&argv[1][1]);
		if(argv[1][0] == '+')
			sign = 1;
	}
	dup2(fd, 0);
	count = count_strs();
        rewind(stdin);
        char *str = malloc(sizeof(char) * SIZE);
        int len = SIZE, cur_byte = 0, cur_str = 0;
        while((c = getchar()) != EOF)
        {
		if(!(cur_byte < len))
			len += SIZE;
                        str = realloc(str, len);
              	if(c == '\n'){
                         cur_str += 1;
                         str[cur_byte] = '\0';
                         cur_byte = 0;
                         if(cur_str > count - n && !sign)
                                printf("%s\n", str);
			 else if(cur_str >= n && sign)
				 printf("%s\n", str);
                        memset(str, 0, len);
                } else
                {
                        str[cur_byte] = c;
                        cur_byte ++;
		}
	}
	free(str);
        close(fd);

	return 0;
}

