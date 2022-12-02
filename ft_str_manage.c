/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:24:40 by seunghoy          #+#    #+#             */
/*   Updated: 2022/11/30 15:52:29 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//need change, not complete, join should join null and str
int	join_plain_str(const char **format, char **print_str)
{
	t_ull	plain_len;
	char	*plain_str;
	char	*temp;
	
	plain_len = 0;
	while (**format && **format != '%')
		plain_len++;
	*format = *format + plain_len;
	plain_str = sub();
	temp = *print_str;
	*print_str = join(temp, plain_str);
	free(temp);
	free(plain_str);
	if (*print_str == 0 || plain_str == 0)
		return (ERR_MALLOC);
	return (0);
}

//need change, converge_format is not complete
int	join_conversion_str(const char **format, char **print_str, va_list *ap)
{
	t_conv	conv_option;
	char	*conv_str;
	char	*temp;
	int		err;
	
	err = 0;
	(*format)++;
	//initialize conv_option, set mem
	err = parse_format(format, &conv_option);
	conv_str = converge_format(conv_option, ap);
	temp = *print_str;
	*print_str = join(temp, conv_str);
	free(temp);
	free(conv_str);
	if (conv_str == 0 || temp == 0)
		err = ERR_MALLOC;
	return (err);
}
