/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:24:40 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 18:17:33 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*null_join(char *str1, char *str2)
{
	if (str1 == 0)
		str1 = "";
	if (str2 == 0)
		str2 = "";
	return (ft_strjoin(str1, str2));
}

int	join_plain_str(const char **format, char **print_str)
{
	t_ull	plain_len;
	char	*plain_str;
	char	*temp;

	plain_len = 0;
	while ((*format)[plain_len] && (*format)[plain_len] != '%')
		plain_len++;
	plain_str = ft_substr(*format, 0, plain_len);
	*format = *format + plain_len;
	temp = *print_str;
	*print_str = null_join(temp, plain_str);
	free(temp);
	free(plain_str);
	if (*print_str == 0 || plain_str == 0)
		return (ERR_MALLOC);
	return (0);
}

int	join_conversion_str(const char **format, char **print_str, va_list *ap)
{
	t_conv	conv_option;
	char	*conv_str;
	char	*temp;
	int		err;

	err = 0;
	(*format)++;
	ft_memset(&conv_option, 0, sizeof(t_conv));
	err = parse_format(format, &conv_option);
	conv_str = converge_format(conv_option, ap, &err);
	temp = *print_str;
	*print_str = null_join(temp, conv_str);
	free(temp);
	free(conv_str);
	if (*print_str == 0 || conv_str == 0)
		err = ERR_MALLOC;
	return (err);
}

int	malloc_set(char **str, char c, t_ull size, int *err)
{
	if (size == ULLONG_MAX)
	{
		*err = ERR_MALLOC;
		return (ERR_MALLOC);
	}
	*str = (char *)malloc(size + 1);
	if (*str == 0)
	{
		*err = ERR_MALLOC;
		return (ERR_MALLOC);
	}
	ft_memset(*str, c, size);
	(*str)[size] = 0;
	return (0);
}
