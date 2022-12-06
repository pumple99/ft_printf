/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:46:31 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 13:46:34 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*converge_format(t_conv conv_option, va_list *ap, int *err)
{
	if (conv_option.specifier == 'c')
		return (conv_c(conv_option, ap, err));
	else if (conv_option.specifier == 's')
		return (conv_s(conv_option, ap, err));
	else if (conv_option.specifier == 'p')
		return (conv_p(conv_option, ap, err));
	else if (conv_option.specifier == 'd')
		return (conv_d(conv_option, ap, err));
	else if (conv_option.specifier == 'i')
		return (conv_i(conv_option, ap, err));
	else if (conv_option.specifier == 'u')
		return (conv_u(conv_option, ap, err));
	else if (conv_option.specifier == 'x')
		return (conv_x(conv_option, ap, err));
	else if (conv_option.specifier == 'X')
		return (conv_x_capital(conv_option, ap, err));
	else if (conv_option.specifier == '%')
		return (conv_percent(conv_option, err));
	else
		return (0);
}

char	*conv_c(t_conv conv_option, va_list *ap, int *err)
{
	char	*temp;
	char	c;

	temp = 0;
	conv_option.zero = 0;
	c = (char)va_arg(*ap, int);
	if (malloc_set(&temp, c, 1, err))
		return (0);
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_s(t_conv conv_option, va_list *ap, int *err)
{
	char	*temp;
	char	*arg;

	arg = (char *)va_arg(*ap, char *);
	if (arg == 0)
		arg = "(null)";
	conv_option.zero = 0;
	if (conv_option.point)
		temp = ft_substr(arg, 0, conv_option.precision);
	else
		temp = ft_substr(arg, 0, ft_strlen(arg));
	if (temp == 0)
	{
		*err = ERR_MALLOC;
		return (0);
	}
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_i(t_conv conv_option, va_list *ap, int *err)
{
	int		num;
	char	*temp;

	num = (int)va_arg(*ap, int);
	if (num < 0 && conv_option.precision)
		conv_option.precision++;
	if (num == 0 && conv_option.point)
		temp = null_join("", "");
	else
		temp = ft_itoa(num);
	if (temp == 0)
		*err = ERR_MALLOC;
	precision_flag(conv_option, &temp, err);
	if (num >= 0)
		blank_or_plus_flag(conv_option, &temp, err);
	width_zero_flag(conv_option, &temp, err);
	width_blank_flag(conv_option, &temp, err);
	return (temp);
}

char	*conv_d(t_conv conv_option, va_list *ap, int *err)
{
	return (conv_i(conv_option, ap, err));
}
