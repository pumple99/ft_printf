/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:27:29 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/08 17:27:31 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	copy_c_percent(const char **format, char **temp, va_list *ap)
{
	char	c;

	c = '%';
	if (**format == 'c')
		c = (char)va_arg(*ap, int);
	copy_char(temp, c, 1);
	return (0);
}

int	copy_s(char **temp, va_list *ap)
{
	char	*s;

	s = (char *)va_arg(*ap, char *);
	if (s == 0)
		copy_str(temp, "(null)", 6);
	else
		copy_str(temp, s, ft_strlen(s));
	return (0);
}

int	copy_d_i(char **temp, va_list *ap)
{
	long long	d;

	d = (long long)va_arg(*ap, int);
	if (d < 0)
	{
		copy_char(temp, '-', 1);
		d *= -1;
	}
	copy_num_base(temp, (t_ull)d, "0123456789");
	return (0);
}

int	copy_xs(const char **format, char **temp, va_list *ap)
{
	t_ull	u;
	char	*base;

	base = "0123456789abcdef";
	u = (t_ull)va_arg(*ap, unsigned int);
	if (**format == 'u')
		base = "0123456789";
	else if (**format == 'X')
		base = "0123456789ABCDEF";
	copy_num_base(temp, u, base);
	return (0);
}

int	copy_p(char **temp, va_list *ap)
{
	t_ull	u;

	u = (t_ull)va_arg(*ap, t_ull);
	copy_str(temp, "0x", 2);
	copy_num_base(temp, u, "0123456789abcdef");
	return (0);
}
