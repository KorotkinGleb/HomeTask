#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

#define RECUR 0
#define ATTR 1
#define GRP 2

void display_file_type(int st_mode) 
{                                   
    switch (st_mode & __S_IFMT)
    {
        case __S_IFDIR: putchar('d'); return;
        case __S_IFCHR: putchar ('c'); return;
        case __S_IFBLK: putchar ('b'); return;
        case __S_IFREG: putchar ('-'); return;
        case __S_IFLNK: putchar ('l'); return;
        case __S_IFSOCK: putchar ('s'); return;
    }
}

void display_permission(int st_mode)
{
	static const char xtbl[10] = "rwxrwxrwx";
	char amode[10];
	int i, j;
	for (i = 0, j = (1 << 8); i < 9; i++, j >>= 1)
		amode[i] = (st_mode&j) ? xtbl[i]: '-';
	if (st_mode & __S_ISUID) amode[2]= 's';
	if (st_mode & __S_ISGID) amode[5]= 's';
	if (st_mode & __S_ISVTX) amode[8]= 't';
	amode[9]='\0';
	printf ("%s ", amode);
}

void file_info(struct stat stbuf)
{
	struct passwd *pw_d;
	display_file_type(stbuf.st_mode);
	display_permission(stbuf.st_mode);
	pw_d = getpwuid(stbuf.st_uid);
	printf("%s ", pw_d->pw_name);
	printf("%ld ", stbuf.st_size);
}

int isdir(struct stat stbuf)
{
	 if((stbuf.st_mode & __S_IFMT) == __S_IFDIR)
		 return 1;
	 return 0;
}

void dirwalk(char *name, int *flags)
{
	int fd;
	DIR *dfd;
	struct dirent *dp;
	struct stat stbuf;
	dfd = opendir(name);
	chdir(name);
	while((dp = readdir(dfd)) != NULL){
		if(!strcmp(dp->d_name, "..") || !strcmp(dp->d_name, "."))
			continue;
		lstat(dp->d_name, &stbuf);
		if(isdir(stbuf) && flags[RECUR]){
			dirwalk(dp->d_name, flags);
			chdir("..");
		}
		if(flags[GRP]){
			struct group *grp;
			grp = getgrgid(stbuf.st_gid);
			printf("%s ", grp->gr_name);
		}
		if(flags[ATTR])
		{
			file_info(stbuf);
		}	
		printf("%s\n", dp->d_name);
	}
	free(dp);
	free(dfd);
}

int main(int argc, char **argv)
{
	int i = 1;
	int flags[3] = {0, 0, 0};
	if(argc == 1){
		dirwalk(".", flags);
		exit(0);
	}
	for(; i < 4 && argc > i; i ++)
	{
		if(!strcmp(argv[i], "-R"))
			flags[RECUR] = 1;
		 else if(!strcmp(argv[i], "-l"))
			flags[ATTR] = 1;
		else if(!strcmp(argv[i], "-g"))
			flags[GRP] = 1;
		 else
			break;
	}
	dirwalk(".", flags);
	return 0;
}

