/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:38:23 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 14:14:34 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	get_itoa_len(t_ull nbr, char *base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= ft_strlen(base);
		len++;
	}
	return (len);
}

t_ull	get_slen(int num, char *base)
{
	t_ull		len;
	long long	new_num;

	len = 0;
	new_num = (long long)num;
	if (new_num < 0)
	{
		len += 1;
		new_num *= -1;
	}
	len += (t_ull)get_itoa_len((t_ull)new_num, base);
	return (len);
}

static t_ull	len_s(char *s)
{
	if (s == 0)
		return (6);
	return (ft_strlen(s));
}

t_ull	get_plain_len(const char **format)
{
	t_ull	pl;

	pl = 0;
	while (**format && **format != '%')
	{
		pl++;
		(*format)++;
	}
	return (pl);
}

t_ull	get_conv_len(const char **format, va_list *app)
{
	t_ull	cl;

	cl = 0;
	(*format)++;
	if (**format == 'c')
		va_arg(*app, int);
	if (**format == 'c' || **format == '%')
		cl = 1;
	else if (**format == 's')
		cl = len_s((char *)va_arg(*app, char *));
	else if (**format == 'd' || **format == 'i')
		cl = get_slen((int)va_arg(*app, int), "0123456789");
	else if (**format == 'u')
		cl = (t_ull)get_itoa_len((unsigned int)va_arg(*app, \
		unsigned int), "0123456789");
	else if (**format == 'X' || **format == 'x')
		cl = (t_ull)get_itoa_len((unsigned int)va_arg(*app, \
		unsigned int), "0123456789abcdef");
	else if (**format == 'p')
		cl = (t_ull)get_itoa_len((t_ull)va_arg(*app, t_ull), \
				"0123456789abcdef") + 2;
	else
		return (0);
	(*format)++;
	return (cl);
}
