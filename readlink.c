/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:15:46 by yxie              #+#    #+#             */
/*   Updated: 2019/09/20 10:40:15 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int main(int argc, char *argv[])
{
    struct stat sb;
    char *linkname;
    ssize_t r;

   if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

   if (lstat(argv[1], &sb) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

   linkname = malloc(sb.st_size + 1);
    if (linkname == NULL) {
        fprintf(stderr, "insufficient memory\n");
        exit(EXIT_FAILURE);
    }

   r = readlink(argv[1], linkname, sb.st_size + 1);

   if (r < 0) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

   if (r > sb.st_size) {
        fprintf(stderr, "symlink increased in size "
                        "between lstat() and readlink()\n");
        exit(EXIT_FAILURE);
    }

   linkname[sb.st_size] = '\0';

   printf("'%s' points to '%s'\n", argv[1], linkname);

   exit(EXIT_SUCCESS);
}
