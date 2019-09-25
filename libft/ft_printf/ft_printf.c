/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:00:07 by yxie              #+#    #+#             */
/*   Updated: 2019/09/18 10:35:39 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	prep_print(char **format, t_param *param)
{
	if (param->error != 2)
	{
		print(param, **format);
		if (param->error == 1)
		{
			ft_putchar(**format);
			param->len++;
		}
		(*format)++;
	}
}

void	print(t_param *param, char format)
{
	int	int_len;

	if (format == 'c')
		param->len = 1 + (int)ft_strlen(param->str);
	else
		param->len = (int)ft_strlen(param->str);
	int_len = param->len;
	if (*(param->flag_field) == 0 && param->width - int_len > 0)
	{
		param->len = param->width;
		while ((param->width-- - int_len) > 0)
			ft_putchar(' ');
	}
	ft_putstr(param->str);
	if (format == 'c')
		ft_putchar(param->c);
	if (*(param->flag_field) == 1 && param->width - int_len > 0)
	{
		param->len = param->width;
		while (param->width-- - int_len > 0)
			ft_putchar(' ');
	}
}

void	get_percent(t_param *param)
{
	free(param->str);
	param->str = ft_strnew(1);
	param->str[0] = '%';
	add_zero(param, param->width, '%');
}

int		what_to_print(char **format, va_list *ap)
{
	t_param	*param;
	int		len;

	param = (t_param *)malloc(sizeof(t_param));
	get_param(format, param);
	if (**format == '\0')
		param->error = 2;
	else if (ft_strchr("cspS", **format))
		get_csp(**format, ap, param);
	else if (ft_strchr("diouUxX", **format))
		get_diouxx(**format, ap, param);
	else if (ft_strchr("f", **format))
		get_float(ap, param);
	else if (**format == '%')
		get_percent(param);
	else
	{
		param->error = 1;
		param->width--;
	}
	prep_print(format, param);
	free(param->str);
	len = param->len;
	free(param);
	return (len);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format && ft_strchr("-+ 0#.hlL123456789csSpdiouUxXf%jzt",
			*format))
				len += what_to_print(&format, &ap);
		}
		else if (*format && *format != '%')
		{
			ft_putchar(*format);
			len++;
			format++;
		}
	}
	va_end(ap);
	return (len);
}
