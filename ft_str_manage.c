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

char	*ft_new_str(t_ull *size, int *err)
{
	char	*str;

	str = (char *)malloc(*size);
	if (str == 0)
		*err = ERR_MALLOC;
	return (str);
}

char	*ft_str_double(t_ull *size, int *err, char *old_str)
{
	char	*new_str;
	t_ull	new_size;

	if (*size * 2 > *size)
		new_size = *size * 2;
	else
	{
		*err = ERR_MALLOC;
		free(old_str);
		return (0);
	}
	return (new_str);
}
