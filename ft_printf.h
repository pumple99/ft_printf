/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:42:59 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 14:07:15 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_MALLOC -1
# define ERR_WRITE -1
# define ERR_RETURN_OVER -2

typedef unsigned long long	t_ull;

//ft_printf.c
int		ft_printf(const char *format, ...);

//ft_len.c
t_ull	get_plain_len(const char **format);
t_ull	get_conv_len(const char **format, va_list *app);
int		get_itoa_len(t_ull nbr, char *base);
t_ull	get_slen(int num, char *base);

//ft_copy.c
int		copy_plain_str(const char **format, char **temp);
int		copy_conv_str(const char **format, char **temp, va_list *ap);
void	copy_char(char **dst, char c, t_ull len);
void	copy_str(char **dst, char *src, t_ull len);
void	copy_num_base(char **dst, t_ull num, char *base);

//ft_copy_conv.c
int		copy_c_percent(const char **format, char **temp, va_list *ap);
int		copy_s(char **temp, va_list *ap);
int		copy_d_i(char **temp, va_list *ap);
int		copy_xs(const char **format, char **temp, va_list *ap);
int		copy_p(char **temp, va_list *ap);

#endif
