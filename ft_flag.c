/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:46:46 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 19:30:51 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_flag(t_conv conv_option, char **str, int *err)
{
	char	c;
	char	t;
	char	*width;
	char	*temp;

	c = ' ';
	width = 0;
	temp = *str;
	if (ft_strlen(*str) < conv_option.width)
	{
		if (!conv_option.minus && conv_option.zero && !conv_option.point)
			c = '0';
		if (malloc_set(&width, c, conv_option.width - ft_strlen(*str), err))
			return ;
		if (conv_option.minus)
			*str = null_join(temp, width);
		else
		{
			if ((temp[0] == '-' || temp[0] == '+' || temp[0] == ' ') && width[0] == '0')
			{
				t = temp[0];
				temp[0] = width[0];
				width[0] = t;
			}
			*str = null_join(width, temp);
		}
		free(temp);
		free(width);
		if (*str == 0)
			*err = ERR_MALLOC;
	}
}

void	hash_flag(t_conv conv_option, char **str, int *err)
{
	char	*temp;

	if (conv_option.specifier == 'x' || \
			conv_option.specifier == 'p' || conv_option.specifier == 'X')
	{
		temp = *str;
		if (conv_option.specifier == 'x' || conv_option.specifier == 'p')
			*str = null_join("0x", temp);
		else if (conv_option.specifier == 'X')
			*str = null_join("0X", temp);
		free(temp);
		if (*str == 0)
			*err = ERR_MALLOC;
	}
}

void	precision_flag(t_conv conv_option, char **str, int *err)
{
	char	*temp;
	char	*precision;

	if (conv_option.point)
	{
		precision = 0;
		temp = *str;
		if (ft_strlen(*str) < conv_option.precision)
		{
			if (malloc_set(&precision, '0', conv_option.precision \
			- ft_strlen(*str), err))
				return ;
			if (temp[0] == '-')
			{
				precision[0] = '-';
				temp[0] = '0';
			}
			*str = null_join(precision, temp);
			free(temp);
			free(precision);
			if (*str == 0)
				*err = ERR_MALLOC;
		}
	}
}

void	blank_or_plus_flag(t_conv conv_option, char **str, int *err)
{
	char	c;
	char	*bp;
	char	*temp;

	if (conv_option.blank || conv_option.plus)
	{
		bp = 0;
		temp = *str;
		c = '+';
		if (!conv_option.plus && conv_option.blank)
			c = ' ';
		if (malloc_set(&bp, c, 1, err))
			return ;
		*str = null_join(bp, temp);
		free(temp);
		free(bp);
		if (*str == 0)
			*err = ERR_MALLOC;
	}
}
