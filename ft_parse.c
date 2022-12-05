/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:46:54 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 13:46:56 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flag(const char **format, t_conv *conv_option)
{
	while (**format == '+' || **format == '-' || **format == '0' \
	|| **format == ' ' || **format == '#')
	{
		if (**format == '+')
			conv_option->plus = 1;
		else if (**format == '-')
			conv_option->minus = 1;
		else if (**format == '0')
			conv_option->zero = 1;
		else if (**format == ' ')
			conv_option->blank = 1;
		else if (**format == '#')
			conv_option->hash = 1;
		(*format)++;
	}
}

static void	parse_width_precision(const char **format, t_conv *conv_option)
{
	conv_option->width = (t_ull)ft_atoi(*format);
	while ('0' <= **format && **format <= '9')
		(*format)++;
	if (**format == '.')
	{
		conv_option->point = 1;
		(*format)++;
		conv_option->precision = (t_ull)ft_atoi(*format);
		while ('0' <= **format && **format <= '9')
			(*format)++;
	}
}

static void	parse_specifier(const char **format, t_conv *conv_option)
{
	if (**format == 'c' || **format == 's' || **format == 'p' || \
	**format == 'd' || **format == 'i' || **format == 'u' || \
	**format == 'x' || **format == 'X' || **format == '%')
	{
		conv_option->specifier = **format;
		(*format)++;
	}
}

int	parse_format(const char **format, t_conv *conv_option)
{
	parse_flag(format, conv_option);
	parse_width_precision(format, conv_option);
	parse_specifier(format, conv_option);
	if (conv_option->width > INT_MAX)
		return (ERR_WIDTH_OVER);
	if (conv_option->precision == INT_MAX)
		return (ERR_PRECISION);
	return (0);
}
