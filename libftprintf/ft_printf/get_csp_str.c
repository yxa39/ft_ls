/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_csp_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:05:06 by yxie              #+#    #+#             */
/*   Updated: 2019/09/18 10:34:56 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	get_s_str(char *str, t_param *param)
{
	int		len;
	int		i;
	char	*tmp;
	int		j;

	j = 0;
	tmp = str == 0 ? ft_strdup("(null)") : ft_strdup(str);
	len = (int)ft_strlen(tmp);
	free(param->str);
	if (param->precision < len && *(param->flag_field + 5) == 1)
	{
		len = param->precision;
		param->str = ft_strnew(len);
		i = 0;
		while (param->precision-- > 0)
			param->str[i++] = tmp[j++];
		param->str[i] = '\0';
	}
	else
		param->str = ft_strdup(tmp);
	if (*(param->flag_field + 3) == 1)
		add_zero(param, param->width, 's');
	free(tmp);
}

void	get_c_str(char ch, t_param *param)
{
	param->precision = 0;
	param->c = (char)ch;
	add_zero(param, param->width, 'c');
}

void	get_csp(char format, va_list *ap, t_param *param)
{
	if (format == 'c')
		get_c_str(va_arg(*ap, int), param);
	if (format == 's')
		get_s_str(va_arg(*ap, char *), param);
	if (format == 'S')
		get_s_str(va_arg(*ap, char *), param);
	if (format == 'p')
	{
		get_ouxx_str((unsigned long long)va_arg(*ap, void *), param, 'x');
		*(param->flag_field + 4) = 1;
		add_sign_prefix(param, 'x');
	}
}
