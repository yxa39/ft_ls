/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:01:49 by yxie              #+#    #+#             */
/*   Updated: 2019/09/18 10:34:09 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		get_j(char format, t_param *param)
{
	int	j;

	j = *(param->flag_field + 1) + *(param->flag_field + 4) +
		*(param->flag_field + 6);
	if (*(param->flag_field + 2) == 1 && *(param->flag_field + 1) == 0)
		j++;
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
		j++;
	return (j);
}

void	add_zero_2(t_param *param, char **tmp, int width, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	free(param->str);
	param->str = ft_strnew(width);
	while (width-- - len > 0)
		param->str[i++] = '0';
	while ((*tmp)[j])
		param->str[i++] = (*tmp)[j++];
}

void	add_zero(t_param *param, int width, char format)
{
	char	*tmp;
	int		len;

	if (format == 'c')
		len = 1;
	else
		len = (int)ft_strlen(param->str);
	tmp = ft_strdup(param->str);
	if (*(param->flag_field + 5) != 1 || format == 'f')
		len += get_j(format, param);
	if ((*(param->flag_field + 3) == 1 && *(param->flag_field) == 0) ||
			*(param->flag_field + 5) == 1)
		if (width - len > 0)
			add_zero_2(param, &tmp, width, len);
	free(tmp);
}

int		add_sign_prefix_2(t_param *param, char format, int i)
{
	if (*(param->flag_field + 1) == 1)
		param->str[i++] = '+';
	if (*(param->flag_field + 6) == 1)
		param->str[i++] = '-';
	if (*(param->flag_field + 2) == 1 && *(param->flag_field + 1) == 0)
		param->str[i++] = ' ';
	if (*(param->flag_field + 4) == 1 && ft_strchr("o", format) &&
			param->precision == 0)
		param->str[i++] = '0';
	if (*(param->flag_field + 4) == 1 && ft_strchr("xX", format))
	{
		param->str[i++] = '0';
		param->str[i++] = format;
	}
	return (i);
}

void	add_sign_prefix(t_param *param, char format)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(param->str);
	i = *(param->flag_field + 1) + *(param->flag_field + 4) * 2 +
		*(param->flag_field + 6);
	if (i > 0)
	{
		free(param->str);
		param->str = ft_strnew((int)ft_strlen(tmp) + i);
	}
	i = 0;
	i = add_sign_prefix_2(param, format, i);
	j = 0;
	while (tmp[j])
		param->str[i++] = tmp[j++];
	param->str[i] = '\0';
	free(tmp);
}
