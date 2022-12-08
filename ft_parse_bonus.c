/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:00:19 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/08 19:00:21 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	parse_flag(const char **format, t_conv *conv_op)
{
	while (**format == '+' || **format == '-' || **format == '0' \
	|| **format == ' ' || **format == '#')
	{
		if (**format == '+')
		{
			conv_op->plus = 1;
			conv_op->blank = 0;
		}
		else if (**format == '-')
		{
			conv_op->minus = 1;
			conv_op->zero = 0;
		}
		else if (**format == '0' && !(conv_op->minus))
			conv_op->zero = 1;
		else if (**format == ' ' && !(conv_op->plus))
			conv_op->blank = 1;
		else if (**format == '#')
			conv_op->hash = 1;
		(*format)++;
	}
}

static void	parse_width_precision(const char **format, t_conv *conv_op)
{
	conv_op->width = (t_ull)ft_atoi(*format);
	while ('0' <= **format && **format <= '9')
		(*format)++;
	if (**format == '.')
	{
		conv_op->zero = 0;
		conv_op->point = 1;
		(*format)++;
		conv_op->preci = (t_ull)ft_atoi(*format);
		while ('0' <= **format && **format <= '9')
			(*format)++;
	}
}

static void	parse_specifier(const char **format, t_conv *conv_op)
{
	if (**format == 'c' || **format == 's' || **format == 'p' || \
	**format == 'd' || **format == 'i' || **format == 'u' || \
	**format == 'x' || **format == 'X' || **format == '%')
	{
		conv_op->speci = **format;
		(*format)++;
	}
}

int	parse_format(const char **format, t_conv *conv_op)
{
	parse_flag(format, conv_op);
	parse_width_precision(format, conv_op);
	parse_specifier(format, conv_op);
	if (conv_op->width > INT_MAX)
		return (ERR_WIDTH_OVER);
	if (conv_op->preci > INT_MAX)
		return (ERR_PRECISION_OVER);
	return (0);
}
