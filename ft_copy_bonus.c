/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:22:42 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/08 18:59:27 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	copy_plain_str(const char **format, char **temp)
{
	t_ull	len;

	len = get_plain_len(format);
	ft_memmove(*temp, *format - len, len);
	*temp += len;
	return (0);
}

int	copy_conv_str(const char **format, char **temp, va_list *app)
{
	t_conv	conv_op;
	int		err;

	(*format)++;
	ft_memset(&conv_op, 0, sizeof(t_conv));
	err = parse_format(format, &conv_op);
	if (err)
		return (err);
	if (conv_op.speci == 'c')
		return (conv_c(conv_op, app));
	else if (conv_op.speci == 's')
		return (copy_s(temp, app, conv_op));
	else if (conv_op.speci == 'd' || conv_op.speci == 'i')
		return (copy_di(temp, app, conv_op));
	else if (conv_op.speci == 'p')
		return (copy_p(temp, app, conv_op));
	else if (conv_op.speci == 'u')
		return (copy_u(temp, app, conv_op));
	else if (conv_op.speci == 'x' || conv_op.speci == 'X')
		return (copy_xs(temp, app, conv_op));
	else if (conv_op.speci == '%')
		return (copy_percent(temp, conv_op));
	return (0);
}

void	copy_char(char **dst, char c, t_ull len)
{
	t_ull	idx;

	idx = 0;
	if (*dst == 0)
		return ;
	while (idx < len)
	{
		**dst = c;
		(*dst)++;
		idx++;
	}
}

void	copy_str(char **dst, char *src, t_ull len)
{
	t_ull	idx;

	idx = 0;
	if (*dst == 0 || src == 0)
		return ;
	while (idx < len)
	{
		**dst = src[idx];
		(*dst)++;
		idx++;
	}
}

void	copy_num_base(char **dst, t_ull num, char *base)
{
	int			size;
	int			size_copy;

	size = get_itoa_len(num, base);
	size_copy = size--;
	while (size >= 0)
	{
		(*dst)[size] = base[num % ft_strlen(base)];
		num /= ft_strlen(base);
		size--;
	}
	*dst += size_copy;
}
