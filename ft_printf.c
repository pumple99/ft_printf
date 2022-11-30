/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:17:24 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/30 15:52:04 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	return_strlen(t_ull print_len)
{
	int	len;

	if (print_len > LLONG_MAX)
		len = 0;
	else if (print_len > INT_MAX)
		len = ERR_RETURN_OVER;
	else
		len = (int)print_len;
	return (len);
}

static int	ft_print_str(char *print_str, t_ull print_len, int err)
{
	int	re;

	re = 0;
	if (err)
		re = err;
	else
	{
		re = return_strlen(print_len);
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
	t_ull		print_len;

	err = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		else
			parse(&format);
		format++;
		if (err)
			break ;
	}
	return (ft_print_str(print_str, err));
}
