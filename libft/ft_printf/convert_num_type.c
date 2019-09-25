/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:58:27 by yxie              #+#    #+#             */
/*   Updated: 2019/09/18 10:35:26 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

long long int			convert_int_type(long long int num, t_param *param)
{
	if (param->len_field == 0)
		num = (int)num;
	else if (param->len_field == 1)
		num = (char)num;
	else if (param->len_field == 2)
		num = (short int)num;
	else if (param->len_field == 3)
		num = (long int)num;
	return (num);
}

unsigned long long int	convert_un_type(long long int num, t_param *param)
{
	if (param->len_field == 0)
		num = (unsigned int)num;
	else if (param->len_field == 1)
		num = (unsigned char)num;
	else if (param->len_field == 2)
		num = (unsigned short int)num;
	else if (param->len_field == 3)
		num = (unsigned long int)num;
	return (num);
}
