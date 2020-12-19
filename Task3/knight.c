#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
int main(int argc, char **argv)
{
    DIR *dfd;
    struct dirent *dp;
    struct stat file_stat;
    char filename[NAME_MAX];
 
    if ( argc < 2 )
        strcpy(filename, ".");
    else
        strcpy(filename, argv[1]);
 
    if ( !(dfd=opendir(filename)) )
        return 1;
 
    while( (dp=readdir(dfd)) != NULL ){
	strcpy(filename, "/");
	strcpy(filename, dp->d_name);
	stat(filename, &file_stat );
	switch (file_stat.st_mode & S_IFMT) {
            case S_IFBLK:  printf("b "); break;
            case S_IFCHR:  printf("c "); break; 
            case S_IFDIR:  printf("d "); break; //It's a (sub)directory 
            case S_IFIFO:  printf("p "); break; //fifo
            case S_IFLNK:  printf("l "); break; //Sym link
            case S_IFSOCK: printf("s "); break;
            //Filetype isn't identified
            default:       printf("- "); break;
                }
	 printf( (file_stat.st_mode & S_IRUSR) ? " r" : " -");
        printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
        printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
	  printf("\t%d ", file_stat.st_nlink);       

 printf("%s\n", dp->d_name);
 	}


    closedir(dfd);
    return 0;
}

