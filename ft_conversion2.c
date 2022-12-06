/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:46:39 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 19:31:35 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_p(t_conv conv_option, va_list *ap, int *err)
{
	t_ull	num;
	char	*temp;

	conv_option.zero = 0;
	num = (t_ull)va_arg(*ap, t_ull);
	temp = base16(num, err);
	hash_flag(conv_option, &temp, err);
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_u(t_conv conv_option, va_list *ap, int *err)
{
	char			*temp;
	unsigned int	num;

	num = (unsigned int)va_arg(*ap, unsigned int);
	if (num == 0 && conv_option.point)
		temp = null_join("", "");
	else
		temp = ft_itoa((long long)num);
	if (temp == 0)
		*err = ERR_MALLOC;
	precision_flag(conv_option, &temp, err);
	width_zero_flag(conv_option, &temp, err);
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_x(t_conv conv_option, va_list *ap, int *err)
{
	char	*temp;
	t_ull	num;
	int		check;

	check = 0;
	num = (t_ull)va_arg(*ap, unsigned int);
	if (num == 0 && conv_option.point)
		temp = null_join("", "");
	else
		temp = base16(num, err);
	if (temp == 0)
		*err = ERR_MALLOC;
	precision_flag(conv_option, &temp, err);
	if (conv_option.hash && num)
	{
		if (conv_option.width > 1)
		{
			conv_option.width -= 2;
			check = 1;
		}
		width_zero_flag(conv_option, &temp, err);
		hash_flag(conv_option, &temp, err);
		if (check)
			conv_option.width += 2;
	}
	else
		width_zero_flag(conv_option, &temp, err);
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_x_capital(t_conv conv_option, va_list *ap, int *err)
{
	char	*temp;
	t_ull	num;
	int		check;

	check = 0;
	num = (t_ull)va_arg(*ap, unsigned int);
	if (num == 0 && conv_option.point)
		temp = null_join("", "");
	else
		temp = base16_cap(num, err);
	if (temp == 0)
		*err = ERR_MALLOC;
	precision_flag(conv_option, &temp, err);
	if (conv_option.hash && num)
	{
		if (conv_option.width > 1)
		{
			conv_option.width -= 2;
			check = 1;
		}
		width_zero_flag(conv_option, &temp, err);
		hash_flag(conv_option, &temp, err);
		if (check)
			conv_option.width += 2;
	}
	else
		width_zero_flag(conv_option, &temp, err);
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_percent(t_conv conv_option, int *err)
{
	char	*temp;

	conv_option.point = 0;
	temp = 0;
	if (malloc_set(&temp, '%', 1, err))
		return (0);
	width_zero_flag(conv_option, &temp, err);
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}
