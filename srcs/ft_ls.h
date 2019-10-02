/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:27:09 by yxie              #+#    #+#             */
/*   Updated: 2019/10/02 12:27:45 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <libc.h>

void			ft_putstr(char const *s);
char			*ft_strdup(const char *s1);
int				ft_printf(char *format, ...);
typedef struct			s_details
{
	int					total;
	char				pms[11];
	int					nol;
	char				*uid;
	char				*gid;
	int					size;
	char				*time;
	char				*filename;
	struct s_details 	*next;
}						t_details;

#endif
