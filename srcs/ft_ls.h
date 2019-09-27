/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:27:09 by yxie              #+#    #+#             */
/*   Updated: 2019/09/27 11:53:22 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

void			ft_putstr(char const *s);
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
