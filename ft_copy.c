/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:22:42 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 14:14:51 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	copy_plain_str(const char **format, char **temp)
{
	t_ull	len;

	len = get_plain_len(format);
	ft_memmove(*temp, *format - len, len);
	*temp += len;
	return (0);
}

int	copy_conv_str(const char **format, char **temp, va_list *ap)
{
	int	err;

	err = 0;
	(*format)++;
	if (**format == 'c' || **format == '%')
		err = copy_c_percent(format, temp, ap);
	else if (**format == 'd' || **format == 'i')
		err = copy_d_i(temp, ap);
	else if (**format == 'x' || **format == 'X' || **format == 'u')
		err = copy_xs(format, temp, ap);
	else if (**format == 'p')
		err = copy_p(temp, ap);
	else if (**format == 's')
		err = copy_s(temp, ap);
	else
		return (0);
	(*format)++;
	return (err);
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
	int	size;
	int	size_copy;

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
