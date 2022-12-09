/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_conv_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:27:29 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/08 18:59:37 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	copy_p(char **temp, va_list *app, t_conv conv_op)
{
	t_ull	p;
	t_ull	temp_len;

	p = (t_ull)va_arg(*app, t_ull);
	temp_len = (t_ull)get_itoa_len(p, BASE_X) + 2;
	if (!conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	copy_str(temp, "0x", 2);
	copy_num_base(temp, p, BASE_X);
	if (conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, ' ', conv_op.width - temp_len);
	return (0);
}

int	copy_u(char **temp, va_list *app, t_conv conv_op)
{
	t_ui	u;
	t_ull	temp_len;
	char	c;

	c = ' ';
	if (conv_op.zero)
		c = '0';
	u = (t_ui)va_arg(*app, t_ui);
	temp_len = (t_ull)get_itoa_len((t_ull)u, BASE_D);
	if (conv_op.point && conv_op.preci > temp_len)
		temp_len = conv_op.preci;
	if (!conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, c, conv_op.width - temp_len);
	copy_num_base(temp, (t_ull)u, BASE_D);
	if (conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, c, conv_op.width - temp_len);
	return (0);
}

int	copy_xs(char **temp, va_list *app, t_conv conv_op)
{
	t_ui	xs;
	t_ull	temp_len;
	char	c;

	c = ' ';
	if (conv_op.zero)
		c = '0';
	xs = (t_ui)va_arg(*app, t_ui);
	temp_len = (t_ull)get_itoa_len((t_ull)xs, BASE_X);
	if (conv_op.point && conv_op.preci > temp_len)
		temp_len = conv_op.preci;
	if (!conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, c, conv_op.width - temp_len);
	copy_num_base(temp, (t_ull)u, BASE_D);
	if (conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, c, conv_op.width - temp_len);
	return (0);
}

int	copy_percent(char **temp, t_conv conv_op)
{
	t_ull	temp_len;
	char	c;

	c = ' ';
	if (conv_op.zero)
		c = '0';
	temp_len = 1;
	if (!conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, c, conv_op.width - temp_len);
	copy_char(temp, '%', temp_len);
	if (conv_op.minus && conv_op.width > temp_len)
		copy_char(temp, c, conv_op.width - temp_len);
	return (0);
}
