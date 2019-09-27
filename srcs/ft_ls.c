/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:57:37 by yxie              #+#    #+#             */
/*   Updated: 2019/09/27 11:53:05 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_options(char *str)
{
	ft_printf("get_options: %s\n", str);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	num_fd;
	
	i = 0;
	while (i < argc)
	{
		if	(*argv[i] == '-')
			get_options(argv[i]);
		else
			break;
		i++;
	}
	if (--argc > i)
	{
		num_fd = argc - i;
		ft_printf("num_fd: %d\n", num_fd);
		while (argc > i)
		{
			ft_ls(argv[argc]);
			ft_printf("%s\n", argv[argc]);
			argc--;
		}
	}
	else
	{
		ft_printf(".\n");
		ft_ls(".");
		// the current folder name only
	}
	
	return (0);
}
