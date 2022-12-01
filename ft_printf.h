/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:18:38 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/30 15:52:13 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

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
}	t_conv;

//ft_printf.c
int		ft_printf(const char *format, ...);

//ft_str_manage.c
int		join_plain_str(const char **format, char **print_str);
int		join_conversion_str(const char **format, char **print_str, va_list *ap);

#endif
