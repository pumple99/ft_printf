/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:18:38 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 18:18:00 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define ERR_MALLOC -1
# define ERR_RETURN_OVER -2
# define ERR_WIDTH_OVER -3
# define ERR_PRECISION -4

typedef unsigned long long	t_ull;
typedef struct s_conv
{
	int		plus;
	int		minus;
	int		zero;
	int		blank;
	int		hash;
	int		point;
	t_ull	width;
	t_ull	precision;
	char	specifier;
}	t_conv;

//ft_printf.c
int		ft_printf(const char *format, ...);

//ft_str_manage.c
char	*null_join(char *str1, char *str2);
int		join_plain_str(const char **format, char **print_str);
int		join_conversion_str(const char **format, \
char **print_str, va_list *ap);
int		malloc_set(char **str, char c, t_ull size, int *err);

//ft_parse.c
int		parse_format(const char **format, t_conv *conv_option);

//ft_conversion.c
char	*converge_format(t_conv conv_option, va_list *ap, int *err);
char	*conv_c(t_conv conv_option, va_list *ap, int *err);
char	*conv_s(t_conv conv_option, va_list *ap, int *err);
char	*conv_i(t_conv conv_option, va_list *ap, int *err);
char	*conv_d(t_conv conv_option, va_list *ap, int *err);

//ft_conversion2.c
char	*conv_p(t_conv conv_option, va_list *ap, int *err);
char	*conv_u(t_conv conv_option, va_list *ap, int *err);
char	*conv_x(t_conv conv_option, va_list *ap, int *err);
char	*conv_x_capital(t_conv conv_option, va_list *ap, int *err);
char	*conv_percent(t_conv conv_option, int *err);

//ft_flag.c
void	width_flag(t_conv conv_option, char **str, int *err);
void	hash_flag(t_conv conv_option, char **str, int *err);
void	precision_flag(t_conv conv_option, char **str, int *err);
void	blank_or_plus_flag(t_conv conv_option, char **str, int *err);

//ft_base16.c
char	*base16(t_ull num, int *err);
char	*base16_cap(t_ull num, int *err);

#endif
