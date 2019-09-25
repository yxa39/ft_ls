/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:06:49 by yxie              #+#    #+#             */
/*   Updated: 2019/09/18 10:35:07 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char		*get_decimal(long double num, int precision)
{
	int		prec;
	char	*str;
	int		i;
	int		precision_copy;
	char	*dec_str;

	precision_copy = precision;
	if (num < 0)
		num *= -1;
	prec = 1;
	i = 0;
	str = ft_strnew(precision + 1);
	str[i++] = '.';
	while (precision-- > 0)
		prec *= 10;
	dec_str = ft_llitoa((int)((num - (int)num) * prec));
	while ((int)ft_strlen(dec_str) < precision_copy--)
		str[i++] = '0';
	prec = 0;
	while (dec_str[prec])
		str[i++] = dec_str[prec++];
	str[i] = '\0';
	free(dec_str);
	return (str);
}

long double	rounding(long double num, t_param *param)
{
	long double	tens;
	int			precision;

	precision = param->precision;
	tens = 1;
	while (precision-- != 0)
		tens *= 10;
	if (num > 0)
		num = ((num * tens) + 0.5) / tens;
	else
		num = ((num * tens) - 0.5) / tens;
	return (num);
}

void		get_float_3(long double num, t_param *param)
{
	char	*tmp;
	char	*dec_str;

	if (param->precision != 0)
	{
		tmp = ft_strdup(param->str);
		free(param->str);
		dec_str = get_decimal((long double)(num - (long long int)num),
				param->precision);
		param->str = ft_strnew((int)(ft_strlen(tmp) + ft_strlen(dec_str)));
		ft_strcat(param->str, tmp);
		ft_strcat(param->str, dec_str);
		free(tmp);
		free(dec_str);
	}
	if (*(param->flag_field + 4) == 1 && *(param->flag_field + 5) ==
			1 && param->precision == 0)
	{
		tmp = ft_strdup(param->str);
		free(param->str);
		param->str = ft_strnew((int)ft_strlen(tmp) + 1);
		ft_strcat(param->str, tmp);
		ft_strcat(param->str, ".");
		free(tmp);
	}
}

void		get_float_2(long double num, t_param *param)
{
	char	*tmp;

	get_float_3(num, param);
	if (param->str[0] == '-')
	{
		tmp = ft_strdup(param->str + 1);
		free(param->str);
		param->str = ft_strdup(tmp);
		free(tmp);
		*(param->flag_field + 6) = 1;
		*(param->flag_field + 2) = 0;
		*(param->flag_field + 1) = 0;
	}
}

void		get_float(va_list *ap, t_param *param)
{
	long double	num;

	if (param->len_field == 5)
		num = (va_arg(*ap, long double));
	else
		num = (long double)va_arg(*ap, double);
	if (*(param->flag_field + 5) == 0)
		param->precision = 6;
	if (num > -1.0 && num < 0.0)
		*(param->flag_field + 6) = 1;
	num = rounding(num, param);
	free(param->str);
	param->str = ft_llitoa((long long int)num);
	get_float_2(num, param);
	if (*(param->flag_field + 3) == 1)
		add_zero(param, param->width, 'f');
	add_sign_prefix(param, 'f');
}
