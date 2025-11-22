#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 16

void prefix_function(char *s_data, int *prefix_max_len)
{
        int position = 1, suffix = 1;
        prefix_max_len[0] = 0;
        while(s_data[position])
        {
                suffix = position;
                while(1)
                {
                        suffix = prefix_max_len[suffix - 1];
                        if(s_data[suffix] == s_data[position])
                        {
                                prefix_max_len[position] = suffix + 1;
                                break;
                        }
                        if(suffix == 0)
                        {
                                prefix_max_len[position] = 0;
                                break;
                        }
                }
                ++ position;
        }
}

void merge_strings(char *s_data, char *s_find, char *buffer)
{
        while(1)
        {
                if(*s_find)
                {
                        *buffer = *s_find;
                } else
                {
                        break;
                }
                ++ buffer;
                ++ s_find;
        }
        *buffer = '#';
        ++ buffer;
        while(1)
        {
                if(*s_data)
                {
                        *buffer = *s_data;
                } else
                {
                        break;
                }
                ++ buffer;
                ++ s_data;
        }
        *buffer = '\0';
}

int insubstr(char *substr, char *str)
{
	int i_data = 0, i_find = 0;
        i_data = strlen(str);
        i_find = strlen(substr);
	char *merged_str = malloc(sizeof(char) * (i_data + i_find + SIZE));
        int *prefix_max_len = malloc(sizeof(int) * (i_data + i_find + SIZE));
        merge_strings(str, substr, merged_str);
        prefix_function(merged_str, prefix_max_len);
        for(int j = i_find + 1; j < i_data + i_find + 1; j ++)
        {
                if(prefix_max_len[j] == i_find)
                {
			free(merged_str);
        		free(prefix_max_len);
                        return 1;
                }
        }
	free(merged_str);
	free(prefix_max_len);
	return 0;
}

int main(int argc, char **argv)
{
	char *str = malloc(sizeof(char) * SIZE);
	int fd, c, cur = 0, len = SIZE, flag_v = 0, flag_s = 0, line = 0;
	if(!strcmp("-v", argv[1]) || !strcmp("-v", argv[2]))
		flag_v = 1;
	if(!strcmp("-s", argv[1]) || !strcmp("-s", argv[2]))
		flag_s = 1;
	fd = open(argv[2 + flag_v + flag_s], O_RDONLY, 0644);
	dup2(fd, 0);
	while((c = getchar()) != EOF)
	{
		if(!(cur < len)){
			str = realloc(str, len + SIZE);
			len += SIZE;
		}
		if((c == '\0' || c == '\n') && cur > 1){
			str[cur] = '\0';
			line ++;
			int in = insubstr(argv[1 + flag_s + flag_v], str);
			if(in && !flag_v)
				if(flag_s)
					printf("%d %s\n",line, str);
				else
					printf("%s\n", str);
			else if(!in && flag_v)
				if(flag_s)
					printf("%d %s\n", line, str);
				else
					printf("%s\n", str);
			memset(str, 0, len);
			cur = 0;
			continue;
		} else{
			str[cur] = c;
			cur ++;
		}
	}
	free(str);
	close(fd);
	return 0;
}
