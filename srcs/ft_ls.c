/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:57:37 by yxie              #+#    #+#             */
/*   Updated: 2019/10/02 13:54:06 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_options(char *str)
{
	ft_printf("get_options: %s\n", str);
}

void	get_fd(char *str)
{
	struct dirent	*pDirent;
	DIR				*pDir;

	pDir = opendir(str);
	if (pDir == NULL)
		printf ("Cannot open directory '%s'\n", str);
	else
	{
 		while ((pDirent = readdir(pDir)) != NULL)
        	printf ("[%s]\n", pDirent->d_name);
        closedir (pDir);
	}
}

void	get_block_size(char *str)
{
	
}

int	main(int argc, char *argv[])
{
	int	i;
	int	num_fd;
	
	i = 1;
	while (i < argc)
	{
		if	(*argv[i] == '-')
		{
			ft_putstr("- showed\n");		
			get_options(argv[i++]);
		}
		else
			break;
	}
	i--;
	if (--argc > i)
	{
		num_fd = argc - i;
		ft_printf("num_fd: %d\n", num_fd);
		while (argc > i)
		{
//			ft_ls(argv[argc]);
			ft_printf("%s\n", argv[argc]);
			get_fd(argv[argc]);
			argc--;
		}
	}
	else
	{
		ft_printf(".\n");
//		ft_ls(".");
		// the current folder name only
	}
	
	return (0);
}
