/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:31:51 by yxie              #+#    #+#             */
/*   Updated: 2019/09/18 10:48:37 by yxie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# define NUMERALS "0123456789abcdef"
# define NUMERALS_CAP "0123456789ABCDEF"
# define MAXINT "9223372036854775807"
# define MININT "-9223372036854775808"

typedef struct			s_param
{
	int		len_field;
	int		flag_field[7];
	int		width;
	int		precision;
	char	*str;
	int		len;
	char	c;
	int		error;
}						t_param;

int						get_width(char **format);
void					init_param(t_param *param);
void					get_flag_field(char **format, t_param *param);
void					print(t_param *param, char format);
void					add_sign_prefix(t_param *param, char format);
void					get_len_field(char **format, t_param *param);
void					get_param(char **format, t_param *param);
int						get_j(char format, t_param *param);
void					add_zero(t_param *param, int width, char format);
void					get_s_str(char *str, t_param *param);
void					get_c_str(char ch, t_param *param);
long long int			convert_int_type(long long int num, t_param *param);
unsigned long long int	convert_un_type(long long int num, t_param *param);
void					get_di_str(long long int num, t_param *param);
void					get_ouxx_str(unsigned long long int num,
		t_param *param, char format);
void					get_csp(char format, va_list *ap, t_param *param);
void					get_diouxx(char format, va_list *ap, t_param *param);
char					*get_decimal(long double num, int precision);
long double				rounding(long double num, t_param *param);
void					get_float(va_list *ap, t_param *param);
void					get_percent(t_param *param);
int						what_to_print(char **format, va_list *ap);
int						get_un_long_strlen(unsigned long long int n, int base);
int						get_long_strlen(long long int n);
char					*ft_un_llitoa(unsigned long long int n, int base,
		char format);
char					*ft_llitoa(long long int n);
int						ft_printf(char *format, ...);
#endif
