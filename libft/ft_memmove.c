/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:24:07 by seunghoy          #+#    #+#             */
/*   Updated: 2022/12/05 17:38:22 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, t_ull len)
{
	unsigned long long	idx;

	idx = 0;
	if (dst == 0 && src == 0)
		return (dst);
	if (dst < src)
	{
		while (idx < len)
		{
			((unsigned char *)dst)[idx] = \
			((const unsigned char *)src)[idx];
			idx++;
		}
	}
	else
	{
		while (idx < len)
		{
			((unsigned char *)dst)[len - idx - 1] = \
			((const unsigned char *)src)[len - idx - 1];
			idx++;
		}
	}
	return (dst);
}
