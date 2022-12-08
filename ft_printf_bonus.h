/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:16:58 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/08 19:20:21 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define ERR_MALLOC -1
# define ERR_RETURN_OVER -2
# define ERR_WIDTH_OVER -3
# define ERR_PRECISION_OVER -4
# define ERR_WRITE -1

typedef unsigned long long	t_ull;
typedef unsigned int	t_ui;
typedef struct s_conv
{
	int		plus;
	int		minus;
	int		zero;
	int		blank;
	int		hash;
	int		point;
	t_ull	width;
	t_ull	preci;
	char	speci;
}	t_conv;

//ft_printf_bonus.c
int		ft_printf(const char *format, ...);

//ft_len_bonus.c
t_ull	get_plain_len(const char **format);
t_ull	get_conv_len(const char **format, va_list *app, int *err);
int		get_itoa_len(t_ull nbr, char *base);
t_ull	get_slen(int num, char *base);

//ft_len_conv_bonus.c
t_ull	conv_cpp_len(t_conv conv_op, va_list *app);
t_ull	conv_s_len(t_conv conv_op, va_list *app);
t_ull	conv_di_len(t_conv conv_op, va_list *app);
t_ull	conv_u_len(t_conv conv_op, va_list *app);
t_ull	conv_xs_len(t_conv conv_op, va_list *app);

//ft_copy_bonus.c
int		copy_plain_str(const char **format, char **temp);
int		copy_conv_str(const char **format, char **temp, va_list *ap);
void	copy_char(char **dst, char c, t_ull len);
void	copy_str(char **dst, char *src, t_ull len);
void	copy_num_base(char **dst, t_ull num, char *base);

//ft_copy_conv_bonus.c
int		copy_c_percent(const char **format, char **temp, va_list *ap);
int		copy_s(char **temp, va_list *ap);
int		copy_d_i(char **temp, va_list *ap);
int		copy_xs(const char **format, char **temp, va_list *ap);
int		copy_p(char **temp, va_list *ap);

//ft_parse_bonus.c
int		parse_format(const char **format, t_conv *conv_op);

#endif
