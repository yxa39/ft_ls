/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:38:34 by yxie              #+#    #+#             */
/*   Updated: 2019/09/25 11:18:04 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
 
int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;
 
    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)    
        return 1;
 
    printf("Information for %s\n",argv[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%d bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%d\n",fileStat.st_ino);
 
    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

   printf("S_ISLINK: %d\n", S_ISLNK(fileStat.st_mode) );	
    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode) ? "is" : "is not"));
	
	
	printf("st_atime: the most recent time that the file was accessed: %lld\n", &fileStat.st_atime);
	
	struct tm *time;
	char buffer[200];
	time = localtime(&fileStat.st_atime);
	strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", time);
	printf("%s\n", buffer);
	
	struct passwd *pwd;
	pwd = getpwuid(fileStat.st_uid);
	if(pwd == NULL) {
    	perror("getpwuid");
	} else {
    	printf("%s\n", pwd->pw_name);
	} 
	struct group *grp;
	grp = getgrgid(fileStat.st_gid);
	if(grp == NULL) {
    	perror("getgrigid");
	} else {
    	printf("%s\n", grp->gr_name);
	} 

	return 0;
}
