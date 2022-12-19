/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:00:07 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/19 14:05:59 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_index(char c)
{
	if ('0' <= c && c <= '9')
		return ((int)(c - 48));
	return (-1);
}

static t_ull	make_int(const char *str)
{
	int		index;
	t_ull	num;

	index = 0;
	num = 0;
	while (return_index(str[index]) != -1)
	{
		if (num > LLONG_MAX / 10)
			return (0);
		num *= 10;
		if (num == LLONG_MAX - 7 && return_index(str[index]) > 7)
			return (0);
		num += return_index(str[index]);
		index++;
	}
	return (num);
}

t_ull	ft_atoi(const char *str)
{
	return (make_int(str));
}
