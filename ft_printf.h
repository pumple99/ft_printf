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

//ft_printf.c
int		ft_printf(const char *format, ...);

//ft_str_manage.c
char	*ft_new_str(unsigned long long *size, int *err);
char	*ft_str_double(unsigned long long *size, int *err, char *old_str);

#endif
