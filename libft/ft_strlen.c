/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:39:54 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 18:25:41 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull	ft_strlen(const char *s)
{
	t_ull	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
