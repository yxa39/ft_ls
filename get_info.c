/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:38:34 by yxie              #+#    #+#             */
/*   Updated: 2019/10/02 12:46:48 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <sys/xattr.h>

#include <sys/acl.h>
#include <libc.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
 
int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;
 
    struct stat fileStat;
    if(lstat(argv[1],&fileStat) < 0)    
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
	pwd = NULL;
	if(pwd == NULL) {
    	perror("getpwuid");
		ft_putchar('X');
		strerror(0);
		ft_putchar('X');
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
	struct dirent *pDirent;
     
	DIR *pDir;

        if (argc < 2) {
            printf ("Usage: testprog <dirname>\n");
            return 1;
        }
        pDir = opendir (argv[1]);
        if (pDir == NULL) {
            printf ("Cannot open directory '%s'\n", argv[1]);
   //         return 1;
		}
		else 
		{
 			while ((pDirent = readdir(pDir)) != NULL) 
			{
        		printf ("[%s]\n", pDirent->d_name);
      		}
        	closedir (pDir);
		}

	acl_t acl = NULL;
    acl_entry_t dummy;
    ssize_t xattr = 0;
    char chr;
    char * filename = "/nfs/2018/y/yxie/Working_folder/ft_ls_github/a.txt";

	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
    if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
        acl_free(acl);
        acl = NULL;
    }
    xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
    if (xattr < 0)
        xattr = 0;
	printf("xattr: %d\n", xattr);
    if (xattr > 0)
        chr = '@';
    else if (acl != NULL)
        chr = '+';
    else
        chr = ' ';

    printf("chr: %c\n", chr);

	char buf[1024];
	size_t len;
	char *filename_2 = "/nfs/2018/y/yxie/Working_folder/ft_ls_github/test_symbolic.c";
	if ((len = readlink(filename_2, buf, sizeof(buf)-1)) != -1)
    	buf[len] = '\0';
	printf("symbolic link: %s\n", buf);

	int             ret;
    struct stat     bur;

	ret = stat(".", &bur);
	if (ret < 0)
	{
		printf("stat failed, errno");
		exit(0);
	}
	printf("File system block size is = %d\n",bur.st_blksize);
	return 0;
}
