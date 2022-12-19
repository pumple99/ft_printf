/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:38:23 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 14:17:16 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	get_itoa_len(t_ull nbr, t_conv op)
{
	int		len;
	char	*base;

	base = BASE_D;
	if (op.speci == 'p' || op.speci == 'X' || op.speci == 'x')
		base = BASE_X;
	if (nbr == 0)
	{
		if (op.point && (op.speci == 'd' || op.speci == 'i' || \
		op.speci == 'u' || op.speci == 'X' || op.speci == 'x'))
			return (0);
		return (1);
	}
	len = 0;
	while (nbr > 0)
	{
		nbr /= ft_strlen(base);
		len++;
	}
	return (len);
}

t_ull	get_slen(int num, t_conv op)
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
	len += (t_ull)get_itoa_len((t_ull)new_num, op);
	return (len);
}

t_ull	get_ulen(int num, t_conv op)
{
	t_ull		len;
	long long	new_num;

	new_num = (long long)num;
	if (new_num < 0)
		new_num *= -1;
	len = (t_ull)get_itoa_len((t_ull)new_num, op);
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
	t_conv	op;

	(*format)++;
	ft_memset(&op, 0, sizeof(t_conv));
	*err = parse_format(format, &op);
	if (op.speci == 'c' || op.speci == '%' || op.speci == 'p')
		return (conv_cpp_len(op, app));
	else if (op.speci == 's')
		return (conv_s_len(op, app));
	else if (op.speci == 'd' || op.speci == 'i')
		return (conv_di_len(op, app));
	else if (op.speci == 'u')
		return (conv_u_len(op, app));
	else if (op.speci == 'X' || op.speci == 'x')
		return (conv_xs_len(op, app));
	return (0);
}
