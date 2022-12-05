/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:17:24 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 18:25:04 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	return_strlen(char *print_str)
{
	t_ull	len;

	len = ft_strlen(print_str);
	if (len > LLONG_MAX)
		len = 0;
	else if (len > INT_MAX)
		len = ERR_RETURN_OVER;
	return ((int)len);
}

static int	ft_print_str(char *print_str, int err)
{
	int	re;

	re = 0;
	if (err)
		re = err;
	else
	{
		re = return_strlen(print_str);
		if (re != ERR_RETURN_OVER)
			ft_putstr_fd(print_str, 1);
	}
	free(print_str);
	return (re);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*print_str;
	int			err;

	err = 0;
	print_str = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			err = join_plain_str(&format, &print_str);
		else
			err = join_conversion_str(&format, &print_str, &ap);
		if (err)
			break ;
	}
	va_end(ap);
	return (ft_print_str(print_str, err));
}
