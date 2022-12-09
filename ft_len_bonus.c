/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:38:23 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/08 18:59:46 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

t_ull	get_ulen(int num, char *base)
{
	t_ull		len;
	long long	new_num;

	len = 0;
	new_num = (long long)num;
	if (new_num < 0)
		new_num *= -1;
	len += (t_ull)get_itoa_len((t_ull)new_num, base);
	return (len);
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

t_ull	get_conv_len(const char **format, va_list *app, int *err)
{
	t_conv	conv_op;

	(*format)++;
	ft_memset(&conv_op, 0, sizeof(t_conv));
	*err = parse_format(format, &conv_op);
	if (conv_op.speci == 'c' || conv_op.speci == '%' || conv_op.speci == 'p')
		return (conv_cpp_len(conv_op, app));
	else if (conv_op.speci == 's')
		return (conv_s_len(conv_op, app));
	else if (**format == 'd' || **format == 'i')
		return (conv_di_len(conv_op, app));
	else if (**format == 'u')
		return (conv_u_len(conv_op, app));
	else if (**format == 'X' || **format == 'x')
		return (conv_xs_len(conv_op, app));
	return (0);
}
